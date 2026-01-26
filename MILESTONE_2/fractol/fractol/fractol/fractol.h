/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 18:08:05 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 17:43:12 by unovo-ru         ###   ########.fr       */
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
# define JULIA_C_REAL -0.7
# define JULIA_C_IMAG 0.27015
# define ERROR_ARGS "Error: Invalid arguments\n"
# define USAGE "Usage: ./fractol [mandelbrot|julia|burning_ship]\n"
# define ERROR_MLX "Error: Failed to initialize MLX42\n"
# define ERROR_IMG "Error: Failed to create image\n"

typedef struct s_fractol
{
	mlx_t		*mlx;			/* Handle to the MLX instance */
	mlx_image_t	*img;			/* Pointer to the image buffer */
	int			type;			/* Type of fractal (1=Mandelbrot, 2=Julia) */
	int			width;			/* Window width in pixels */
	int			heigth;			/* Window height in pixels */
	double		zoom;			/* Current zoom factor */
	double		max_real;		/* Maximum real coordinate (right bound) */
	double		min_real;		/* Minimum real coordinate (left bound) */
	double		max_imag;		/* Maximum imaginary coordinate (bottom) */
	double		min_imag;		/* Minimum imaginary coordinate (top) */
	uint32_t	color_draw;		/* Default drawing color (unused) */
	double		real;			/* Current real coordinate caching */
	double		imaginary;		/* Current imag coordinate caching */
	int			max_iter;		/* Maximum iteration limit used for rendering */
	double		julia_real;		/* Real constant for Julia Set */
	double		julia_imag;		/* Imaginary constant for Julia Set */
}				t_fractol;

typedef struct s_calc
{
	double	img;				/* Imaginary component of complex number */
	double	real;				/* Real component of complex number */
}			t_calc;

typedef struct s_atod
{
	double			frac;		/* Accumulator for fractional part */
	double			base;		/* Divisor for fractional part */
	double			val;		/* Accumulator for integer part */
	const char		*mary;		/* Pointer to current char in string */
	int				point;		/* Flag indicating decimal point found */
}			t_atod;

/* ========================================================================== */
/*                              Initialization                                */
/* ========================================================================== */

/**
 * @brief	Initializes the main fractol structure with default values.
 * @param	fractol Pointer to the fractol structure.
 */
void		init_fractol(t_fractol *fractol);

/**
 * @brief	Initializes the calculator structure values to zero.
 * @param	calc Pointer to the calc structure.
 */
void		init_calc(t_calc *calc);

/**
 * @brief	Initializes the MLX window, creates the image, and sets hooks.
 * @param	fractol Pointer to the fractol structure.
 */
void		init_window(t_fractol *fractol);

/* ========================================================================== */
/*                             Parsing & Utils                                */
/* ========================================================================== */

/**
 * @brief	Parses string to double.
 * @param	s The string to convert.
 * @param	atod Pointer to helper struct for conversion.
 * @return	The converted double value.
 */
double		ft_atod(const char *s, t_atod *atod);

/**
 * @brief	Parses command line arguments to select fractal type.
 * @param	ac Argument count.
 * @param	av Argument values.
 * @param	fractal Pointer to fractol structure to set type/values.
 * @param	atod Pointer to helper struct for parsing params.
 * @return	1 on success, 0 on failure.
 */
int			parse_arg(int ac, char **av, t_fractol *fractal, t_atod *atod);

/* ========================================================================== */
/*                             Fractal Logic                                  */
/* ========================================================================== */

/**
 * @brief	Calculates Mandelbrot iterations for a specific point.
 * @param	c Complex number representing the point.
 * @return	Number of iterations reached.
 */
int			mandelbrot(t_calc c);

/**
 * @brief	Calculates Julia iterations for a specific point.
 * @param	fractal Pointer to fractol structure (contains Julia constants).
 * @param	c Complex number representing the point.
 * @return	Number of iterations reached.
 */
