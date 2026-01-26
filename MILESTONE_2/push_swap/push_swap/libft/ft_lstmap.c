/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unovo-ru <unovo-ru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 21:14:03 by unovo-ru          #+#    #+#             */
/*   Updated: 2025/05/15 21:28:40 by unovo-ru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*h;
	t_list	*mod;
	t_list	*mynode;

	if (!lst)
		return (NULL);
	h = NULL;
	while (lst)
	{
		mod = f(lst->content);
		mynode = ft_lstnew(mod);
		if (!mynode)
		{
			del(mod);
			ft_lstclear(&h, del);
			return (NULL);
		}
		ft_lstadd_back(&h, mynode);
		lst = lst->next;
	}
	return (h);
}
