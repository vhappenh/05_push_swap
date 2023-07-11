/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:55:19 by vhappenh          #+#    #+#             */
/*   Updated: 2022/10/28 11:21:55 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;

	if (*lst == NULL || lst == NULL || del == NULL)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		*lst = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = *lst;
	}
	*lst = NULL;
}
