/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:46:39 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/22 20:06:55 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>

/* ************************************************************************** */
/*                                 MACROS                                     */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

/* ************************************************************************** */
/*                              DATA STRUCTURES                               */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*prev;
	struct s_list	*next;
}			t_list;

/* ************************************************************************** */
/*                         CHARACTER CLASSIFICATION                           */
/* ************************************************************************** */

/**
 * @brief Checks if character is alphabetic (a-z, A-Z).
 * @param c Character to check (as int).
 * @return Non-zero if alphabetic, 0 otherwise.
 */
int		ft_isalpha(int c);

/**
 * @brief Checks if character is a digit (0-9).
 * @param c Character to check (as int).
 * @return Non-zero if digit, 0 otherwise.
 */
int		ft_isdigit(int c);

/**
 * @brief Checks if character is alphanumeric (a-z, A-Z, 0-9).
 * @param c Character to check (as int).
 * @return Non-zero if alphanumeric, 0 otherwise.
 */
int		ft_isalnum(int c);

/**
 * @brief Checks if character is within the ASCII set (0-127).
 * @param c Character to check (as int).
 * @return Non-zero if ASCII, 0 otherwise.
 */
int		ft_isascii(int c);

/**
 * @brief Checks if character is printable (including space).
 * @param c Character to check (as int).
 * @return Non-zero if printable, 0 otherwise.
 */
int		ft_isprint(int c);

/**
 * @brief Converts a character to uppercase.
 * @param c Character to convert.
 * @return Uppercase character if convertible, else c.
 */
int		ft_toupper(int c);

/**
 * @brief Converts a character to lowercase.
 * @param c Character to convert.
 * @return Lowercase character if convertible, else c.
 */
int		ft_tolower(int c);

/* ************************************************************************** */
/*                            MEMORY OPERATIONS                               */
/* ************************************************************************** */

/**
 * @brief Fills memory with a constant byte.
 * @param s Pointer to the memory area.
 * @param c Byte to fill with.
 * @param n Number of bytes to fill.
 * @return Pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Zeroes out a memory area.
 * @param s Pointer to the memory area.
 * @param n Number of bytes to zero.
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Copies memory area.
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies memory area, handling overlapping areas safely.
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Scans memory for a character.
 * @param s Pointer to the memory area.
 * @param c Character to search for.
 * @param n Number of bytes to scan.
 * @return Pointer to the matching byte or NULL if not found.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares two memory areas.
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n Number of bytes to compare.
 * @return Difference between first differing bytes, or 0 if equal.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Allocates and zeroes memory for an array.
 * @param nmemb Number of elements.
 * @param size Size of each element.
 * @return Pointer to the allocated memory.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/* ************************************************************************** */
/*                            STRING MANIPULATION                             */
/* ************************************************************************** */

/**
 * @brief Calculates the length of a string.
 * @param s The string to measure.
 * @return Length of the string.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Copies a string to a specific size buffer.
 * @param dest Destination string.
 * @param src Source string.
 * @param size Size of the destination buffer.
 * @return Length of the source string.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Concatenates a string to a specific size buffer.
 * @param dst Destination string.
 * @param src Source string.
 * @param size Size of the destination buffer.
 * @return Total length of string tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Locates the first occurrence of a character in string.
 * @param s String to search.
 * @param c Character to search for.
 * @return Pointer to the located character, or NULL if not found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Locates the last occurrence of a character in string.
 * @param s String to search.
 * @param c Character to search for.
 * @return Pointer to the located character, or NULL if not found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Compares two strings up to n characters.
 * @param s1 First string.
 * @param s2 Second string.
 * @param n Max number of characters to compare.
 * @return Difference between first differing characters.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates a substring in a string.
 * @param big String to search in.
 * @param little Substring to search for.
 * @param len Max number of characters to search.
 * @return Pointer to beginning of the substring, or NULL if not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Duplicates a string.
 * @param s String to duplicate.
 * @return Pointer to the new string.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Creates a substring from a string.
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Trims characters from the beginning and end of a string.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Joins two strings.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string result of the concatenation. NULL if allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Splits a string using a delimiter.
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split. NULL if allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Applies a function to each character of a string to create a new string.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of 'f'.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies a function to each character of a string, modifying it in place.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ************************************************************************** */
/*                              CONVERSION                                    */
/* ************************************************************************** */

