#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int	validation(int *table, int pos, int val)
{
	for (int i = 0; i < pos; i++)
	{
		if (val == table[i])
			return (0);
		if ((val - pos) == table[i] - i)
			return (0);
		if ((val + pos) == table[i] + i)
			return (0);
	}
	return (1);
}

void n_queen(int val, int pos, int size, int *table)
{
	if (pos == size)
	{
		for (int i = 0; i < size; i++)
		{
			fprintf(stdout, "%d", table[i]);
			if (i == size - 1)
				fprintf(stdout, "\n");
		}
		return ;
	}
	while (val < size)
	{
		if(validation(table, pos, val))
		{
			table[pos] = val;
			n_queen(0, pos + 1, size, table);
		}
		val++;
	}
	return ;
}

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	int size = atoi(av[1]);
	int table[size];
	n_queen(0, 0, size, table);
	return (0);

}
