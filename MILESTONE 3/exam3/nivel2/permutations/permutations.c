// #include "stdio.h"
// #include "stdlib.h"
// #include "unistd.h"

// int ft_strlen(char *s)
// {
// 	int i = 0;
// 	while (*s)
// 	{
// 		s++;
// 		i++;
// 	}
// 	return (i);
// }

// void	pos(char *av, char *aux, int *used, int i, int j, int size)
// {
// 	if (j == size)
// 	{
// 		puts(aux);
// 		return ;
// 	}
// 	while (i < size)
// 	{
// 		if (!used[i])
// 		{
// 			used[i] = 1;
// 			aux[j] = av[i];
// 			pos(av, aux, used, 0, j + 1, size);
// 			used[i] = 0;
// 		}
// 		i++;
// 	}
// }

// /**
//  * [ av ] = string recibido por paramtros. 
//  * - Ej: A B C
//  * [ aux ] = string creado para imprimir las combinaciones por pantalla
//  * - Ej: A B C
//  * 		 A C B
//  * 		 B A C
//  * 		 B C A
//  * 		 C B A
//  * 		 C A B
//  * [ used ] = array de int que funciona para saber que caracter se uso
//  * [ i ] = iterador del array principal
//  * [ j ] = iterador del array para las combinaciones
//  * [ size ] = tamaño del array principal
//  */
// // void	pos(char *av, char *aux, int *used, int i, int j, int size)
// // {
// 	// Si el <ITERADOR> del string de combinaciones es igual al <TAMAÑO>
// 	// Lo ESCRIBE y CORTA
// 	// if (j == size)
// 	// {
// 	// 	puts(aux);
// 	// 	return ;
// 	// }
// 	// Bucle para probar todos los caracteres posibles
// 	// Si el caracter no esta usado:
// 	// - Se marca esa posicion en 1 (ya usado)
// 	// - Se le agrega a AUX
// 	// - Se vuelve a llamar a la funcion con:
// 	//		- av
// 	// 		- aux
// 	// 		- used
// 	//		- i = Desde 0 para probar todos los caracteres 		
// 	//		- j = Desde la proxima posicion para no sobreescribir el caracter 		
// 	//		- size
// 	// - Se marca la posicion en 0 (sin usar) para probar otras combinaciones
// // 	while (i < size)
// // 	{
// // 		if (!used[i])
// // 		{
// // 			used[i] = 1;
// // 			aux[j] = av[i];
// // 			pos(av, aux, used, 0, j + 1, size);
// // 			used[i] = 0;
// // 		}
// // 		i++;
// // 	}
// // }

// int main(int ac, char **av)
// {
// 	int size = ft_strlen(av[1]); 
// 	int *used;
// 	char *aux;

// 	if (ac < 2)
// 		return (0);
// 	aux = malloc(size + 1 * sizeof(char));
// 	if (!aux)
// 		return (1);
// 	aux[size + 1] = '\0';
// 	used = calloc(size, sizeof(int));
// 	if (!used)
// 	{
// 		free(aux);
// 		return (1);
// 	}
// 	pos(av[1], aux, used, 0, 0, ft_strlen(av[1]));
// 	free(aux);
// 	free(used);
// 	return (0);
// }

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

int ft_strlen(char *s)
{
	int i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

void bubble_sort(char *av)
{
	int i = 0, j;
	char aux;

	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (av[i] > av[j])
			{
				aux = av[i];
				av[i] = av[j];
				av[j] = aux;
			}
			j++;
		}
		i++;
	}
}

void	pos(char *av, char *aux, int *used, int i, int j, int size)
{
	if (j == size)
	{
		puts(aux);
		return ;
	}
	while (i < size)
	{
		if (!used[i])
		{
			used[i] = 1;
			aux[j] = av[i];
			pos(av, aux, used, 0, j + 1, size);
			used[i] = 0;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	int size = ft_strlen(av[1]); 
	int *used;
	char *aux;

	if (ac != 2)
		return (1);
	bubble_sort(av[1]);
	aux = malloc(size + 1 * sizeof(char));
	if (!aux)
		return (1);
	aux[size + 1] = '\0';
	used = calloc(size, sizeof(int));
	if (!used)
	{
		free(aux);
		return (1);
	}
	pos(av[1], aux, used, 0, 0, ft_strlen(av[1]));
	free(aux);
	free(used);
	return (0);
}
