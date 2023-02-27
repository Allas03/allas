/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalhi <asalhi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:23:09 by asalhi            #+#    #+#             */
/*   Updated: 2023/02/27 17:37:59 by asalhi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char *ToTemp(char *dst, char const *src, size_t dst_size)
{
	size_t	i;

	i = 0;
	if (dst_size == 0)
	{
		while (src[i] != 0)
		{
			i++;
		}
		return (i);
	}
	while (src[i] && i < dst_size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < dst_size)
	{
		dst[i] = '\0';
	}
	while (src[i] != '\0')
	{
		i++;
	}
	return (i);
}

char *get_next_line(int fd)
{
	int	x;
	int	i;
	char	*str;
	char	*temp;
	char	*supp;

	str = malloc(sizeof (char *) * BUFF_SIZE);
	if (str == NULL)
		return (NULL);
	read(fd, str, BUFF_SIZE);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			x = 0;
			while (str[i])
			{
				supp[x] = str[i];
			}
			ToTemp(temp, supp, BUFF_SIZE);	
			return (temp);
		}
		i++;
	}
}


void main()
{
	int fd;
	char buffer[1024];
	size_t	bytesread;
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
}