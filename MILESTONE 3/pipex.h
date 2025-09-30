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
# include "libft.h"

typedef struct s_pipex
{
	int			infile;
	int			outfile;
	int			pipe_fd[2];
	pid_t		son_1;
	pid_t		son_2;
	int			exit_code;
	char		**env_var;
	char		*cmd1; /*ls*/
	char		*cmd2;
	char		**cmd1_av; /*ls 
							-l
							-a*/
	char		**cmd2_av;
}		t_pipex;

/*------------------MAIN FUNCTIONS--------------------*/
// t_pipex	ft_pipex(int argc, char **argv, char **envp);
int		main(int argc, char **argv, char **envp);

/*-----------PARSE AND INITIAL FUNCTIONS--------------*/
void	initializer(t_pipex *pipex);
void	free_array(char **array);
void	*free_all(char *str1, char **str2);
char	*path_search(char **envp);

char	*set_cmd(t_pipex *pipex, char *argv);
int		parse_arg(int argc, char **argv);
int		init_pipex(int argc, char **argv, char **envp, t_pipex *pipex);
int		set_file(t_pipex *pipex, char **argv);

int		father(t_pipex *pipex, char **envp);


#endif
