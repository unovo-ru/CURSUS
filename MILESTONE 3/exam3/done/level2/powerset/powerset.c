#include <stdio.h>
#include <stdlib.h>

// definir variables globales para evitar tener que pasar variables de un lado a otro
// define global variables to avoid having to pass variables around
int required_sum; // integer n
int size; // el tamaño del conjunto de enteros  //the size of the set of integers
int *nums; // el conjunto de números enteros  //the set of integers

// imprime el subconjunto, tomando su tamaño como parámetro
// (necesitamos llevar manualmente la cuenta del tamaño de un array de enteros)
// print the subset, taking its size as parameter
// (we need to manually keep track of the size of an integer array)
void	print_subset(int subsize, int *subset)
{
	for(int i = 0; i < subsize; i++)
	{
		printf("%d", subset[i]);
		if(i < subsize -1 ) // espacio final sólo si no es el último entero 
			printf(" ");
	}			//trailing space only if it's not the last integer
	printf("\n");
}

// calcular la suma real de un subconjunto dado
// calculate the actual sum of a given subset
int calcul_subset_sum(int subsize, int *subset)
{
	int actual_sum = 0;
	for (int i = 0; i < subsize; i++)
		actual_sum += subset[i];
	return actual_sum;
}

// función recursiva para generar todos los subconjuntos que sumen la suma requerida
// recursive function to generate all subsets that sum to the required sum
void solve(int subsize, int current_index, int *subset)
{	// Caso base: si hemos procesado todos los números del conjunto dado
	// Base case: if we've processed all numbers in the given set
	if (current_index == size)
	{
		// si la suma real del subconjunto cumple el requisito 
		// y el subconjunto no es un conjunto vacío
		// if the actual sum of subset meets the requirement 
		// and the subset is not an empty set
		if (calcul_subset_sum(subsize, subset) == required_sum && subsize != 0)
			print_subset(subsize, subset);
		return ;
	}
	// opción 1: no incluir el número actual
	// simplemente se mueve a la siguiente posición del índice
	// option 1: don't include current number
	// simply moves to next index position
	solve(subsize, current_index + 1, subset);

	// opción 2: incluir el número actual
	// añadir el número actual al subconjunto, incrementar el tamaño del subconjunto
	// option 2: include current number
	// add current number into the subset, increment subset size
	subset[subsize] = nums[current_index]; 
	solve(subsize + 1, current_index + 1, subset);
}

// NOTA: Los requerimientos reales de manejo de errores en el examen pueden ser diferentes!!!!!!!
// puede ser necesario comprobar si hay duplicados en el conjunto dado de enteros antes de llamar
// a la función solve()
// NOTE: The actual error handling requirements in the exam may be different!!!!!!!
// may need to check for duplicates in the given set of integers before calling solve() function
int main(int ac, char **av)
{
	// tratamiento de errores: sin argumentos; sólo la suma requerida y sin conjunto de enteros
	// error handling: no arguments; just the required sum and no integer set
	if (ac <= 2)
	{
		printf("\n");
        return 0;
	}
	// analizar la suma requerida
	// parse required sum
	required_sum = atoi(av[1]);
	// calcular el tamaño del conjunto de enteros
	// calculate size of the integer set
	size = ac - 2;
	nums = malloc(sizeof(int) * size);
	if (!nums)
		return 1;
	int *subset = calloc(size, sizeof(int));
	if (!subset)
	{
		free(nums);
		return 1;
	}
	// analizar conjunto de enteros
	// parse integer set
	for (int i = 0; i < size; i++)
		nums[i] = atoi(av[i + 2]); // a partir del tercer argv // starting from the third argv
	// inicializar el tamaño del subconjunto a 0
	// initialise subset size to 0
	int subsize = 0;
	int current_index = 0;
	solve(subsize, current_index, subset);
	free(nums);
	free(subset);
}
