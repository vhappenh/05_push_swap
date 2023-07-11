/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:18:50 by vhappenh          #+#    #+#             */
/*   Updated: 2022/10/28 11:04:34 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
		j++;
	destlen = i;
	srclen = j;
	if (size == 0)
		return (srclen);
	if (size <= destlen)
		return (srclen + size);
	i = 0;
	while (i < (size - destlen - 1) && src[i] != '\0')
	{
		dest[destlen + i] = src[i];
		i++;
	}
	dest[destlen + i] = '\0';
	return (destlen + srclen);
}
/*
#include <stdio.h>
int	main(void)
{
	char dest[30];

	char *src = (char *)"AAAAAAAAA";
	dest[0] = 'B';
	printf("%ld", ft_strlcat(dest, src, 1000));
	printf("\n%s", dest);
}*/
