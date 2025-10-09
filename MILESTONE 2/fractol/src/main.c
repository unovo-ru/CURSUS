/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:58:33 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/09 17:55:27 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	parse_arg(int ac, char **av, t_fractol *fractol, t_atod *atod)
{
	if (ft_strlen(av[1]) == 0)
		return (0);
	if (ft_strncmp(av[1], "julia", ft_strlen(av[1])) == 0
		&& (ac == 2 || ac == 4))
	{
		fractol->type = JULIA;
		fractol->julia_real = -0.7;
		fractol->julia_imag = 0.27015;
		if (ac == 4)
		{
			fractol->julia_real = ft_atod(av[2], atod);
			fractol->julia_imag = ft_atod(av[3], atod);
		}
	}
	else if (ft_strncmp(av[1], "mandelbrot", ft_strlen(av[1])) == 0
		&& ac == 2)
		fractol->type = MANDELBROT;
	else
	{
		return (0);
	}
	return (1);
}

void	free_exit(t_fractol *fractol)
{
	mlx_delete_image(fractol->mlx, fractol->img);
	mlx_terminate(fractol->mlx);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;
	t_atod		atod;

	if (ac == 1)
	{
		ft_putstr_fd("Fractol type not specified\n", 2);
		return (0);
	}
	init_fractol(&fractol);
	if (!parse_arg(ac, av, &fractol, &atod))
	{
		ft_putstr_fd("err: invalid arguments\n", 2);
		return (0);
	}
	init_window(&fractol);
	render_fractals(&fractol);
	mlx_loop(fractol.mlx);
	finish_exit(&fractol);
	mlx_terminate(fractol.mlx);
	free_exit(&fractol);
	return (0);
}
