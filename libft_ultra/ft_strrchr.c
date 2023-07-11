/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 09:59:47 by vhappenh          #+#    #+#             */
/*   Updated: 2022/10/28 11:07:38 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;

	ptr = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
			ptr = (char *)s;
		s++;
	}
	if ((char)c == 0)
		return ((char *)s);
	return ((char *)ptr);
}
