/*Assignement name : n_queens

Expected files : *.c *.h

Allowed functions : atoi, fprintf, write, calloc, malloc, free, realloc, stdout, stderr

-------------------------------------------------------------------------

Write a program that will print all the solutions to the n queens problem
for a n given as argument.
We will not test with negative values.
The order of the solutions is not important.

You will display the solutions under the following format :
<p1> <p2> <p3> ... \n
where pn are the line index of the queen in each colum starting from 0.

For example this should work :
$> ./n_queens 2 | cat -e

$> ./n_queens 4 | cat -e
1 3 0 2$
2 0 3 1$

$> ./n_queens 7 | cat -e
0 2 4 6 1 3 5$
0 3 6 2 5 1 4$
etc...*/

/*void backtrack(parameters...)
{
	if (end solutions conditions)
		{print solution;
		return;}
	for (every option posible)
	{
		if (is valid){
			aply option;
			backtrack(step+1,...);
			undo option;
		}
	}
}*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int is_alive(int *sol, int pos)
{
	for(int i=0; i < pos; i++)
	{
		if (sol[i] == sol[pos])
			return (0);
		if(ft_abs(i - pos) == ft_abs(sol[i] - sol[pos]))
			return (0);
	}
	return(1);
}

void	backtrack(int pos, int *sol, int size)
{
	if (pos == size)
	{
		for(int i=0; i < size; i++){
			if (i < size -1)
				fprintf(stdout, "%d ", sol[i]);
			else
				fprintf(stdout, "%d\n", sol[i]);
		}
		return;
	}
	for (int i =0; i < size; i++){
		sol[pos] = i;
		if (is_alive(sol, pos))
			backtrack(pos + 1, sol, size);
	}
}

int main(int argc, char**argv)
{
	if (argc != 2)
		return(1);
	int size = atoi(argv[1]);
	if (size < 4)
	{
		fprintf(stdout, "\n");
		return (0);
	}
	int *sol = calloc(sizeof(int), size);
	backtrack(0, sol, size);
	return(0);
}