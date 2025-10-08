/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:58:33 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/08 13:55:46 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	parse_arg(int ac, char **av, t_fractol fractol)
{
	(void)fractol;
	if (ft_strncmp(av[1], "mandelbrot", 10) != 0
		&& ft_strncmp(av[1], "julia", 5) != 0)
		return (0);
	else if (ft_strncmp(av[1], "mandelbrot", 10) == 0 && ac != 2)
		return (0);
	else if (ft_strncmp(av[1], "julia", 5) == 0)
	{
		if (ac == 4)
		{
			fractol.julia_imag = ft_atof(av[2]);
			fractol.julia_real = ft_atof(av[3]);
		}
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

	init_fractol(&fractol);
	if (!parse_arg(ac, av, fractol))
	{
		ft_putstr_fd("err: invalid arguments", 2);
		return (0);
	}
	init_window(&fractol);
	render_fractals(&fractol);
	mlx_loop(fractol.mlx);
	free_exit(&fractol);
	mlx_terminate(fractol.mlx);
	printf("puto");
	return (0);
}
