/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:20:02 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/29 23:40:49 by unovo-ru         ###   ########.fr       */
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

int	parse_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i] == NULL)
			return (0);
		else
			i++;
	}
	if (argc != 5)
	{
		ft_putstr_fd("Error: Invalid number of arguments.\n", 2);
		return (0);
	}
	return (1);
}

int	init_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
	char	*path;

	(void)argv;
	if (!parse_arg(argc, argv))
		return (0);
	initializer(pipex);
	path = path_search(envp);
	if (!path || !*path)
		return (0);
	pipex->env_var = ft_split(path, ':');
	if (!pipex->env_var)
		return (0);
	pipex->cmd1 = set_cmd(pipex, argv[2]);
	pipex->cmd2 = set_cmd(pipex, argv[3]);
	if (set_file(pipex, argv))
		return (1);
	return (0);
}

char	*set_cmd(t_pipex *pipex, char *argv)
{
	int		i;
	char	**res;
	char	*aux;
	char	*full_path;

	i = 0;
	res = ft_split(argv, ' ');
	if (!*res || !res)
		return (NULL);
	while (pipex->env_var[i])
	{
		aux = ft_strjoin(pipex->env_var[i], "/");
		full_path = ft_strjoin(aux, res[0]);
		if (!full_path)
			return (free_all(aux, &full_path));
		if (access(full_path, X_OK) == 0)
			return (full_path);
		else
		{
			free_all(aux, &full_path);
			i++;
		}
	}
	return (NULL);
}

int	set_file(t_pipex *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		perror("open infile error");
		return (-1);
	}
	pipex->outfile = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (pipex->outfile == -1)
	{
		perror("open outfile error");
		return (-1);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (!parse_arg(argc, argv))
		return (-57892);
	else
		init_pipex(argc, argv, envp, &pipex);
}
