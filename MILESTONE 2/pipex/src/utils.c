/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 20:43:40 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 20:43:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	initializer(t_pipex *pipex)
{
	pipex->infile = -1;
	pipex->outfile = -1;
	pipex->pipe_fd[0] = -1;
	pipex->pipe_fd[1] = -1;
	pipex->son_1 = -1;
	pipex->son_2 = -1;
	pipex->exit_code = 0;
	pipex->env_var = NULL;
	pipex->cmd1 = NULL;
	pipex->cmd2 = NULL;
	pipex->cmd1_av = NULL;
	pipex->cmd2_av = NULL;
}

char	*path_search(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	free_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_all(t_pipex *pipex)
{
	if (pipex->cmd1)
		free(pipex->cmd1);
	if (pipex->cmd2)
		free(pipex->cmd2);
	if (pipex->env_var)
		free_array(pipex->env_var);
	if (pipex->cmd1_av)
		free_array(pipex->cmd1_av);
	if (pipex->cmd2_av)
		free_array(pipex->cmd2_av);
}

char	*set_path(t_pipex *pipex, char *cmd)
{
	int		i;
	char	*aux;
	char	*full_path;

	i = 0;
	aux = NULL;
	while (pipex->env_var && pipex->env_var[i])
	{
		aux = ft_strjoin(pipex->env_var[i], "/");
		full_path = ft_strjoin(aux, cmd);
		free(aux);
		if (!full_path)
			return (NULL);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	return (NULL);
}
