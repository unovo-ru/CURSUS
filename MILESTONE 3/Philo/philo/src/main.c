/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 13:07:59 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/10/16 11:49:50 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (parse_arg(ac, av) < 0)
		print_error(parse_arg(ac, av));
	else
		printf("\nAGUANTE RIVER 9/12/18 :)\n\n");
	return (0);
}