/**
 * @brief Converts a string to an integer.
 * @param nptr The string to be converted.
 * @return The converted integer value.
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Converts a string to a long integer.
 * @param str The string to be converted.
 * @return The converted long value.
 */
long	ft_atol(char *str);

/**
 * @brief Converts an integer to a string.
 * @param n The integer to convert.
 * @return The string representing the integer. NULL if allocation fails.
 */
char	*ft_itoa(int n);

/* ************************************************************************** */
/*                                  I/O                                       */
/* ************************************************************************** */

/**
 * @brief Outputs a character to a file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs a string to a file descriptor.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs a string followed by a newline to a file descriptor.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs an integer to a file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd);

/* ************************************************************************** */
/*                               PRINTF                                       */
/* ************************************************************************** */

/**
 * @brief Custom implementation of printf.
 * @param input Format string.
 * @param ... Variable arguments.
 * @return Number of characters printed.
 */
int		ft_printf(char const *input, ...);

/**
 * @brief Printf helper: Writes a character to STDOUT.
 * @param c Character to write.
 * @return Number of bytes written.
 */
int		pf_putchar_fd(char c);

/**
 * @brief Printf helper: Writes an integer to STDOUT.
 * @param n Integer to write.
 * @return Number of bytes written.
 */
int		pf_putnbr_fd(int n);

/**
 * @brief Printf helper: Writes a string to STDOUT.
 * @param s String to write.
 * @return Number of bytes written.
 */
int		pf_putstr_fd(char *s);

/**
 * @brief Printf helper: Prints uppercase hexadecimal number.
 * @param num Number to print.
 * @return Number of bytes written.
 */
int		ft_hexa_max(unsigned long long num);

/**
 * @brief Printf helper: Handles format specifiers.
 * @param args Variable argument list.
 * @param c Format specifier character.
 * @return Number of characters printed.
 */
int		ft_var_type(va_list args, char c);

/**
 * @brief Printf helper: Prints a pointer address in hex.
 * @param y Pointer to print.
 * @return Number of bytes written.
 */
int		ft_hexa(void *y);

/**
 * @brief Printf helper: Prints an unsigned integer.
 * @param n Number to print.
 * @return Number of bytes written.
 */
int		ft_put_unsig(unsigned int n);

/**
 * @brief Printf helper: Prints lowercase hexadecimal number.
 * @param num Number to print.
 * @return Number of bytes written.
 */
int		ft_hexa_min(unsigned long long num);

/* ************************************************************************** */
/*                           GET NEXT LINE                                    */
/* ************************************************************************** */

/**
 * @brief Reads a line from a file descriptor.
 * @param fd The file descriptor to read from.
 * @return Read line, or NULL if there is nothing else to read or an error occurred.
 */
char	*get_next_line(int fd);

/**
 * @brief GNL Helper: Creates a substring.
 * @param s Source string.
 * @param start Start index.
 * @param len Length of substring.
 * @param flag Internal flag for behavior.
 * @return The substring.
 */
char	*gnl_substr(char const *s, unsigned int start, size_t len, int flag);

/**
 * @brief GNL Helper: Joins two strings.
 * @param s1 First string.
 * @param s2 Second string.
 * @return Joined string.
 */
char	*gnl_strjoin(char *s1, char *s2);

/**
 * @brief Reads a line from a file descriptor (Bonus).
 * @param fd The file descriptor to read from.
 * @return Read line, or NULL if there is nothing else to read or an error occurred.
 */
char	*get_next_line_bonus(int fd);

/* ************************************************************************** */
/*                            LINKED LISTS                                    */
/* ************************************************************************** */

/**
 * @brief Creates a new list node.
 * @param content The content to put in the new node.
 * @return The new node.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds an element to the front of a list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The link to add at the beginning of the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of elements in a list.
 * @param lst The beginning of the list.
 * @return The length of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of the list.
 * @param lst The beginning of the list.
 * @return Last element of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds an element to the end of a list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The link to add at the end of the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Deletes and frees a node.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees a list.
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates a list and applies a function to the content of each element.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates a list and applies a function to create a new list.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content if needed.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
