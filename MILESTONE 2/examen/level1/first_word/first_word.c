/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:49:27 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/09 17:04:16 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void first_word(char *s)
{
	int i = 0;
	while (s[i] <= 32)
		i++;
	while (s[i] > 32)
	{
		if (s[i] < 33)
			break;
		write(1, &s[i], 1);
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		first_word(av[1]);
		write (1, "\n", 1);
	}
	else
		write (1, "\n", 1);
}
