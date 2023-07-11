/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 10:40:07 by vhappenh          #+#    #+#             */
/*   Updated: 2022/10/28 11:09:01 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (ft_strlen(little) == 0 || big == little)
		return ((char *) &*big);
	i = 0;
	while (big[i] != '\0' && (i < len))
	{
		j = 0;
		if (big[i] == little[0])
		{
			while (little[j] != '\0' && (i + j) < len)
			{
				if (big[i + j] == little[j])
					j++;
				else
					break ;
			}
		}
		if (j == ft_strlen(little))
			return ((char *) &*big + i);
		i++;
	}
	return (NULL);
}
