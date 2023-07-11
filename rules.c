/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:18:25 by vhappenh          #+#    #+#             */
/*   Updated: 2023/01/09 10:02:41 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a_stack)
{
	t_list	*temp;

	if ((*a_stack)->next == NULL || *a_stack == NULL)
		return ;
	temp = *a_stack;
	*a_stack = temp->next;
	temp->next = (*a_stack)->next;
	(*a_stack)->next = temp;
	write(1, "sa\n", 3);
}

void	pa(t_list **a_stack, t_list **b_stack)
{
	t_list	*temp;

	if (*b_stack == NULL)
		return ;
	temp = *b_stack;
	*b_stack = (*b_stack)->next;
	ft_lstadd_front(a_stack, temp);
	write(1, "pa\n", 3);
}

void	pb(t_list **a_stack, t_list **b_stack)
{
	t_list	*temp;

	if (*a_stack == NULL)
		return ;
	temp = *a_stack;
	*a_stack = (*a_stack)->next;
	ft_lstadd_front(b_stack, temp);
	write(1, "pb\n", 3);
}

void	ra(t_list **a_stack)
{
	t_list	*last;
	t_list	*temp;

	if (!(*a_stack)->next)
		return ;
	last = *a_stack;
	temp = *a_stack;
	while (last->next)
		last = last->next;
	*a_stack = temp->next;
	last->next = temp;
	last->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rra(t_list **a_stack)
{
	t_list	*last;
	t_list	*temp;

	if (!(*a_stack)->next)
		return ;
	last = *a_stack;
	while (last->next->next)
		last = last->next;
	temp = last->next;
	last->next->next = *a_stack;
	last->next = NULL;
	*a_stack = temp;
	write(1, "rra\n", 4);
}
