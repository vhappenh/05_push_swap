/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 14:49:55 by vhappenh          #+#    #+#             */
/*   Updated: 2022/12/03 10:01:05 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char(int input)
{
	ft_putchar_fd(input, 1);
	return (1);
}

static int	ft_string(char *input)
{
	if (!input)
		return (write(1, "(null)", 6));
	if (!*input)
		return (0);
	ft_putstr_fd(input, 1);
	return ((int)ft_strlen(input));
}

static int	ft_chooseft(va_list input, char c)
{
	long	arg;

	if (c == 'c')
		return (ft_char(va_arg(input, long)));
	else if (c == 's')
		return (ft_string(va_arg(input, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_numbers(va_arg(input, int)));
	else if (c == 'u')
		return (ft_numbers(va_arg(input, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_hexa(va_arg(input, unsigned int), c));
	else if (c == 'p')
	{
		arg = va_arg(input, long);
		if (!arg)
			return (write(1, "(nil)", 5));
		write(1, "0x", 2);
		return (ft_hexa(arg, c) + 2);
	}
	else if (c == '%')
		return (write(1, "%", 1));
	else
		return (-1);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	long	temp;
	int		count;

	va_start(args, input);
	i = 0;
	temp = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1] != 0)
		{
			temp = count;
			count += ft_chooseft(args, input[i + 1]);
			if (temp <= count)
				i++;
		}
		else
			count += write(1, &input[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
/*
int	main(void)
{
//	int	p1;
	char p2[] = "hallo";

	printf("\n%d\n", ft_printf("%%p", p2));
	printf("\n%d\n", printf("%%p", p2));
	printf("\n%d\n", ft_printf(" %%% "));
	printf("\n%d\n", printf(" %%% "));
	printf("\n%d\n", ft_printf(" %%%% "));
	printf("\n%d\n", printf(" %%%% "));
	return (0);
}*/
