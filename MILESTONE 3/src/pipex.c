/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:20:02 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/01 19:57:53 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	parse_arg(int argc, char **argv)
{
	int	i;

	if (argc != 5)
	{
		ft_putstr_fd("Error: Invalid number of arguments.\n", 2);
		return (0);
	}
	i = 1;
	if (argv[2][0] == '\0' || argv[3][0] == '\0')
	{
		ft_putstr_fd("Error: Invalid command.\n", 2);
		return (0);
	}
	while (argv[i])
	{
		if (argv[i] == NULL)
			return (0);
		else
			i++;
	}
	return (1);
}

static int	init_pipex_aux(char **argv, t_pipex *pipex)
{
	if (set_cmd(pipex, argv) == -1)
	{
		free_all(pipex);
		ft_putstr_fd("command failure", 2);
		return (0);
	}
	pipex->cmd1 = set_path(pipex, pipex->cmd1_av[0]);
	pipex->cmd2 = set_path(pipex, pipex->cmd2_av[0]);
	if (!pipex->cmd1 || !pipex->cmd2)
	{
		ft_putstr_fd("Command not found\n\n", 2);
		free_all(pipex);
		return (0);
	}
	return (1);
}

int	init_pipex(int argc, char **argv, char **envp, t_pipex *pipex)
{
	char	*path;

	if (!parse_arg(argc, argv))
		return (0);
	initializer(pipex);
	path = path_search(envp);
	if (!path || !*path)
		return (0);
	pipex->env_var = ft_split(path, ':');
	if (!pipex->env_var)
		return (0);
	if (init_pipex_aux(argv, pipex) == 0)
		return (0);
	if (set_file(pipex, argv) == -1)
		return (0);
	return (1);
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

	if (init_pipex(argc, argv, envp, &pipex) == 0)
		return (0);
	if (launch_children(&pipex, envp) == -1)
		return (1);
	return (father(&pipex));
}
