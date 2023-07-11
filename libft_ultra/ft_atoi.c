/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:07:17 by vhappenh          #+#    #+#             */
/*   Updated: 2022/12/15 13:22:33 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static long	ft_overflow(long sum)
{
	if (sum > 2147483647)
		return (0);
	if (sum < -2147483648)
		return (-1);
	return (sum);
}

int	ft_atoi(const char *nptr)
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
	sum = ft_overflow(sum * sign);
	return (sum);
}
/*
int	main(void)
{
	printf("ft_atoi: %d\n", ft_atoi("-2147483648"));
	printf("atoi: %d\n", atoi("-2147483648"));
}*/
