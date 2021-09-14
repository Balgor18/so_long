/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcatinau <fcatinau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 20:43:18 by fcatinau          #+#    #+#             */
/*   Updated: 2021/07/29 19:26:59 by fcatinau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	a(t_list *new_lst, t_list *new_elem, t_list *lst)
{
	new_lst = new_elem;
	lst = lst->next;
}

void	clear(t_list *lst, t_list *new_lst, void (*d)(void *))
{
	ft_lstclear(&lst, d);
	ft_lstclear(&new_lst, d);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	new_lst = NULL;
	if (!lst || !f)
		return (NULL);
	new_elem = ft_lstnew(f(lst->content));
	if (!new_elem)
	{
		ft_lstclear(&lst, d);
		return (NULL);
	}
	a(new_lst, new_elem, lst);
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (!new_elem)
		{
			clear(lst, new_lst, d);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_elem);
	}
	return (new_lst);
}
