/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:02:13 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/08 14:23:28 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pan_view(t_fractol *f, double dx, double dy)
{
	double	w;
	double	h;

	w = f->max_real - f->min_real;
	h = f->max_imag - f->min_imag;
	f->min_real += dx * w;
	f->max_real += dx * w;
	f->min_imag += dy * h;
	f->max_imag += dy * h;
}

int	julia(t_fractol *fractal, t_calc c)
{
	int		i;
	double	tmp;
	t_calc	aux;

	aux.real = fractal->julia_real;
	aux.img = fractal->julia_imag;
	while (c.real * c.real + c.img * c.img <= 4.0 && i < fractal->max_iter)
	{
		tmp = c.real * c.real - c.img * c.img + aux.real;
		c.img = 2 * c.real * c.img + aux.img;
		c.real = tmp;
		i++;
	}
	return (i);
}

void	render_julia(t_fractol *fractal)
{
	t_calc		c;
	uint32_t	color;
	int			x;
	int			y;
	int			iter;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			c = pixel_to_complex(x, y, fractal);
			iter = julia(fractal, c);
			if (iter == fractal->max_iter)
				color = BLACK;
			else
				color = WHITE;
			mlx_put_pixel(fractal->img, x, y, color);
			y++;
		}
		x++;
	}
}
