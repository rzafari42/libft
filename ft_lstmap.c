/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rzafari <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 00:05:11 by rzafari           #+#    #+#             */
/*   Updated: 2019/10/22 16:31:41 by rzafari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n;
	t_list	*b;

	if (!lst || !*f || !del)
		return (NULL);
	b = NULL;
	while (lst)
	{
		if (!(n = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&b, del);
			return (NULL);
		}
		ft_lstadd_back(&b, n);
		lst = lst->next;
	}
	return (b);
}
