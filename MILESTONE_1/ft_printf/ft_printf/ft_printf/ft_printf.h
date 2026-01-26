/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:46:39 by unovo-ru          #+#    #+#             */
/*   Updated: 2026/01/22 19:46:46 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

/* ========================================================================== */
/*                              CORE FUNCTION                                 */
/* ========================================================================== */

/**
 * @brief Produces output according to a format.
 * @param input The string format.
 * @param ... The values to format.
 * @return The number of characters printed (excluding the null byte used to end
 *         output to strings).
 */
int	ft_printf(char const *input, ...);

/* ========================================================================== */
/*                             INTERNAL LOGIC                                 */
/* ========================================================================== */

/**
 * @brief Determines the type of the argument and calls the appropriate
 *        function.
 * @param args The list of arguments.
 * @param c The format specifier character.
 * @return The number of characters printed.
 */
int	ft_var_type(va_list args, char c);

/* ========================================================================== */
/*                          FORMAT SPECIFIC HELPERS                           */
/* ========================================================================== */

/**
 * @brief Writes an unsigned integer to stdout.
 * @param n The unsigned integer to write.
 * @return The number of characters written.
 */
int	ft_put_unsig(unsigned int n);

/**
 * @brief Writes a pointer address in hexadecimal format to stdout. Handles the
 *        'nil' case for NULL pointers.
 * @param x The pointer to write.
 * @return The number of characters written.
 */
int	ft_hexa(void *x);

/**
 * @brief Writes a number in uppercase hexadecimal format to stdout.
 * @param num The number to write.
 * @return The number of characters written.
 */
int	ft_hexa_max(unsigned long long num);

/**
 * @brief Writes a number in lowercase hexadecimal format to stdout.
 * @param num The number to write.
 * @return The number of characters written.
 */
int	ft_hexa_min(unsigned long long num);

#endif
