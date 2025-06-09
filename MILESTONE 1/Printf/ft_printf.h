/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 20:46:39 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/21 21:03:50 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(char const *input, ...);
int	ft_var_type(va_list args, char c);
int	ft_put_unsig(unsigned int n);
int	ft_hexa(void *x);
int	ft_hexa_max(unsigned long long num);
int	ft_hexa_min(unsigned long long num);

#endif
