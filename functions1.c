/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:10:36 by vhappenh          #+#    #+#             */
/*   Updated: 2023/01/13 10:37:12 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi_long(const char *nptr)
{
	long			sum;
	int				i;
	int				sign;

	i = 0;
	sum = 0;
	sign = 1;
	while ((nptr[i] <= 13 && nptr[i] > 8) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	if (!(nptr[i] >= '0' && nptr[i] <= '9'))
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = sum * 10 + nptr[i] - '0';
		i++;
	}
	return (sum * sign);
}

t_list	*ft_lstnew_pushswap(long content)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return ((t_list *)ptr);
}

int	ft_stack_sorted(t_list *a_stack, t_list *b_stack)
{
	if (b_stack != NULL)
		return (1);
	while (a_stack->next)
	{
		if (a_stack->content < a_stack->next->content)
			a_stack = a_stack->next;
		else
			return (1);
	}
	return (0);
}

void	ft_sort_index(char **index, int max, t_list **a_stack)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < max)
	{
		j = 0;
		while (j < (max - 1))
		{
			if (ft_atoi_long(index[j]) > ft_atoi_long(index[j + 1]))
			{
				temp = index[j];
				index[j] = index[j + 1];
				index[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	ft_lst_index(index, max, a_stack);
}

void	ft_lst_index(char **index, int max, t_list **a_stack)
{
	int		i;
	t_list	*temp;

	temp = *a_stack;
	while (*a_stack)
	{
		i = 0;
		while (i < max)
		{
			if ((*a_stack)->content == ft_atoi_long(index[i]))
				(*a_stack)->index = i;
			i++;
		}
		*a_stack = (*a_stack)->next;
	}
	*a_stack = temp;
}
