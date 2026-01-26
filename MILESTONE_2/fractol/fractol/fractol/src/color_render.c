/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:44:05 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/09 17:28:44 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

uint32_t	create_rgba(int r, int g, int b, int a)
{
	return ((uint32_t)r << 24 | (uint32_t)g << 16
		| (uint32_t)b << 8 | (uint32_t)a);
}

int	lerp(int start, int end, double t)
{
	return ((int)(start + t * (end - start)));
}

uint32_t	color_blue_purple_smooth(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (BLACK);
	t = (double)iter / (double)max_iter;
	t = (sin(t * 3.14159) + 1.0) / 2.0;
	r = (int)(9 * (1 - t) * t * t * t * 180 + 75);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 150);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255 + 100);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return (create_rgba(r, g, b, 255));
}

uint32_t	color_ultraviolet(int iter, int max_iter)
{
	double	t;
	double	wave;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0x0A0A2EFF);
	t = (double)iter / (double)max_iter;
	wave = sin(t * 6.28318);
	r = (int)(128 + wave * 70);
	g = (int)(64 + wave * 40);
	b = (int)(200 + wave * 55);
	return (create_rgba(r, g, b, 255));
}
