/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 09:43:59 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/15 09:50:36 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char res = 0;

	while(i > 0)
	{
		res = (res << 1) | (octet & 1);
		octet >>= 1;
		i--;
	}
	return (res);
}


