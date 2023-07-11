/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:47:40 by vhappenh          #+#    #+#             */
/*   Updated: 2023/01/05 17:59:38 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_join_inputs(char *dest, char **src)
{
	int		i;
	char	*temp;

	i = 0;
	while (src[i] && src[i + 1])
	{
		temp = ft_strjoin(dest, " ");
		free (dest);
		if (temp == NULL)
			return (NULL);
		dest = ft_strjoin(temp, src[i + 1]);
		free (temp);
		if (dest == NULL)
			return (NULL);
		i++;
	}
	return (dest);
}

int	ft_check_for_doubles(char **input)
{
	int	i;
	int	j;

	if (input[0] == NULL)
		return (1);
	i = 0;
	while (input[i])
	{
		j = 1;
		while (input[j] && input[i + j])
		{
			if (ft_atoi_long(input[i]) == ft_atoi_long(input[i + j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_input_check(char **input)
{
	int		i;
	int		j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if ((input[i][0] == '-' || input[i][0] == '+') && j == 0)
				j++;
			if (ft_isdigit(input[i][j]) == 0)
				return (1);
			j++;
		}
		if (ft_atoi_long(input[i]) > 2147483647
			|| ft_atoi_long(input[i]) < -2147483648)
			return (1);
		i++;
	}
	if (ft_check_for_doubles(input))
		return (1);
	return (0);
}

int	ft_input_to_list(t_list **a_stack, int argc, char **argv)
{
	int		i;
	t_list	*temp;

	*a_stack = ft_lstnew_pushswap(ft_atoi_long(argv[0]));
	if (*a_stack == NULL)
		return (1);
	i = 1;
	while (i < argc)
	{
		temp = ft_lstnew_pushswap(ft_atoi_long(argv[i]));
		if (temp == NULL)
		{
			ft_free_pushswap(*a_stack, NULL);
			return (1);
		}
		ft_lstadd_back(a_stack, temp);
		i++;
	}
	ft_sort_index(argv, argc, a_stack);
	return (0);
}

char	**ft_input_prepare(char **input)
{
	char	*input_joined;
	char	**input_split;

	input_joined = ft_strjoin(input[0], "");
	if (input_joined == NULL)
		return (NULL);
	input_joined = ft_join_inputs(input_joined, input);
	if (input_joined == NULL)
		return (NULL);
	input_split = ft_split(input_joined, ' ');
	if (ft_input_check(input_split))
	{	
		ft_free_pushswap(NULL, input_split);
		input_split = NULL;
	}
	free (input_joined);
	return (input_split);
}
