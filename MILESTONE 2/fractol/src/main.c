/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:58:33 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/05 18:31:15 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	parse_arg(int ac, char **av)
{
	if (ft_strncmp(av[1], "mandelbrot", 10) == 1
		|| ft_strncmp(av[1], "julia", 5) == 1)
	{
		printf("hola\n");
		return (0);
	}
	if (ft_strncmp(av[1], "mandelbrot", 10) && ac != 2)
	{
		printf("hola2\n");
		return (0);
	}
	if (ft_strncmp(av[1], "julia", 5) && ac != 4)
	{
		printf("hola3\n");
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

	(void)ac;
	(void)av;
	if (!parse_arg(ac, av))
		return (0);
	init_fractol(&fractol);
	init_window(&fractol);
	render_mandelbrot(&fractol);
	mlx_loop(fractol.mlx);
	free_exit(&fractol);
	mlx_terminate(fractol.mlx);
	printf("puto");
	return (0);
}
