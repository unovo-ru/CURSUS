/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:46:39 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/23 15:58:23 by unovo-ru         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

/* ************************************************************************** */
/*                                                                            */
/*                           STRUCTURE DEFINITIONS                            */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ************************************************************************** */
/*                                                                            */
/*                           CHARACTER FUNCTIONS                              */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Checks if the character is an alphabetic character.
 * @param c The character to check.
 * @return Non-zero if the character is an alphabetic character, zero otherwise.
 */
int		ft_isalpha(int c);

/**
 * @brief Checks if the character is a digit (0 through 9).
 * @param c The character to check.
 * @return Non-zero if the character is a digit, zero otherwise.
 */
int		ft_isdigit(int c);

/**
 * @brief Checks if the character is alphanumeric.
 * @param c The character to check.
 * @return Non-zero if the character is alphanumeric, zero otherwise.
 */
int		ft_isalnum(int c);

/**
 * @brief Checks if the character fits into the ASCII character set.
 * @param c The character to check.
 * @return Non-zero if the character is an ASCII character, zero otherwise.
 */
int		ft_isascii(int c);

/**
 * @brief Checks if the character is printable (including space).
 * @param c The character to check.
 * @return Non-zero if the character is printable, zero otherwise.
 */
int		ft_isprint(int c);

/**
 * @brief Converts a lowercase letter to uppercase.
 * @param c The character to convert.
 * @return The uppercase equivalent of c, or c if not possible.
 */
int		ft_toupper(int c);

/**
 * @brief Converts an uppercase letter to lowercase.
 * @param c The character to convert.
 * @return The lowercase equivalent of c, or c if not possible.
 */
int		ft_tolower(int c);

/* ************************************************************************** */
/*                                                                            */
/*                             MEMORY FUNCTIONS                               */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Fills the first n bytes of the memory area pointed to by s
 *        with the constant byte c.
 * @param s The memory area to fill.
 * @param c The constant byte to fill with.
 * @param n The number of bytes to fill.
 * @return A pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Erases the data in the n bytes of the memory starting at the
 *        location pointed to by s, by writing zeros (bytes containing '\0')
 *        to that area.
 * @param s The memory area to erase.
 * @param n The number of bytes to erase.
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *        The memory areas must not overlap.
 * @param dest The destination memory area.
 * @param src The source memory area.
 * @param n The number of bytes to copy.
 * @return A pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 *        The memory areas may overlap.
 * @param dest The destination memory area.
 * @param src The source memory area.
 * @param n The number of bytes to copy.
 * @return A pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s
 *        for the first instance of c.
 * @param s The memory area to scan.
 * @param c The character to search for.
 * @param n The number of bytes to scan.
 * @return A pointer to the matching byte or NULL if the character
 *         does not occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of the memory areas s1 and s2.
 * @param s1 The first memory area.
 * @param s2 The second memory area.
 * @param n The number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if the first
 *         n bytes of s1 is found, respectively, to be less than, to match,
 *         or be greater than the first n bytes of s2.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each
 *		and returns a pointer to the allocated memory. The memory is set to zero.
 * @param nmemb The number of elements.
 * @param size The size of each element.
 * @return A pointer to the allocated memory.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/* ************************************************************************** */
/*                                                                            */
/*                             STRING FUNCTIONS                               */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Calculates the length of a string.
 * @param s The string to calculate the length of.
 * @return The length of the string.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string
 *        src to dest, NUL-terminating the result.
 * @param dest The destination string.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string they tried to create.
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Appends the NUL-terminated string src to the end of dest.
 *        It will append at most size - strlen(dst) - 1 bytes,
 *        NUL-terminating the result.
 * @param dst The destination string.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string they tried to create.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Returns a pointer to the first occurrence of the character c
 *        in the string s.
 * @param s The string to search.
 * @param c The character to search for.
 * @return A pointer to the matched character or NULL if the character
 *         is not found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Returns a pointer to the last occurrence of the character c
 *        in the string s.
 * @param s The string to search.
 * @param c The character to search for.
 * @return A pointer to the matched character or NULL if the character
 *         is not found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Compares the two strings s1 and s2. It compares not more than
 *        n characters.
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if s1
 *         (or the first n bytes thereof) is found, respectively, to be
 *         less than, to match, or be greater than s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated string
 *        little in the string big, where not more than len characters
 *        are searched.
 * @param big The string to search.
 * @param little The substring to search for.
 * @param len The maximum number of characters to search.
 * @return A pointer to the beginning of the located substring, or NULL
 *         if the substring is not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Returns a pointer to a new string which is a duplicate of the string s.
 * @param s The string to duplicate.
 * @return A pointer to the duplicated string.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string 's'.
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 *        result of the concatenation of 's1' and 's2'.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates (with malloc(3)) and returns a copy of 's1' with the
 *        characters specified in 'set' removed from the beginning and the
 *        end of the string.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings
 *        obtained by splitting 's' using the character 'c' as a delimiter.
 * @param s The string to split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split. NULL if
 *         the allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Applies the function 'f' to each character of the string 's',
 *        and passing its index as first argument to create a new string
 *        (with malloc(3)) resulting from successive applications of 'f'.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of 'f'.
 *         Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function 'f' on each character of the string passed
 *        as argument, passing its index as first argument. Each character
 *        is passed by address to 'f' to be modified if necessary.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ************************************************************************** */
