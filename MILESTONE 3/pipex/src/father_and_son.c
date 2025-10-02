/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   father_and_son.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:57:51 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/02 12:02:33 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	set_cmd(t_pipex *pipex, char **argv)
{
	pipex->cmd1_av = ft_split(argv[2], ' ');
	if (!pipex->cmd1_av || !*pipex->cmd1_av)
		return (-1);
	pipex->cmd2_av = ft_split(argv[3], ' ');
	if (!pipex->cmd2_av || !*pipex->cmd2_av)
		return (-1);
	return (0);
}

int	son_1(t_pipex *pipex, char **envp)
{
	if (!pipex->cmd1 || !pipex->cmd1_av)
		exit(127);
	close(pipex->pipe_fd[0]);
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->infile);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->outfile);
	close(pipex->pipe_fd[1]);
	execve(pipex->cmd1, pipex->cmd1_av, envp);
	perror("execve failure\n");
	exit(EXIT_FAILURE);
}

int	son_2(t_pipex *pipex, char **envp)
{
	if (!pipex->cmd2 || !pipex->cmd2_av)
		exit(127);
	close(pipex->pipe_fd[1]);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->outfile);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->infile);
	close(pipex->pipe_fd[0]);
	execve(pipex->cmd2, pipex->cmd2_av, envp);
	perror("execve failure\n");
	exit(EXIT_FAILURE);
}

int	father(t_pipex *pipex)
{
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	close(pipex->infile);
	close(pipex->outfile);
	waitpid(pipex->son_1, NULL, 0);
	waitpid(pipex->son_2, NULL, 0);
	free_all(pipex);
	return (0);
}

int	launch_children(t_pipex *pipex, char **envp)
{
	if (pipe(pipex->pipe_fd) == -1)
	{
		perror("pipe failure\n");
		return (-1);
	}
	pipex->son_1 = fork();
	if (pipex->son_1 < 0)
	{
		free_all(pipex);
		perror("fork failure\n");
		return (-1);
	}
	if (pipex->son_1 == 0)
		son_1(pipex, envp);
	pipex->son_2 = fork();
	if (pipex->son_2 < 0)
	{
		free_all(pipex);
		perror("fork failure\n");
		return (1);
	}
	if (pipex->son_2 == 0)
		son_2(pipex, envp);
	return (0);
}
