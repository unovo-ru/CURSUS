/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:46:39 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/22 17:54:55 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* ========================================================================== */
/*                              STRUCTURES                                    */
/* ========================================================================== */

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ========================================================================== */
/*                 CHARACTER VALIDATION & CONVERSION                          */
/* ========================================================================== */

/**
 * @brief Checks if character is alphabetic (a-z, A-Z).
 * @param c Character to check (as int).
 * @return 1 if alphabetic, 0 otherwise.
 */
int			ft_isalpha(int c);

/**
 * @brief Checks if character is a digit (0-9).
 * @param c Character to check (as int).
 * @return 1 if digit, 0 otherwise.
 */
int			ft_isdigit(int c);

/**
 * @brief Checks if character is alphanumeric (a-z, A-Z, 0-9).
 * @param c Character to check (as int).
 * @return 1 if alphanumeric, 0 otherwise.
 */
int			ft_isalnum(int c);

/**
 * @brief Checks if character is within the ASCII set (0-127).
 * @param c Character to check (as int).
 * @return 1 if ASCII, 0 otherwise.
 */
int			ft_isascii(int c);

/**
 * @brief Checks if character is printable (including space).
 * @param c Character to check (as int).
 * @return 1 if printable, 0 otherwise.
 */
int			ft_isprint(int c);

/**
 * @brief Converts a lower-case letter to upper-case.
 * @param c The character to convert.
 * @return The upper-case equivalent or c if not lower-case.
 */
int			ft_toupper(int c);

/**
 * @brief Converts an upper-case letter to lower-case.
 * @param c The character to convert.
 * @return The lower-case equivalent or c if not upper-case.
 */
int			ft_tolower(int c);

/* ========================================================================== */
/*                        STRING MANIPULATION                                 */
/* ========================================================================== */

/**
 * @brief Calculates the length of the string s.
 * @param s The string to measure.
 * @return The number of bytes in the string s.
 */
size_t		ft_strlen(const char *s);

/**
 * @brief Copies up to size - 1 characters from src to dest, NUL-terminating.
 * @param dest Destination buffer.
 * @param src Source string.
 * @param size Size of the destination buffer.
 * @return The total length of the string it tried to create.
 */
size_t		ft_strlcpy(char *dest, const char *src, size_t size);

/**
 * @brief Appends src to dest, ensuring NUL-termination.
 * @param dst Destination buffer.
 * @param src Source string.
 * @param size Size of the destination buffer.
 * @return The total length of the string it tried to create.
 */
size_t		ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Locates the first occurrence of c in the string s.
 * @param s The string to search.
 * @param c The character to search for.
 * @return Pointer to the located character or NULL.
 */
char		*ft_strchr(const char *s, int c);

/**
 * @brief Locates the last occurrence of c in the string s.
 * @param s The string to search.
 * @param c The character to search for.
 * @return Pointer to the located character or NULL.
 */
char		*ft_strrchr(const char *s, int c);

/**
 * @brief Compare the first n bytes of strings s1 and s2.
 * @param s1 First string.
 * @param s2 Second string.
 * @param n Maximum number of bytes to compare.
 * @return Integer less than, equal to, or greater than zero.
 */
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Locates the first occurrence of little in big, searching at most len.
 * @param big The string to be searched.
 * @param little The string to search for.
 * @param len Maximum number of characters to search.
 * @return Pointer to the beginning of the located substring, or NULL.
 */
char		*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Returns a pointer to a new string which is a duplicate of s.
 * @param s The string to duplicate.
 * @return Pointer to the duplicated string.
 */
char		*ft_strdup(const char *s);

/**
 * @brief Allocates and returns a substring from the string 's'.
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string 's'.
 * @param len The maximum length of the substring.
 * @return The substring.
 */
char		*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates and returns a new string, concatenation of 's1' and 's2'.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string.
 */
char		*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates and returns a copy of 's1' with characters in 'set' removed.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string.
 */
char		*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates and returns an array of strings obtained by splitting 's'.
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 */
char		**ft_split(char const *s, char c);

/**
 * @brief Creates a new string by applying 'f' to each character of 's'.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of 'f'.
 */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function 'f' to each character of the string 's'.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ========================================================================== */
/*                        MEMORY MANIPULATION                                 */
/* ========================================================================== */

/**
 * @brief Fills the first n bytes of the memory area s with zeros.
 * @param s Pointer to the memory area.
 * @param n Number of bytes to set to zero.
 */
void		ft_bzero(void *s, size_t n);

/**
 * @brief Allocates memory for an array of nmemb elements of size bytes each.
 * @param nmemb Number of elements.
 * @param size Size of each element.
 * @return Pointer to the allocated memory.
 */
void		*ft_calloc(size_t nmemb, size_t size);

/**
 * @brief Scans the initial n bytes of s for the first instance of c.
 * @param s Pointer to the memory area.
 * @param c Value to search for.
 * @param n Number of bytes to search.
 * @return Pointer to the matching byte or NULL.
 */
