/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 13:51:43 by vhappenh          #+#    #+#             */
/*   Updated: 2022/10/28 11:12:04 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		count;
	char	*ptr;

	i = 0;
	count = 0;
	while (s1[count] && ft_strchr(set, s1[count]))
		count++;
	i = ft_strlen(s1) - 1;
	while (i >= count && ft_strchr(set, s1[i]))
		i--;
	ptr = ft_substr(s1, count, i - count + 1);
	if (ptr == NULL)
		return (NULL);
	return ((char *)ptr);
}
/*
int	main(void)
{
	char s1[] = " Hallo ich bin ein Test ";
	char set[] = " ";
	ft_strtrim(s1, set);
}*/
