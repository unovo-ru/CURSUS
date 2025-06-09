/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:58:11 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/14 18:23:53 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *data)
{
	t_list	*mynodo;

	mynodo = (t_list *)malloc(sizeof(t_list));
	if (!mynodo)
		return (NULL);
	mynodo->content = data;
	mynodo->next = NULL;
	return (mynodo);
}

int	main(void)
{
	char	*data = "hola";

	t_list *mynodo = ft_lstnew(data);
	printf ("%s\n", (char *)mynodo->content);
	free(mynodo);
	return (0);
}