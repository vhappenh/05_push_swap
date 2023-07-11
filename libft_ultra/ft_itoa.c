/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 14:06:21 by vhappenh          #+#    #+#             */
/*   Updated: 2022/10/28 11:15:09 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(long n)
{
	int	count;

	count = 0;
	while (n % 10 != 0 || n / 10 != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_fillzero(char *ptr)
{
	ptr[0] = '0';
	ptr[1] = '\0';
}

static void	ft_fill(char *ptr, long n, int isize)
{
	int	i;

	i = isize;
	if (n < 0)
	{
		ptr[0] = '-';
		n = n * -1;
		while (i >= 1)
		{
			ptr[i] = (n % 10) + '0';
			n = n / 10;
			i--;
		}
		ptr[isize + 1] = '\0';
	}
	else
	{
		while (i > 0)
		{
			ptr[i - 1] = (n % 10) + '0';
			n = n / 10;
			i--;
		}
		ptr[isize] = '\0';
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	long	boy;

	boy = n;
	if (boy <= 0)
		ptr = (char *)malloc(sizeof(char) * (ft_count(boy) + 2));
	else
		ptr = (char *)malloc(sizeof(char) * (ft_count(boy) + 1));
	if (ptr == NULL)
		return (NULL);
	if (boy == 0)
		ft_fillzero(ptr);
	else
		ft_fill(ptr, boy, ft_count(n));
	return ((char *)ptr);
}
/*
int	main(void)
{
	int n;

	n = 0;
	ft_itoa(n);
}*/