/*                                                                            */
/*                           TYPE CONVERSION                                  */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts the initial portion of the string pointed to by nptr to int.
 * @param nptr The string to convert.
 * @return The converted integer value.
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Converts the initial portion of the string pointed to by str to long.
 * @param str The string to convert.
 * @return The converted long value.
 */
long	ft_atol(char *str);

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the
 *        integer received as an argument.
 * @param n The integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int n);

/* ************************************************************************** */
/*                                                                            */
/*                             I/O FUNCTIONS                                  */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor followed
 *        by a newline.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer 'n' to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Writes the formatted string to the standard output.
 * @param input The format string.
 * @param ... The arguments to replace format specifiers.
 * @return The number of characters printed.
 */
int		ft_printf(char const *input, ...);

/**
 * @brief Reads a line from the specified file descriptor.
 * @param fd The file descriptor to read from.
 * @return The line read from the file descriptor, including the newline
 *         character, or NULL if there is nothing else to read or an error
 *         occurred.
 */
char	*get_next_line(int fd);

/**
 * @brief (Bonus) Reads a line from ID.
 * @param fd The file descriptor to read from.
 * @return The line read.
 */
char	*get_next_line_bonus(int fd);

/* Printf Helpers (Internal/Auxiliary) */

/**
 * @brief Outputs a character to the given file descriptor and returns the count.
 * @param c The character to put.
 * @return The number of characters written.
 */
int		pf_putchar_fd(char c);

/**
 * @brief Outputs a number to the given file descriptor and returns the count.
 * @param n The number to put.
 * @return The number of characters written.
 */
int		pf_putnbr_fd(int n);

/**
 * @brief Outputs a string to the given file descriptor and returns the count.
 * @param s The string to put.
 * @return The number of characters written.
 */
int		pf_putstr_fd(char *s);

/**
 * @brief Calculates length of hex number.
 * @param num The number.
 * @return Length.
 */
int		ft_hexa_max(unsigned long long num);
int		ft_hexa_min(unsigned long long num);

/**
 * @brief Handles variable types for printf.
 * @param args The va_list.
 * @param c The conversion specifier.
 * @return Length printed.
 */
int		ft_var_type(va_list args, char c);

/**
 * @brief Helper for hex conversion.
 * @param y Pointer to value.
 * @return Length.
 */
int		ft_hexa(void *y);

/**
 * @brief Prints an unsigned int.
 * @param n The number.
 * @return Length printed.
 */
int		ft_put_unsig(unsigned int n);

/**
 * @brief Substring helper for GNL.
 */
char	*gnl_substr(char const *s, unsigned int start, size_t len, int flag);
char	*gnl_strjoin(char *s1, char *s2);

/* ************************************************************************** */
/*                                                                            */
/*                           LINKED LIST FUNCTIONS                            */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Allocates (with malloc(3)) and returns a new node. The member
 *        variable 'content' is initialized with the value of the parameter
 *        'content'. The variable 'next' is initialized to NULL.
 * @param content The content to create the new node with.
 * @return The new node.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds the node 'new' at the beginning of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The node to add to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return The length of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Returns the last node of the list.
 * @param lst The beginning of the list.
 * @return The last node of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds the node 'new' at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The node to add to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter a node and frees the memory of the node's
 *        content using the function 'del' given as a parameter and free
 *        the node. The memory of 'next' must not be freed.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given node and every successor of that node,
 *        using the function 'del' and free(3). Finally, the pointer to the
 *        list must be set to NULL.
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the node.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' on the content
 *        of each node.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' on the content
 *        of each node. Creates a new list resulting of the successive
 *        applications of the function 'f'. The 'del' function is used to
 *        delete the content of a node if needed.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a
 *        node if needed.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif

