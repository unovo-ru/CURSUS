/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:20:44 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/23 09:24:13 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char   reverse_bits(unsigned char octet)
{
	int i = 8;
	const char res;
	while (i > 0)
	{
		res = (res << 1) | (octet & 1);
		octet >>= 1;
		i--;
	}
}
