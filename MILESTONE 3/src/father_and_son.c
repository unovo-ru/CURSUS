/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   father_and_son.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:57:51 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/09/30 20:26:32 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


int	son_1(t_pipex *pipex, char **envp)
{
	close(pipex->pipe_fd[0]);
	dup2(pipex->infile, STDIN_FILENO);
	close(pipex->infile);
	dup2(pipex->pipe_fd[1], STDOUT_FILENO);
	close(pipex->outfile);
	close(pipex->pipe_fd[1]);
	execve(pipex->cmd1, pipex->cmd1_av, envp);
}


int	son_2(t_pipex *pipex, char **envp)
{
	close(pipex->pipe_fd[1]);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->outfile);
	dup2(pipex->pipe_fd[0], STDIN_FILENO);
	close(pipex->infile);
	close(pipex->pipe_fd[0]);
	execve(pipex->cmd2, pipex->cmd2_av, envp);
}

int	father(t_pipex *pipex, char **envp)
{
	if (!pipe(pipex->pipe_fd))
		return (-1);
	pipex->son_1 = fork();
	if (pipex->son_1 < 0)
		perror("fork failure\n");
	else if (pipex->son_1 == 0)
		son_1(pipex, envp);
	else
	{
		printf("padre espera\n");
		close(pipex->pipe_fd[1]);
		pipex->son_2 = fork();
		if (pipex->son_2 < 0)
			perror("fork failure\n");
		else if (pipex->son_2 == 0)
			son_2(pipex, envp);
		printf("padre sigue\n");
	}
	close(pipex->pipe_fd[0]);
	close(pipex->pipe_fd[1]);
	waitpid(pipex->son_1, NULL, 0);
	waitpid(pipex->son_2, NULL, 0);
	return (0);
}

