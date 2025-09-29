/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 20:09:44 by marvin            #+#    #+#             */
/*   Updated: 2025/09/28 20:09:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/wait.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int			infile;
	int			outfile;
	int			pipe[2];
	pid_t		son_1;
	pid_t		son_2;
	int			exit_code;
	char		**env_var;
	char		*cmd1;
	char		*cmd2;
	char		**cmd1_av;
	char		**cmd2_av;
}		t_pipex;

/*------------------MAIN FUNCTIONS--------------------*/

t_pipex ft_pipex(int argc, char **argv, char **envp);
int		main(int argc, char **argv, char **envp);

/*-----------PARSE AND INITIAL FUNCTIONS--------------*/

void	initializer(t_pipex *pipex);
void	free_array(char **array);


#endif


