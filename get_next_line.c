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
	//free(buff);
	return (t);
}

int		get_next_line(const int fd, char **line)
{
	static char		*lastbuff;
	char			*buff;
	int				eol;
	int				res;
	int				n;

	eol = -1;
	//printf("toto\n");
	printf("%s\n", lastbuff);
	if (lastbuff)
	{
		if (ft_strchr(lastbuff, '\n'))
		{
			printf("toto\n");
			*line = malloc(findeol(lastbuff));
			ft_strncpy(*line, lastbuff, findeol(lastbuff));
			ft_strcpy(lastbuff, lastbuff + eol);
			return (1);
		}
	}
	n = 0;
	//printf("toto\n");
	while (eol == -1)
	{
		//printf("toto\n");
		buff = ft_realloc(buff, (n + 1) * BUFF_SIZE);
		//printf("toto\n");
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
			//printf("toto\n");
			printf("%s\n", buff);
			eol = findeol(buff);
			printf("%d\n", eol);
			//printf("toto\n");
			if (eol == -1)
			{
				n++;
			}
		}
	}
	lastbuff = ft_strdup(buff + (eol + 1));
	*line = malloc(ft_strlen(lastbuff) + eol + 1);
	//printf("toto\n");
	ft_strcpy(*line, lastbuff);
	//printf("toto\n");
	ft_strlcat(*line, buff, eol);
	eol = eol + (n * BUFF_SIZE);
	printf("%d\n", eol);
	free(buff);
	printf("%s\n", lastbuff);
	return (1);
}
