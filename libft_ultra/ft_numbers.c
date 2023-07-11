/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:57:14 by vhappenh          #+#    #+#             */
/*   Updated: 2022/12/03 10:05:16 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbrlong_fd(long n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = n * -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		n = n % 10;
	}
	if (n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
	}
}

int	ft_numbers(long input)
{
	int		i;
	long	temp;

	i = 1;
	temp = input;
	while ((temp / 10) != 0)
	{	
		temp = temp / 10;
		i++;
	}
	ft_putnbrlong_fd(input, 1);
	if (input < 0)
		i = i + 1;
	return (i);
}
