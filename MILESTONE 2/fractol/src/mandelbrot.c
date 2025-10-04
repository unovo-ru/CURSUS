/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 06:36:11 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/04 06:44:13 by unovo-ru         ###   ########.fr       */
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
	return (MAX_ITERATIONS);
}

