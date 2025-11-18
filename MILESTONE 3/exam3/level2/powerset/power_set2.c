/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power_set2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 04:34:48 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/11/18 05:32:20 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int sum;
int size;
int *nums;

void print_sum(int subsize, int *subset)
{
	for (int i = 0; i < subsize; i++)
	{
		printf("%d", subset[i]);
		if (i < size - 1)
			printf(" ");
	}
	printf("\n");
}

int calculate(int subsize, int *subset)
{
	int actual_sum = 0;
	for (int i = 0; i < subsize; i++)
		actual_sum += subset[i];
	return (actual_sum);
}

void powerset(int subsize, int current, int *subset)
{
	if (current == size)
	{
		if (calculate(subsize, subset) == sum && subsize != 0)
			print_sum(subsize, subset);
		return ;
	}
	powerset(subsize, current + 1, subset);
	subset[subsize] = nums[current];
	powerset(subsize + 1, current, subset);
}

int main(int ac, char **av)
{
	if (ac <= 2)
	{
		printf("\n");
		return 0;
	}
//	int sum = atoi(av[1]);
	int size = ac - 2;
	int *nums = malloc(sizeof(int) * size);
	if (!nums)
		return 1;
	int *subset = calloc(sizeof(int), size);
	if (!subset)
	{
		free(nums);
		return 1;
	}
	int subsize = 0;
	int current = 0;
	for (int i = 0; i < size; i++)
		nums[i] = atoi(av[i + 2]);
	powerset(subsize, current, subset);
	
}
