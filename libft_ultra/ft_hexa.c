/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 11:24:59 by vhappenh          #+#    #+#             */
/*   Updated: 2022/12/03 10:05:26 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_hexprint(unsigned int input, char c)
{
	if (c == 'x' || c == 'p')
		write(1, &"0123456789abcdef"[input], 1);
	else
		write(1, &"0123456789ABCDEF"[input], 1);
}

int	ft_hexa(unsigned long input, char c)
{
	int		i;

	i = 1;
	if (input <= 15)
		ft_hexprint(input, c);
	else
	{
		ft_hexa((input / 16), c);
		ft_hexprint((input % 16), c);
	}
	while ((input / 16) != 0)
	{
		input = input / 16;
		i++;
	}
	return (i);
}
