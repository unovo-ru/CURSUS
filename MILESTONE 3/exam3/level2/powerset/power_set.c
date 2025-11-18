/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:48:53 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/11/11 12:23:41 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	sum;
int	size;
int	*nums;

void	print_subset(int subsize, int *subset)
{
	for (int i = 0; i < subsize; i++)
	{
		printf("%d", subset[i]);
		if (i < subsize - 1)
			printf(" ");
	}
	printf("\n");
}

int	calc_sum(int subsize, int *subset)
{
	int actual_sum = 0;
	for (int i = 0; i < subsize; i++)
		actual_sum += subset[i];
	return (actual_sum);
}

void	solve(int subsize, int current, int *subset)
{
	if (current == size)
	{
		if (calc_sum(subsize, subset) == sum && subsize != 0)
			print_subset(subsize, subset);
		return ;
	}
	solve(subsize, current + 1, subset);
	subset[subsize] = nums[current];
	solve(subsize + 1, current, subset);
}

int main(int ac, char **av)
{
	if (ac <= 2)
	{
		printf("\n");
		return 0;
	}
	sum = atoi(av[1]);
	size = ac - 2;
	nums = malloc(sizeof(int) * size);
	if (!nums)
		return 1;
	int *subset = calloc(sizeof(int), size);
	if (!subset)
	{
		free(nums);
		return 1;
	}
	for (int i = 0; i < size; i++)
		nums[i] = atoi(av[i + 2]);
	int subsize = 0;
	int current = 0;
	solve(subsize, current, subset);
	free(nums);
	free(subset);
	return 0;
}


