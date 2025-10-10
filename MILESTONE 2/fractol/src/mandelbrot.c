/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 06:36:11 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/10 13:19:27 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mandelbrot(t_calc c)
{
	int		i;
	double	aux;
	t_calc	cons;

	cons.real = 0.0;
	cons.img = 0.0;
	i = 0;
	while (i < MAX_ITERATIONS)
	{
		if (cons.real * cons.real + cons.img > ESCAPE_RADIUS)
			return (i);
		aux = cons.real * cons.real - cons.img * cons.img + c.real;
		cons.img = 2 * cons.real * cons.img + c.img;
		cons.real = aux;
		i++;
	}
	return (i);
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
			if (i == fractol->max_iter)
				color = color_blue_purple_smooth(i, fractol->max_iter);
			else
				color = color_blue_purple_smooth(i, fractol->max_iter);
			mlx_put_pixel(fractol->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_image_to_window(fractol->mlx, fractol->img, 0, 0);
}
