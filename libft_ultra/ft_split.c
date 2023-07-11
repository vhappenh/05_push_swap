/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 17:48:36 by vhappenh          #+#    #+#             */
/*   Updated: 2022/11/03 15:14:35 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_arrcount(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_free(char **poarr, int i)
{
	while (i >= 0)
	{
		free (poarr[i]);
		i--;
	}
	return (1);
}

static int	ft_arrfill(char const *s, char **poarr, char c)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == c)
			j++;
		else
		{
			count = 0;
			while (s[j + count] != c && s[j + count] != '\0')
				count++;
			poarr[i] = ft_substr(s, j, count);
			if (poarr[i] == NULL)
				return (ft_free(poarr, i));
			i++;
			j = j + count;
		}
	}
	poarr[i] = ((void *)0);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**poarr;

	poarr = (char **)malloc(sizeof(char *) * (ft_arrcount(s, c) + 1));
	if (poarr == NULL)
		return (NULL);
	if (ft_arrfill(s, poarr, c))
	{
		free (poarr);
		return (NULL);
	}
	return ((char **)poarr);
}
/*
int	main(void)
{
	char s[] = "tripouille";
	char c = 0;
	char **arararar;
	arararar = ft_split(s, c);
	printf("%s\n", arararar[0]);
	printf("%p\n", arararar[1]);
	free(arararar[0]);
	free(arararar);
}*/
