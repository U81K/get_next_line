/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:04:54 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/10 17:33:05 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *line;
	static char *out;
	char *buf;
	int j;
	// char *s;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// line = NULL;
	
	j = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
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
	{
		free(buf);
		return (NULL);
	}
	free(buf);
	line = cut_first(out);
	// s = out;
	out = cut_last(out);
	// free(out);
	// printf("<%s>", out);
	// printf("<%s>", out);
	// free(s);
	return (line);
}

// int	main(void)
// {
// 	int	fd;
// 	int	i;
// 	int	j;
// 	int	k;
// 	char *res;
	
// 	fd = open("test.txt", O_RDWR | O_CREAT);
// 	// i = read(fd, res, 11);
// 	// res[i] = '\0';
// 	// printf("%s", res);
// 	printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// close(fd);
// 	// fd = open("test.txt", O_RDWR | O_CREAT, S_IRWXU);
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// res = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	// i = read(fd, res, BUFFER_SIZE);
// 	// j = read(fd, res, BUFFER_SIZE);
// 	// k = read(fd, res, BUFFER_SIZE);
// 	// printf("%d\n%d\n%d", i, j, k);
// 	close(fd);
// }
