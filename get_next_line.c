/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 14:21:11 by robin             #+#    #+#             */
/*   Updated: 2017/02/10 19:20:27 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	findEOL(char *buff)
{
	char	EOL;
	int		i;

	EOL = '\n';
	i = 0;
	while (buff[i])
	{
		if (buff[i] == EOL)
			return (i + 1);
		++i;
	}
	return (-1);
}

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

char	*ft_strnew(size_t size)
{
	char		*str;

	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (0);
	ft_bzero(str, size + 1);
	return (str);
}


int get_next_line(const int fd, char **line)
{
	static size_t	bufferlen;
	char			*buff;
	int				EOL;
	int				res;

	if (bufferlen == 0)
		bufferlen = BUFF_SIZE;
	EOL = -1;
	while (EOL == -1)
	{
		buff = ft_strnew(bufferlen);
		res = read(fd, buff + bufferlen, BUFF_SIZE);
		if (res == -1)
		{
			free(buff);
			return (-1);
		}
		if (res == 0)
			EOL = 0;
		else
		{
			printf("toto\n");
			EOL = findEOL(buff);
			if (EOL == -1)
				bufferlen += BUFF_SIZE;
		}
	}
	printf("%d\n", EOL);
	printf("%zu", bufferlen);
	//clamp bufferlen
	return (1);
}
