/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 20:47:40 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 13:59:39 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

/* -------------------------------------------------------------------------- */
/*                              Core Functionality                            */
/* -------------------------------------------------------------------------- */

/**
 * @brief Reads a line from a file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @return The read line ending with a newline, or NULL on error/EOF.
 */
char	*get_next_line(int fd);

/**
 * @brief Reads from the file descriptor into a buffer until a newline is found.
 *
 * @param fd The file descriptor to read from.
 * @param buffer The current static buffer content.
 * @return The updated buffer with the new data read.
 */
char	*read_line(int fd, char *buffer);

/**
 * @brief Extracts the line (characters up to '\n') from the buffer.
 *
 * @param buffer The buffer containing the full text read so far.
 * @return A new string containing only the line.
 */
char	*extract_line(char *buffer);

/**
 * @brief Removes the extracted line from the buffer, keeping the rest.
 *
 * @param buffer The original buffer.
 * @return A new string containing the remaining characters after the newline.
 */
char	*update_buffer(char *buffer);

/* -------------------------------------------------------------------------- */
/*                                String Utils                                */
/* -------------------------------------------------------------------------- */

/**
 * @brief Creates a substring from string 's'.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in 's'.
 * @param len The maximum length of the substring.
 * @param flag If 1, the original string 's' is freed.
 * @return The substring.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len, int flag);

/**
 * @brief Locates the first occurrence of character 'c' in string 's'.
 *
 * @param s The string to be searched.
 * @param c The character to search for.
 * @return A pointer to the character found, or NULL if not found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Allocates and returns a new string, result of concatenating s1 and s2.
 *        Note: Used here to join buffer reading chunks.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new concatenated string.
 */
char	*ft_strjoin(char *s1, char *s2);

/**
 * @brief Calculates the length of a string.
 *
 * @param s The string to measure.
 * @return The length of the string.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Duplicates a string by allocating sufficient memory and copying it.
 *
 * @param s The string to duplicate.
 * @return A pointer to the new string.
 */
char	*ft_strdup(const char *s);

#endif