/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:46:39 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/22 19:45:35 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <stdarg.h>
# include "../printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

/* ========================================================================== */
/*                       CHARACTER CHECKS & CONVERSION                        */
/* ========================================================================== */

/**
 * @brief Checks for an alphabetic character.
 * @param c The character to check.
 * @return Non-zero if c is alphabetic, zero otherwise.
 */
int		ft_isalpha(int c);

/**
 * @brief Checks for a decimal digit character.
 * @param c The character to check.
 * @return Non-zero if c is a digit, zero otherwise.
 */
int		ft_isdigit(int c);

/**
 * @brief Checks for an alphanumeric character.
 * @param c The character to check.
 * @return Non-zero if c is alphanumeric, zero otherwise.
 */
int		ft_isalnum(int c);

/**
 * @brief Checks for an ASCII character.
 * @param c The character to check.
 * @return Non-zero if c is a 7-bit unsigned char value that fits into the
 *         ASCII character set, zero otherwise.
 */
int		ft_isascii(int c);

/**
 * @brief Checks for any printable character including space.
 * @param c The character to check.
 * @return Non-zero if c is printable, zero otherwise.
 */
int		ft_isprint(int c);

/**
 * @brief Converts a lower-case letter to the corresponding upper-case letter.
 * @param c The character to convert.
 * @return The converted letter, or c if the conversion was not possible.
 */
int		ft_toupper(int c);

/**
 * @brief Converts an upper-case letter to the corresponding lower-case letter.
 * @param c The character to convert.
 * @return The converted letter, or c if the conversion was not possible.
 */
int		ft_tolower(int c);

/* ========================================================================== */
/*                            MEMORY MANIPULATION                             */
/* ========================================================================== */

/**
 * @brief Fills the first n bytes of the memory area pointed to by s with the
 *        constant byte c.
 * @param s Pointer to the memory area.
 * @param c The byte to fill with.
 * @param n Number of bytes to fill.
 * @return A pointer to the memory area s.
 */
void	*ft_memset(void *s, int c, size_t n);

/**
 * @brief Erases the data in the n bytes of the memory starting at the location
 *        pointed to by s, by writing zeros (bytes containing '\0') to that
 *        area.
 * @param s Pointer to the memory area.
 * @param n Number of bytes to erase.
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 *        areas must not overlap.
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return A pointer to dest.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 *        areas may overlap.
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return A pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Scans the initial n bytes of the memory area pointed to by s for the
 *        first instance of c.
 * @param s Pointer to the memory area.
 * @param c The character to search for.
 * @param n Number of bytes to scan.
 * @return A pointer to the matching byte or NULL if the character does not
 *         occur in the given memory area.
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes (each interpreted as unsigned char) of the
 *        memory areas s1 and s2.
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n Number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero if the first n
 *         bytes of s1 is found, respectively, to be less than, to match, or
 *         be greater than the first n bytes of s2.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each
 *        and returns a pointer to the allocated memory. The memory is set to
 *        zero.
 * @param nmemb Number of elements.
 * @param size Size of each element.
 * @return A pointer to the allocated memory.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/* ========================================================================== */
/*                            STRING MANIPULATION                             */
/* ========================================================================== */

/**
 * @brief Calculates the length of the string pointed to by s, excluding the
 *        terminating null byte.
 * @param s The string to measure.
 * @return The number of bytes in the string s.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Copies up to size - 1 characters from the NUL-terminated string src
 *        to dst, NUL-terminating the result.
 * @param dest The destination buffer.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string it tried to create (length of src).
 */
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Appends the NUL-terminated string src to the end of dst. It will
 *        append at most size - strlen(dst) - 1 bytes, NUL-terminating the
 *        result.
 * @param dst The destination buffer.
 * @param src The source string.
 * @param size The size of the destination buffer.
 * @return The total length of the string it tried to create (initial length
 *         of dst + length of src).
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Returns a pointer to the first occurrence of the character c in the
 *        string s.
 * @param s The string to search.
 * @param c The character to search for.
 * @return A pointer to the matched character or NULL if the character is not
 *         found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Returns a pointer to the last occurrence of the character c in the
 *        string s.
 * @param s The string to search.
 * @param c The character to search for.
 * @return A pointer to the matched character or NULL if the character is not
 *         found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Compares the two strings s1 and s2. It compares not more than n
 *        characters.
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if s1 (or the
 *         first n bytes thereof) is found, respectively, to be less than, to
 *         match, or be greater than s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated string little in
 *        the string big, where not more than len characters are searched.
 * @param big The string to search in.
 * @param little The string to search for.
 * @param len The maximum number of characters to search.
 * @return A pointer to the beginning of the located substring, or NULL if the
 *         substring is not found.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Returns a pointer to a new string which is a duplicate of the string
 *        s.
 * @param s The string to duplicate.
 * @return A pointer to the duplicated string.
 */
char	*ft_strdup(const char *s);

/**
 * @brief Allocates and returns a substring from the string 's'.
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates and returns a new string, which is the result of the
 *        concatenation of 's1' and 's2'.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates and returns a copy of 's1' with the characters specified in
 *        'set' removed from the beginning and the end of the string.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates and returns an array of strings obtained by splitting 's'
 *        using the character 'c' as a delimiter. The array must end with a
 *        NULL pointer.
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split. NULL if the
 *         allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Applies the function 'f' to each character of the string 's', and
 *        passing its index as first argument to create a new string passed
 *        on successive applications of 'f'.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of 'f'.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function 'f' on each character of the string passed as
 *        argument, passing its index as first argument. Each character is
 *        passed by address to 'f' to be modified if necessary.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ========================================================================== */
/*                              TYPE CONVERSION                               */
/* ========================================================================== */

/**
 * @brief Converts the initial portion of the string pointed to by nptr to int.
 * @param nptr The string to convert.
 * @return The converted value.
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Allocates and returns a string representing the integer received as
 *        an argument. Negative numbers must be handled.
 * @param n The integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int n);

/* ========================================================================== */
/*                             FILE DESCRIPTORS                               */
/* ========================================================================== */

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 * @param c The character to output.
 * @return The number of bytes written.
 */
int		ft_putchar_fd(char c);

/**
 * @brief Outputs the string 's' to the given file descriptor.
 * @param s The string to output.
 * @return The number of bytes written.
 */
int		ft_putstr_fd(char *s);

/**
 * @brief Outputs the string 's' to the given file descriptor followed by a
 *        newline.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer 'n' to the given file descriptor.
 * @param n The integer to output.
 * @return The number of bytes written.
 */
int		ft_putnbr_fd(int n);

/* ========================================================================== */
/*                                LINKED LISTS                                */
/* ========================================================================== */

/**
 * @brief Allocates and returns a new node. The member variable 'content' is
 *        initialized with the value of the parameter 'content'. The variable
 *        'next' is initialized to NULL.
 * @param content The content to create the new node with.
 * @return The new node.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds the node 'new' at the beginning of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The node to add.
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
 * @param new The node to add.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter a node and frees the memory of the node's
 *        content using the function 'del' given as a parameter and free the
 *        node. The memory of 'next' must not be freed.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given node and every successor of that node,
 *        using the function 'del' and free(3). Finally, the pointer to the
 *        head of the list must be set to NULL.
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content.
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
 * @param del The address of the function used to delete the content.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
