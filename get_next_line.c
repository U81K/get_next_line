/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:04:54 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/08 16:33:01 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *line;
	static char *out;
	char *buf;
	int j;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	
	j = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		j = read(fd, buf, BUFFER_SIZE);
		if (j <= 0)
			break;
		buf[j] = '\0';
		out = ft_strjoin(out, buf);
		if (check(out))
			break ;
	}
	if (!out)
		return (NULL);
	line = cut_first(out);
	if (check(out))
	{
		out = cut_last(out);
	}
	// if ()
	// if (check(buf))
	// 	out = cut_last(out);
	// out = strchr(out, '\n');
	free(buf);
	return (line);
}

int	main(void)
{
	int	fd;
	// int	i;
	// char *res;
	
	fd = open("test.txt", O_RDWR | O_CREAT, S_IRWXU);
	// i = read(fd, res, 11);
	// res[i] = '\0';
	// printf("%s", res);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// close(fd);
	// fd = open("test.txt", O_RDWR | O_CREAT, S_IRWXU);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	// printf("%s", get_next_line(fd));
	close(fd);
}
