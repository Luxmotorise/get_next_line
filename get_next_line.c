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
#include "./libft/libft.h"
#include <stdio.h>

int		findeol(char *buff)
{
	char	eol;
	int		i;

	eol = '\n';
	i = 0;
	while (buff[i])
	{
		// printf("coco\n");
		if (buff[i] == eol)
			return (i);
		++i;
	}
	return (-1);
}

char	*ft_realloc(char *buff, int n)
{
	char *t;

	t = malloc(n + 1);
	t[0] = 0;
	ft_strcat(t, buff);
	return (t);
}

int		get_next_line(const int fd, char **line)
{
	static char		*lastbuff;
	size_t			bufferlen;
	char			*buff;
	int				eol;
	int				res;
	int				n;

	if (ft_strchr(lastbuff, '\n'))
	{
		*line = ft_strncpy(line, lastbuff, findeol(lastbuff));
		lastbuff = ft_strcpy(lastbuff, lastbuff[eol]);
		return (1);
	}
	if (bufferlen == 0)
		bufferlen = BUFF_SIZE;
	eol = -1;
	n = 0;
	while (eol == -1)
	{
		buff = ft_realloc(buff, n * BUFF_SIZE);
		res = read(fd, buff + eol, BUFF_SIZE);
		if (res == -1)
		{
			free(buff);
			return (-1);
		}
		if (res == 0)
			eol = 0;
		else
		{
			// printf("toto\n");
			// printf("%s\n", buff);
			eol = findeol(buff);
			// printf("%d\n", eol);
			// printf("toto\n");
			if (eol == -1)
			{
				bufferlen += BUFF_SIZE;
				n++;
			}
		}
		eol = eol + (n * BUFF_SIZE);
	}
	// printf("%d\n", eol);
	// printf("%zu", bufferlen);
	*line = lastbuff + ft_strncpy(line, buff, eol);
	lastbuff = ft_strcpy(lastbuff, buff[eol]);
	return (1);
}
