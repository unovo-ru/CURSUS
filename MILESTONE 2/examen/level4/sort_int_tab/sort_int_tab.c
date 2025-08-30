/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:20:10 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/15 13:46:50 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i = 0;
	int temp;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}

}


/*
int main(int ac, char **av)
{
	int tab[ac - 1];
	int i = 0;

	if (ac == 1)
		return 0;
	while (++i < ac)
		tab[i - 1] = atoi(av[i]);
	sort_int_tab(tab, ac - 1);
	i = -1;
	while (++i < ac - 1)
		printf("%d\n", tab[i]);
	return 0;
}
*/