int			julia(t_fractol *fractal, t_calc c);

/**
 * @brief	Maps a pixel coordinate (x,y) to the Complex plane.
 * @param	x Horizontal pixel position.
 * @param	y Vertical pixel position.
 * @param	fractol Pointer to fractol structure (window dimensions/bounds).
 * @return	The corresponding complex number.
 */
t_calc		pixel_to_complex(int x, int y, t_fractol *fractol);

/* ========================================================================== */
/*                               Rendering                                    */
/* ========================================================================== */

/**
 * @brief	Main rendering loop that dispatches to specific fractal renderers.
 * @param	f Pointer to the fractol structure.
 */
void		render_fractals(t_fractol *f);

/**
 * @brief	Renders the Mandelbrot set to the image buffer.
 * @param	fractol Pointer to the fractol structure.
 */
void		render_mandelbrot(t_fractol *fractol);

/**
 * @brief	Renders the Julia set to the image buffer.
 * @param	fractal Pointer to the fractol structure.
 */
void		render_julia(t_fractol *fractal);

/* ========================================================================== */
/*                             Colors & Maths                                 */
/* ========================================================================== */

/**
 * @brief	Combines RGBA channels into a single uint32_t color.
 * @param	r Red component (0-255).
 * @param	g Green component (0-255).
 * @param	b Blue component (0-255).
 * @param	a Alpha component (0-255).
 * @return	The combined RGBA color.
 */
uint32_t	create_rgba(int r, int g, int b, int a);

/**
 * @brief	Linear interpolation between two values.
 * @param	start Start value.
 * @param	end End value.
 * @param	t Interpolation factor (0.0 to 1.0).
 * @return	The interpolated value.
 */
int			lerp(int start, int end, double t);

/**
 * @brief	Generates a smooth blue-purple color based on iterations.
 * @param	iter Current iteration count.
 * @param	max_iter Maximum iterations allowed.
 * @return	The computed RGBA color.
 */
uint32_t	color_blue_purple_smooth(int iter, int max_iter);

/**
 * @brief	Generates an ultraviolet color scheme.
 * @param	iter Current iteration count.
 * @param	max_iter Maximum iterations allowed.
 * @return	The computed RGBA color.
 */
uint32_t	color_ultraviolet(int iter, int max_iter);

/* ========================================================================== */
/*                              Event Handling                                */
/* ========================================================================== */

/**
 * @brief	Zooms the fractal view centered at the mouse position.
 * @param	fractal Pointer to the fractol structure.
 * @param	mx Mouse X coordinate.
 * @param	my Mouse Y coordinate.
 * @param	f Zoom factor.
 */
void		zoom_fractal(t_fractol *fractal, double mx, double my, double f);

/**
 * @brief	Shifts the view (panning) by a delta factor.
 * @param	f Pointer to the fractol structure.
 * @param	dx Delta X (normalized width).
 * @param	dy Delta Y (normalized height).
 */
void		pan_view(t_fractol *f, double dx, double dy);

/**
 * @brief	Hook for mouse scroll events (used for zooming).
 * @param	xdelta Scroll X delta.
 * @param	ydelta Scroll Y delta.
 * @param	param User data pointer (t_fractol *).
 */
void		handle_scroll(double xdelta, double ydelta, void *param);

/**
 * @brief	Hook for keyboard events (movement, exit).
 * @param	param User data pointer (t_fractol *).
 */
void		handle_keys(void *param);

/* ========================================================================== */
/*                                Cleanup                                     */
/* ========================================================================== */

/**
 * @brief	Cleans up resources and exits (success/failure agnostic).
 * @param	fractol Pointer to the fractol structure.
 */
void		free_exit(t_fractol *fractol);

/**
 * @brief	Cleans up MLX resources and exits with failure status.
 * @param	fractal Pointer to the fractol structure.
 */
void		finish_exit(t_fractol *fractal);

#endif