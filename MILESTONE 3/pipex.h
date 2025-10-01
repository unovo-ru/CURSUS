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
	char		*cmd1;
	char		*cmd2;
	char		**cmd1_av;
	char		**cmd2_av;
}		t_pipex;

/*------------------MAIN FUNCTIONS--------------------*/
int		main(int argc, char **argv, char **envp);

/*-----------PARSE AND INITIAL FUNCTIONS--------------*/
void	initializer(t_pipex *pipex);
void	free_array(char **array);
void	free_all(t_pipex *pipex);
char	*path_search(char **envp);

int		set_cmd(t_pipex *pipex, char **argv);
char	*set_path(t_pipex *pipex, char *cmd);
int		parse_arg(int argc, char **argv);
int		init_pipex(int argc, char **argv, char **envp, t_pipex *pipex);
int		set_file(t_pipex *pipex, char **argv);

int		son_1(t_pipex *pipex, char **envp);
int		son_2(t_pipex *pipex, char **envp);
int		launch_children(t_pipex *pipex, char **envp);
int		father(t_pipex *pipex);

#endif
