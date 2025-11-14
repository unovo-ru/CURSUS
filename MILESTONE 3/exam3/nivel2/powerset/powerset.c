#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void	print_list(int *list, int size)
{
	int i = 0;

	if (!size)
		return ;
	while (i < size)
	{
		if (i < size - 1)
			printf("%d ", list[i]);
		else
			printf("%d", list[i]);
		i++;
	}
	printf("\n");
}

int	*ft_create_list(char **av, int size)
{
	int *res;
	int i = 0;

	res = calloc(size, sizeof(int));
	if (!res)
		return (NULL);
	while (i < size && av[i])
	{
		res[i] = atoi(av[i]);
		i++;
	}
	return (res);
}

void	track_powerset(int *list, int index, int *new_list, int new_list_size, int new_value, int target, int size)
{
	if (index == size)
	{
		// if (new_value == target)
		print_list(new_list, new_list_size);
		return ;
	}
	new_list[new_list_size] = list[index];
	track_powerset(list, index + 1, new_list, new_list_size + 1, new_value + list[index], target, size);
	track_powerset(list, index + 1, new_list, new_list_size, new_value, target, size);
}

/**
 * 
 * [ list ] = combinacion recibida por argumentos
 * [ index ] = iterador para armar la combinacion de numeros
 * [ new_list ] = combinacion nueva para imprimir por pantalla
 * [ new_list_size ] = tamaño de la nueva combinacion
 * [ new_value ] = suma de numeros que se va incrementando en cada llamada
 * [ target ] = el numero final al que la suma <new_value> tiene que llegar para imprimirla
 * [ size ] = tamaño de la lista recibida por parametros
 * 
*/
/* 
void	track_powerset(int *list, int index, int *new_list, int new_list_size, int new_value, int target, int size)
{
	En el caso de que [ INDEX ] llegue a ser [ SIZE ]
	Cortamos el proceso
	if (index == size)
	{
		En el caso de que [ NEW_VALUE ] sea exactamente igual a [ TARGET ]
		Se imprime la combinacion (se logro la combinacion correcta)
		if (new_value == target)
			print_list(new_list, new_list_size);
		(no se consiguio la combinacion correcta)
		return ;
	}
	new_list[new_list_size] = list[index];
	Llamado en el que incluimos el numero de la iteracion
	Iteramos [ INDEX ] | Incrementamos el [ NEW_LIST_SIZE ] | sumamos el numero que metimos en la combinacion con [ NEW_VALUE ] 
	track_powerset(list, index + 1, new_list, new_list_size + 1, new_value + list[index], target, size);
	Llamado en el que NO incluimos el numero
	Incrementamos el [ INDEX ]
	track_powerset(list, index + 1, new_list, new_list_size, new_value, target, size);
}
 */

int main(int ac, char **av)
{
	int target = atoi(av[1]);
	int size = ac - 2;
	int *list;
	int *new_list;

	if (ac < 3)
		return (-1);
	list = ft_create_list(av+2, size);
	if (!list)
		return (-1);
	new_list = malloc(size * sizeof(int));
	if (!new_list)
		return (-1);
	track_powerset(list, 0, new_list, 0, 0, target, size);
	free(list);
	free(new_list);
	return (0);
}
