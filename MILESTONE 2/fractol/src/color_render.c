/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:44:05 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/08 13:15:48 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_render.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:44:05 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/08 13:15:00 by unovo-ru         ###   ########.fr       */
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

uint32_t	color_blue_purple(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (BLACK);
	t = (double)iter / (double)max_iter;
	if (t < 0.25)
	{
		r = 0;
		g = 0;
		b = lerp(50, 255, t / 0.25);
	}
	else if (t < 0.5)
	{
		r = 0;
		g = lerp(0, 200, (t - 0.25) / 0.25);
		b = 255;
	}
	else if (t < 0.75)
	{
		r = lerp(0, 150, (t - 0.5) / 0.25);
		g = lerp(200, 100, (t - 0.5) / 0.25);
		b = 255;
	}
	else
	{
		r = lerp(150, 200, (t - 0.75) / 0.25);
		g = lerp(100, 50, (t - 0.75) / 0.25);
		b = lerp(255, 200, (t - 0.75) / 0.25);
	}
	return (create_rgba(r, g, b, 255));
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


// uint32_t	color_blue_purple_smooth(int iter, int max_iter)
// {
//     double	t;
//     double	edge_factor;
//     int		r;
//     int		g;
//     int		b;

//     if (iter == max_iter)
//         return (0x0A0A2EFF);  // Azul muy oscuro en lugar de negro puro
    
//     // Normalizar iteraciones
//     t = (double)iter / (double)max_iter;
    
//     // Factor para detectar bordes (alto contraste en iteraciones bajas)
//     edge_factor = 1.0 - t;
    
//     // Si está cerca del borde (pocas iteraciones = escapa rápido)
//     if (t < 0.15)
//     {
//         // AZUL ELÉCTRICO INTENSO en los bordes
//         r = (int)(t * 200);              // Poco rojo
//         g = (int)(t * 400);              // Verde medio
//         b = 255;                          // Azul al máximo
//     }
//     else if (t < 0.35)
//     {
//         // Transición de azul eléctrico a cyan brillante
//         double local_t = (t - 0.15) / 0.20;
//         r = lerp(30, 0, local_t);
//         g = lerp(200, 255, local_t);
//         b = 255;
//     }
//     else if (t < 0.60)
//     {
//         // Cyan a lila
//         double local_t = (t - 0.35) / 0.25;
//         r = lerp(0, 180, local_t);
//         g = lerp(255, 120, local_t);
//         b = 255;
//     }
//     else
//     {
//         // Lila a púrpura profundo
//         double local_t = (t - 0.60) / 0.40;
//         r = lerp(180, 150, local_t);
//         g = lerp(120, 40, local_t);
//         b = lerp(255, 200, local_t);
//     }
    
//     // Aplicar boost de brillo en los bordes
//     if (t < 0.1)
//     {
//         double boost = (0.1 - t) * 10.0;  // Multiplicador para bordes
//         b = (int)(b * (1.0 + boost * 0.2));
//         g = (int)(g * (1.0 + boost * 0.3));
//         if (b > 255) b = 255;
//         if (g > 255) g = 255;
//     }
    
//     return (create_rgba(r, g, b, 255));
// }



uint32_t	color_electric_edge(int iter, int max_iter)
{
    double	t;
    int		r;
    int		g;
    int		b;

    if (iter == max_iter)
        return (BLACK);
    
    t = (double)iter / (double)max_iter;
    
    // Los primeros escapes (bordes) tienen colores brillantes
    if (t < 0.05)
    {
        // BLANCO AZULADO para máximo contraste
        r = 150;
        g = 200;
        b = 255;
    }
    else if (t < 0.1)
    {
        // AZUL ELÉCTRICO PURO
        r = 0;
        g = lerp(200, 255, (t - 0.05) / 0.05);
        b = 255;
    }
    else if (t < 0.3)
    {
        // Transición a cyan
        double local_t = (t - 0.1) / 0.2;
        r = 0;
        g = 255;
        b = lerp(255, 200, local_t);
    }
    else
    {
        // Resto del gradiente normal
        double local_t = (t - 0.3) / 0.7;
        r = (int)(180 * local_t);
        g = (int)(255 - 200 * local_t);
        b = (int)(200 - 50 * local_t);
    }
    
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
