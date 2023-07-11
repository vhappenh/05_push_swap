/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 09:05:49 by vhappenh          #+#    #+#             */
/*   Updated: 2023/01/19 15:34:37 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_three(t_list **a_stack)
{
	if (((*a_stack)->index > (*a_stack)->next->index)
		&& ((*a_stack)->index < (*a_stack)->next->next->index))
		sa(a_stack);
	else if (((*a_stack)->index > (*a_stack)->next->index)
		&& ((*a_stack)->index > (*a_stack)->next->next->index)
		&& ((*a_stack)->next->index > (*a_stack)->next->next->index))
	{
		sa(a_stack);
		rra(a_stack);
	}
	else if (((*a_stack)->index > (*a_stack)->next->index)
		&& ((*a_stack)->next->index < (*a_stack)->next->next->index))
		ra(a_stack);
	else if (((*a_stack)->index < (*a_stack)->next->index)
		&& ((*a_stack)->index < (*a_stack)->next->next->index)
		&& ((*a_stack)->next->index > (*a_stack)->next->next->index))
	{
		sa(a_stack);
		ra(a_stack);
	}
	else
		rra(a_stack);
}

static int	ft_f_index(t_list *a_stack, int index)
{
	int	i;

	i = 0;
	while (a_stack)
	{
		if (a_stack->index == index)
			return (i);
		a_stack = a_stack->next;
		i++;
	}
	return (-1);
}

static void	ft_sort_four_or_five(t_list **a_stack, t_list **b_stack)
{
	int	i;

	i = 0;
	while (ft_stack_sorted(*a_stack, NULL))
	{
		if ((*a_stack)->index == i)
		{
			pb(a_stack, b_stack);
			i++;
		}
		else if (ft_f_index(*a_stack, i) == 4 || ft_f_index(*a_stack, i) == 3)
			rra(a_stack);
		else
			ra(a_stack);
		if (ft_lstsize(*a_stack) == 3)
			ft_sort_three(a_stack);
	}
	pa(a_stack, b_stack);
	pa(a_stack, b_stack);
}

static void	ft_sort_all(t_list **a_stack, t_list **b_stack, int length)
{
	int	temp;
	int	bits;
	int	i;

	bits = 0;
	while ((length - 1) >> bits)
		bits++;
	i = 0;
	while (i < bits)
	{
		temp = 0;
		while (temp < length)
		{
			if (((*a_stack)->index >> i) & 1)
				ra(a_stack);
			else
				pb(a_stack, b_stack);
			temp++;
		}
		while (*b_stack)
			pa(a_stack, b_stack);
		i++;
	}
}

void	ft_push_swap(t_list **a_stack, t_list **b_stack, int length)
{
	if (!ft_stack_sorted(*a_stack, *b_stack))
		return ;
	else if (length == 2 && ft_stack_sorted(*a_stack, *b_stack))
		sa(a_stack);
	else if (length == 3 && ft_stack_sorted(*a_stack, *b_stack))
		ft_sort_three(a_stack);
	else if ((length == 4 || length == 5)
		&& ft_stack_sorted(*a_stack, *b_stack))
		ft_sort_four_or_five(a_stack, b_stack);
	else
		ft_sort_all(a_stack, b_stack, length);
	return ;
}
