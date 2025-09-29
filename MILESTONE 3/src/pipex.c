/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:20:02 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/29 14:22:52 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/*DEBERES DE MARIA HACK
parseo a tener en cuenta:
si hay mas o menos de 5 argumentos error
si el infile no existe error
si el outfile no tiene permisos de escritura error
si alguno de los comandos no existe error
*/

int	parse_args(int argc, char **argv, char **envp, t_pipex *pipex)
{
	char	*path;
	char	**real_path;

	(void)argv;
	if (argc != 5)
	{
		ft_putstr_fd("Error: Invalid number of arguments.\n", 2);
		return (0);
	}
	initializer(pipex);
	path = path_search(envp);
	real_path = ft_split(path, ':');
	return (1);
}

// t_pipex	ft_pipex(int argc, char **argv, char **envp)
// {

// }

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = NULL;
	if (parse_args(argc, argv, envp, pipex))
		ft_pipex(argc, argv, envp);
	else
		ft_putstr_fd("Error\n", 2);
}
