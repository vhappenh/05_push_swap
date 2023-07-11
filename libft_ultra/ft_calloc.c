/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:34:50 by vhappenh          #+#    #+#             */
/*   Updated: 2022/10/22 16:30:43 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	i;

	i = nmemb * size;
	if (i > 4294967295)
		return ((void *) NULL);
	str = (char *)malloc(nmemb * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, i);
	return ((void *)str);
}
