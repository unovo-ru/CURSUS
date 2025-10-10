/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_julia.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 14:02:13 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/10 13:19:02 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_fractol *fractal, t_calc c)
{
	int		i;
	double	tmp;
	t_calc	cc;

	i = 0;
	cc.real = c.real;
	cc.img = c.img;
	while (cc.real * cc.real + cc.img * cc.img <= 4.0 && i < fractal->max_iter)
	{
		tmp = cc.real * cc.real - cc.img * cc.img + fractal->julia_real;
		cc.img = 2 * cc.real * cc.img + fractal->julia_imag;
		cc.real = tmp;
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
				color = color_blue_purple_smooth(iter, fractal->max_iter);
			else
				color = color_blue_purple_smooth(iter, fractal->max_iter);
			mlx_put_pixel(fractal->img, x, y, color);
			y++;
		}
		x++;
	}
}
