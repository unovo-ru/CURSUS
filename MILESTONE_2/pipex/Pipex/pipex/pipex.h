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
	int			infile;		/* File descriptor for the input file */
	int			outfile;	/* File descriptor for the output file */
	int			pipe_fd[2];	/* Array for pipe ends (read/write) */
	pid_t		son_1;		/* Process ID for the first child */
	pid_t		son_2;		/* Process ID for the second child */
	int			exit_code;	/* Exit status code for the process */
	char		**env_var;	/* Split environment PATH directories */
	char		*cmd1;		/* Full path to the first command executable */
	char		*cmd2;		/* Full path to the second command executable */
	char		**cmd1_av;	/* Arguments array for the first command */
	char		**cmd2_av;	/* Arguments array for the second command */
}		t_pipex;

/* ************************************************************************** */
/*                                                                            */
/*                           MAIN FUNCTIONS                                   */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief The main entry point for the pipex program.
 * @param argc variable argument count.
 * @param argv variable argument vector.
 * @param envp environment variables.
 * @return 0 on success, or an error code on failure.
 */
int		main(int argc, char **argv, char **envp);

/* ************************************************************************** */
/*                                                                            */
/*                      PARSING & INITIALIZATION                              */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Initializes the pipex structure with default values.
 * @param pipex Pointer to the pipex structure.
 */
void	initializer(t_pipex *pipex);

/**
 * @brief Frees a null-terminated array of strings.
 * @param array The array to free.
 */
void	free_array(char **array);

/**
 * @brief Frees all allocated memory in the pipex structure.
 * @param pipex Pointer to the pipex structure.
 */
void	free_all(t_pipex *pipex);

/**
 * @brief Searches for the "PATH" variable in the environment.
 * @param envp The environment variables array.
 * @return A pointer to the value of the PATH variable, or NULL if not found.
 */
char	*path_search(char **envp);

/**
 * @brief Validates the command line arguments.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @return 1 if arguments are valid, 0 otherwise.
 */
int		parse_arg(int argc, char **argv);

/**
 * @brief Initializes the entire pipex process, including parsing and setup.
 * @param argc Argument count.
 * @param argv Argument vector.
 * @param envp Environment variables.
 * @param pipex Pointer to the pipex structure to initialize.
 * @return 1 on success, 0 on failure.
 */
int		init_pipex(int argc, char **argv, char **envp, t_pipex *pipex);

/* ************************************************************************** */
/*                                                                            */
/*                        COMMAND & PATH SETUP                                */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Splits command strings into argument arrays for both commands.
 * @param pipex Pointer to the pipex structure.
 * @param argv Argument vector containing command strings.
 * @return 0 on success, -1 on failure.
 */
int		set_cmd(t_pipex *pipex, char **argv);

/**
 * @brief Finds the executable path for a command.
 * @param pipex Pointer to the pipex structure containing environment paths.
 * @param cmd The command name to search for.
 * @return The full path to the executable, or NULL if not found.
 */
char	*set_path(t_pipex *pipex, char *cmd);

/**
 * @brief Opens input and output files and stores their file descriptors.
 * @param pipex Pointer to the pipex structure.
 * @param argv Argument vector containing file names.
 * @return 0 on success, -1 on failure.
 */
int		set_file(t_pipex *pipex, char **argv);

/* ************************************************************************** */
/*                                                                            */
/*                        PROCESS & EXECUTION                                 */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Executes the first child process (cmd1).
 * @param pipex Pointer to the pipex structure.
 * @param envp Environment variables.
 * @return Does not return on success (executes cmd), exits with error
 *         code on failure.
 */
int		son_1(t_pipex *pipex, char **envp);

/**
 * @brief Executes the second child process (cmd2).
 * @param pipex Pointer to the pipex structure.
 * @param envp Environment variables.
 * @return Does not return on success (executes cmd), exits with error
 *         code on failure.
 */
int		son_2(t_pipex *pipex, char **envp);

/**
 * @brief Creates the pipe and forks both child processes.
 * @param pipex Pointer to the pipex structure.
 * @param envp Environment variables.
 * @return 0 on success, non-zero on error.
 */
int		launch_children(t_pipex *pipex, char **envp);

/**
 * @brief Closes pipes and files in the parent process and waits for children.
 * @param pipex Pointer to the pipex structure.
 * @return 0 on success.
 */
int		father(t_pipex *pipex);

#endif
