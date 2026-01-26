/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 02:33:07 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/08 20:01:52 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	init_fractol(t_fractol *fractol)
{
	if (!fractol)
		return ;
	fractol->mlx = NULL;
	fractol->img = NULL;
	fractol->width = WIDTH;
	fractol->heigth = HEIGHT;
	fractol->zoom = 1.0;
	fractol->max_real = 1.0;
	fractol->min_real = -2.5;
	fractol->max_imag = 1.25;
	fractol->min_imag = -1.25;
	fractol->color_draw = 0x00FFFFFF;
	fractol->real = 0.0;
	fractol->imaginary = 0.0;
	fractol->max_iter = 100;
	fractol->julia_real = 0.0;
	fractol->julia_imag = 0.0;
	fractol->type = 0;
}

void	init_calc(t_calc *calc)
{
	calc->img = 0.0;
	calc->real = 0.0;
}

void	init_window(t_fractol *fractol)
{
	fractol->mlx = mlx_init(fractol->width, fractol->heigth, "Fractol", true);
	if (!fractol->mlx)
	{
		ft_putstr_fd(ERROR_MLX, 2);
		ft_putstr_fd((char *)mlx_strerror(mlx_errno), 2);
		exit(EXIT_FAILURE);
	}
	fractol->img = mlx_new_image(fractol->mlx, fractol->width, fractol->heigth);
	if (!fractol->img)
	{
		ft_putstr_fd(ERROR_IMG, 2);
		free_exit(fractol);
		return ;
	}
	if (mlx_image_to_window(fractol->mlx, fractol->img, 0, 0) == -1)
	{
		ft_putstr_fd(ERROR_IMG, 2);
		mlx_terminate(fractol->mlx);
		exit(EXIT_FAILURE);
	}
	mlx_scroll_hook(fractol->mlx, handle_scroll, fractol);
	mlx_loop_hook(fractol->mlx, handle_keys, fractol);
}

void	render_fractals(t_fractol *fractal)
{
	if (fractal->type == MANDELBROT)
		render_mandelbrot(fractal);
	else if (fractal->type == JULIA)
		render_julia(fractal);
	else
		return ;
}

void	finish_exit(t_fractol *fractal)
{
	mlx_delete_image(fractal->mlx, fractal->img);
	mlx_terminate(fractal->mlx);
	exit(EXIT_FAILURE);
}
