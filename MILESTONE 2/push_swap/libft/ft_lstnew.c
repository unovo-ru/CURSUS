/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:58:11 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/08/12 15:20:17 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*mynodo;

	if (!content)
		return (NULL);
	mynodo = malloc(sizeof(t_list));
	if (!mynodo)
		return (NULL);
	mynodo->content = content;
	mynodo->next = NULL;
	return (mynodo);
}
