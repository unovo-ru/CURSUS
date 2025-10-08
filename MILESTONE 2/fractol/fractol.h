/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:08:05 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/08 20:01:59 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <sys/wait.h>
# include <stdint.h>
# include <stdbool.h>
# include <math.h>
# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

# define WIDTH 1920
# define HEIGHT 1080
# define MAX_ITERATIONS 100
# define ESCAPE_RADIUS 4.0
# define X_MIN -2.0
# define X_MAX 2.0
# define Y_MIN -1.5
# define Y_MAX 1.5
# define ZOOM_FACTOR 1.1
# define MOVE_FACTOR 0.1
# define BLACK 0x000000FF
# define WHITE 0xFFFFFFFF
# define RED 0xFF0000FF
# define GREEN 0x00FF00FF
# define BLUE 0x0000FFFF
# define COLOR_SHIFT 15
# define MANDELBROT 1
# define JULIA 2
# define BURNING_SHIP 3
# define JULIA_C_REAL -0.7
# define JULIA_C_IMAG 0.27015
# define ERROR_ARGS "Error: Invalid arguments\n"
# define USAGE "Usage: ./fractol [mandelbrot|julia|burning_ship]\n"
# define ERROR_MLX "Error: Failed to initialize MLX42\n"
# define ERROR_IMG "Error: Failed to create image\n"

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int			type;
	int			width;
	int			heigth;
	double		zoom;
	double		max_real;
	double		min_real;
	double		max_imag;
	double		min_imag;
	uint32_t	color_draw;
	double		real;
	double		imaginary;
	int			max_iter;
	double		julia_real;
	double		julia_imag;
}				t_fractol;

typedef struct s_calc
{
	double	img;
	double	real;
}			t_calc;

typedef struct s_atod
{
	double			frac;
	double			base;
	double			val;
	const char		*mary;
	int				point;
}			t_atod;

void		init_fractol(t_fractol *fractol);
void		init_calc(t_calc *calc);
void		init_window(t_fractol *fractol);
double		ft_atod(const char *s, t_atod *atod);
int			mandelbrot(t_calc c);
t_calc		pixel_to_complex(int x, int y, t_fractol *fractol);
void		render_mandelbrot(t_fractol *fractol);
int			parse_arg(int ac, char **av, t_fractol *fractal, t_atod *atod);
void		free_exit(t_fractol *fractol);
int			main(int ac, char **av);
uint32_t	create_rgba(int r, int g, int b, int a);
int			lerp(int start, int end, double t);
uint32_t	color_blue_purple_smooth(int iter, int max_iter);
uint32_t	color_ultraviolet(int iter, int max_iter);
void		zoom_fractal(t_fractol *fractal, double mx, double my, double f);
void		handle_scroll(double xdelta, double ydelta, void *param);
void		handle_keys(void *param);
void		render_fractals(t_fractol *f);
void		render_julia(t_fractol *fractal);
void		pan_view(t_fractol *f, double dx, double dy);
int			julia(t_fractol *fractal, t_calc c);
void	finish_exit(t_fractol *fractal);

#endif