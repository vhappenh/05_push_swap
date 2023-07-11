/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:40:49 by vhappenh          #+#    #+#             */
/*   Updated: 2023/01/16 14:11:22 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a_stack;
	t_list	*b_stack;
	char	**input;
	int		length;

	input = &(argv[1]);
	a_stack = NULL;
	b_stack = NULL;
	if (argc <= 1)
		return (1);
	input = ft_input_prepare(input);
	if (input == NULL)
		return (write(2, "Error\n", 6));
	length = ft_strlen_pushswap(input);
	if (length <= 1)
		return (ft_free_pushswap(NULL, input));
	if (ft_input_to_list(&a_stack, length, input))
		return (ft_free_pushswap(NULL, input));
	ft_push_swap(&a_stack, &b_stack, length);
	ft_free_pushswap(a_stack, input);
	return (0);
}
