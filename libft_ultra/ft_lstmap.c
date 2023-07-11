/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 09:36:18 by vhappenh          #+#    #+#             */
/*   Updated: 2022/10/28 11:22:27 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*temp;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	ptr = malloc(sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	ptr->content = f(lst->content);
	if (ptr->content == NULL)
		ft_lstclear(&ptr, del);
	temp = ptr;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp->next = (t_list *)malloc(sizeof(t_list));
		if (temp->next == NULL)
			return (NULL);
		temp = temp->next;
		temp->content = f(lst->content);
		if (temp->content == NULL)
			ft_lstclear(&ptr, del);
	}
	temp->next = NULL;
	return ((t_list *)ptr);
}
