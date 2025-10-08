/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 13:22:35 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/08 13:52:16 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_fractal(t_fractol *fractal, double mx, double my, double factor)
{
	double	cx;
	double	cy;
	double	new_w;
	double	new_h;

	cx = fractal->min_real + (mx / (double)WIDTH)
		* (fractal->max_real - fractal->min_real);
	cy = fractal->min_imag + (my / (double)HEIGHT)
		* (fractal->max_imag - fractal->min_imag);
	new_w = (fractal->max_real - fractal->min_real) * factor;
	new_h = (fractal->max_imag - fractal->min_imag) * factor;
	fractal->min_real = cy - (mx / (double)WIDTH) * new_w;
	fractal->max_real = fractal->min_real + new_w;
	fractal->min_imag = cy - (my / (double)HEIGHT) * new_h;
	fractal->max_imag = fractal->min_imag + new_h;
}

void	handle_scroll(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;
	int32_t		mouse_x;
	int32_t		mouse_y;

	fractol = (t_fractol *)param;
	(void)xdelta;
	mlx_get_mouse_pos(fractol->mlx, &mouse_x, &mouse_y);
	if (ydelta > 0)
		zoom_fractal(fractol, ZOOM_FACTOR, mouse_x, mouse_y);
	else if (ydelta < 0)
		zoom_fractal(fractol, 1.0 / ZOOM_FACTOR, mouse_x, mouse_y);
	render_mandelbrot(fractol);
}

static int	horizontal_move(t_fractol *f)
{
	int	updated;

	updated = 0;
	if (mlx_is_key_down(f->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(f->mlx, MLX_KEY_A))
	{
		pan_view(f, 0.05, 0.0);
		updated = 1;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_RIGHT)
		|| mlx_is_key_down(f->mlx, MLX_KEY_D))
	{
		pan_view(f, 0.05, 0.0);
		updated = 1;
	}
	return (updated);
}

static int	vertical_move(t_fractol *f)
{
	int	updated;

	updated = 0;
	if (mlx_is_key_down(f->mlx, MLX_KEY_UP)
		|| mlx_is_key_down(f->mlx, MLX_KEY_W))
	{
		pan_view(f, 0.05, 0.0);
		updated = 1;
	}
	if (mlx_is_key_down(f->mlx, MLX_KEY_DOWN)
		|| mlx_is_key_down(f->mlx, MLX_KEY_S))
	{
		pan_view(f, 0.05, 0.0);
		updated = 1;
	}
	return (updated);
}

void	handle_keys(void *param)
{
	t_fractol	*f;
	int			updated;

	f = (t_fractol *)param;
	if (!f || !f->mlx)
		return ;
	if (mlx_is_key_down(f->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(f->mlx);
	updated = 0;
	updated += horizontal_move(f);
	updated += vertical_move(f);
	if (updated)
		render_fractals(f);
}
