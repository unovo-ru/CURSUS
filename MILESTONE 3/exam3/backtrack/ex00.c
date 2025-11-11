/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex00.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:50:58 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/11/11 16:00:49 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	backtrack(int arr[], int pos, int size)
{
	if (pos == size)
	{
		for (int i = 0; i < size; i++)
			printf("%d", arr[i]);
		printf("\n");
		return ;
	}
	for (int d = 1; d <= 4; d++)
	{
		arr[pos] = d;
		backtrack(arr, pos + 1, size);
	}
}

int	main(void)
{
	int arr[4];
	backtrack(arr, 0, 4);
	return 0;
}
