/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 06:43:51 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/10 13:19:43 by unovo-ru         ###   ########.fr       */
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
