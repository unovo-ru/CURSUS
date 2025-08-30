/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:25:09 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/23 09:33:42 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int i = 7;
	while (i >= 0)
	{
		if ((octet >> i) & 1)
			write (1, "1", 1);
		else
			write (1, "0", 1);
		i--;
	}
}

int main(void)
{
    unsigned char test = 42; // 42 en binario: 00101010
    print_bits(test);
    write(1, "\n", 1);

    test = 255; // 11111111
    print_bits(test);
    write(1, "\n", 1);

    test = 0; // 00000000
    print_bits(test);
    write(1, "\n", 1);

    return 0;
}
