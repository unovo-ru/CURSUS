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
	pipex->pipe[0] = -1;
	pipex->pipe[1] = -1;
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

/*DEBERES DE MARIA HACK*/
/*
1.- free array ** HECHO
2.- free all dobles punteros **
3.- funcion de iniciar pipex, control de errores (solo trabajar con 5 argumentos)
4.- despues llamar a initializer
5.- path search (con el control de errores)
6.- aplico el primer split a lo que me retorna path search con el separador " : ".
7.- liberar lo que trae split y manejar los errores (si da -1 libero)

*/