void		*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of the memory areas s1 and s2.
 * @param s1 Pointer to the first memory area.
 * @param s2 Pointer to the second memory area.
 * @param n Number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero.
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copies n bytes from memory area src to memory area dest.
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to dest.
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from src to dest, handling overlapping memory.
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to dest.
 */
void		*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Fills the first n bytes of memory area s with the constant byte c.
 * @param s Pointer to the memory area.
 * @param c Byte to fill with.
 * @param n Number of bytes to fill.
 * @return Pointer to the memory area s.
 */
void		*ft_memset(void *s, int c, size_t n);

/* ========================================================================== */
/*                        NUMERIC / ARITHMETIC                                */
/* ========================================================================== */

/**
 * @brief Converts a string to an integer.
 * @param nptr The string to convert.
 * @return The integer value.
 */
int			ft_atoi(const char *nptr);

/**
 * @brief Converts a string to a long integer.
 * @param str The string to convert.
 * @return The long integer value.
 */
long		ft_atol(char *str);

/**
 * @brief Converts an integer to a string.
 * @param n The integer to convert.
 * @return The string representation of the integer.
 */
char		*ft_itoa(int n);

/* ========================================================================== */
/*                        FILE DESCRIPTOR OUPUT                               */
/* ========================================================================== */

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 * @param c The character to output.
 * @param fd The file descriptor.
 */
void		ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor.
 * @param s The string to output.
 * @param fd The file descriptor.
 */
void		ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string 's' followed by a newline to the file descriptor.
 * @param s The string to output.
 * @param fd The file descriptor.
 */
void		ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer 'n' to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor.
 */
void		ft_putnbr_fd(int n, int fd);

/* ========================================================================== */
/*                             LINKED LISTS                                   */
/* ========================================================================== */

/**
 * @brief Allocates and returns a new element.
 * @param content The content to create the new element with.
 * @return The new element.
 */
t_list		*ft_lstnew(void *content);

/**
 * @brief Adds the element 'new' at the beginning of the list.
 * @param lst Address of pointer to the first link of a list.
 * @param new The element to add.
 */
void		ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of elements in a list.
 * @param lst The beginning of the list.
 * @return The length of the list.
 */
int			ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of the list.
 * @param lst The beginning of the list.
 * @return The last element of the list.
 */
t_list		*ft_lstlast(t_list *lst);

/**
 * @brief Adds the element 'new' at the end of the list.
 * @param lst Address of pointer to the first link of a list.
 * @param new The element to add.
 */
void		ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Deletes and frees the given element using 'del'.
 * @param lst The element to free.
 * @param del The function used to delete the content.
 */
void		ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given element and every successor.
 * @param lst Address of pointer to an element.
 * @param del The function used to delete the content.
 */
void		ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list and applies 'f' to the content of each element.
 * @param lst Address of pointer to an element.
 * @param f The function used to iterate on the list.
 */
void		ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list and applies 'f' to content to create a new list.
 * @param lst Address of pointer to an element.
 * @param f The function used to iterate.
 * @param del The function used to delete content if needed.
 * @return The new list.
 */
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ========================================================================== */
/*                             GET NEXT LINE                                  */
/* ========================================================================== */

/**
 * @brief Reads a line from a file descriptor.
 * @param fd The file descriptor to read from.
 * @return The line read, or NULL.
 */
char		*get_next_line(int fd);

/**
 * @brief GNL Helper: Allocates and returns a substring.
 */
char		*gnl_substr(char const *s, unsigned int start,
				size_t len, int flag);

/**
 * @brief GNL Helper: Concatenates two strings.
 */
char		*gnl_strjoin(char *s1, char *s2);

/* ========================================================================== */
/*                                FT_PRINTF                                   */
/* ========================================================================== */

/**
 * @brief Formats and prints data to the standard output.
 * @param input The format string.
 * @param ... The values to format.
 * @return The number of characters printed.
 */
int			ft_printf(char const *input, ...);

/**
 * @brief Printf Helper: Determines parsing type.
 */
int			ft_var_type(va_list args, char c);

/**
 * @brief Printf Helper: Prints pointer address in hex.
 */
int			ft_hexa(void *y);

/**
 * @brief Printf Helper: Prints uppercase hex.
 */
int			ft_hexa_max(unsigned long long num);

/**
 * @brief Printf Helper: Prints lowercase hex.
 */
int			ft_hexa_min(unsigned long long num);

/**
 * @brief Printf Helper: Prints unsigned int.
 */
int			ft_put_unsig(unsigned int n);

/**
 * @brief Printf Helper: Output char to fd.
 */
int			pf_putchar_fd(char c);

/**
 * @brief Printf Helper: Output number to fd.
 */
int			pf_putnbr_fd(int n);

/**
 * @brief Printf Helper: Output string to fd.
 */
int			pf_putstr_fd(char *s);

#endif
