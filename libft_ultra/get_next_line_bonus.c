/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhappenh <vhappenh@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:50:19 by vhappenh          #+#    #+#             */
/*   Updated: 2022/12/03 10:01:16 by vhappenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_line(int fd, char *save)
{
	int		ret;
	char	*buf;
	char	*temp_save;

	if (save == NULL)
		save = ft_calloc(1, 1);
	ret = 1;
	while (!ft_strchr(save, '\n') && ret != 0)
	{
		buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (buf == NULL)
			return (NULL);
		temp_save = save;
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free (buf);
			free (save);
			return (NULL);
		}
		save = ft_strjoin(temp_save, buf);
		free (temp_save);
		free (buf);
	}
	return (save);
}

static char	*first_line(char *save)
{
	char	*endline;
	char	*output;
	int		length;

	endline = ft_strchr(save, '\n');
	if (endline == NULL)
	{
		endline = ft_strchr(save, '\0') - 1;
		if (endline == NULL)
			return (NULL);
	}
	length = endline - save + 1;
	if (save[0] == '\0')
		return (NULL);
	output = malloc(sizeof(char) * length + 1);
	if (output == NULL)
		return (NULL);
	output = ft_memcpy(output, save, length + 1);
	if (*output == 0)
		return (NULL);
	output[length] = '\0';
	return (output);
}

static char	*ft_trimmy(char *save)
{
	char	*tempy;
	int		i;

	i = 0;
	tempy = save;
	if (ft_strchr(save, '\n'))
	{
		while (save[i] != '\n')
			i++;
		i++;
		save = ft_strjoin(&tempy[i], "");
		free (tempy);
	}
	else
	{
		free (save);
		return (NULL);
	}
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save[9999];
	char		*result;

	if (read(fd, NULL, 0) < 0 || fd < 0)
	{
		if (save[fd])
		{
			free(save[fd]);
			save[fd] = NULL;
		}
		return (NULL);
	}
	save[fd] = get_line(fd, save[fd]);
	if (save[fd] == NULL)
		return (NULL);
	result = first_line(save[fd]);
	save[fd] = ft_trimmy(save[fd]);
	if (result == NULL && save[fd] == NULL)
		return (NULL);
	return (result);
}
/*
#include <stdio.h>
int	main(void)
{
//	int		fd;
	char	*line;
	char	bla;
	
	fd = open("testfile.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	line = &bla;
	while(line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free (line);
	}
	printf("%s", get_next_line(fd));
	return (0);
}*/
