/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:52:05 by vhappenh          #+#    #+#             */
/*   Updated: 2023/01/16 11:39:46 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen_pushswap(char **input)
{
	int	i;

	i = 0;
	while (input[i])
		i++;
	return (i);
}

int	ft_free_pushswap(t_list *a_stack, char **input)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (input)
	{
		while (input[i])
		{
			free (input[i]);
			i++;
		}
		free (input);
	}
	if (a_stack)
	{
		while (a_stack)
		{
			temp = a_stack;
			a_stack = a_stack->next;
			free(temp);
		}
		free (a_stack);
	}
	return (1);
}
