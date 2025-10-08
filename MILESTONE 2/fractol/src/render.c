/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 06:43:51 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/08 13:22:02 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_calc	pixel_to_complex(int x, int y, t_fractol *fractol)
{
	t_calc	c;

	c.real = fractol->min_real + (double)x
		* (fractol->max_real - fractol->min_real) / fractol->width;
	c.img = fractol->min_imag + (double)y
		* (fractol->max_imag - fractol->min_imag) / fractol->heigth;
	return (c);
}

void	render_mandelbrot(t_fractol *fractol)
{
	t_calc		c;
	int			x;
	int			y;
	uint32_t	color;
	int			i;

	x = 0;
	while (x < fractol->width)
	{
		y = 0;
		while (y < fractol->heigth)
		{
			c = pixel_to_complex(x, y, fractol);
			i = mandelbrot(c);
			// printf("esto es i %d", i);
			// printf("esto es max iter %d", fractol->max_iter);
			if (i == fractol->max_iter)
				color = color_electric_edge(i, fractol->max_iter);
			else
				color = color_blue_purple_smooth(i, fractol->max_iter);
			mlx_put_pixel(fractol->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}
