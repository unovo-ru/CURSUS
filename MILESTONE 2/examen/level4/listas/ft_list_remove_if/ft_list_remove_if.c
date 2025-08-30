/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:21:11 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/07/14 19:33:15 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if(begin_list == NULL || *begin_list == NULL)
		return ;
	t_list *tmp = *begin_list;
	if (cmp(tmp->data, data_ref) == 0)
	{
		*begin_list = tmp->next;
		free(temp);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		tmp = *begin_list;
		ft_list_remove_if(&tmp->next, data_ref_cmp);
	}

}
