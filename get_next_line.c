/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:04:54 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/04 20:12:50 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

char *ft_strjoin(char *s1, char *s2)
{
	// int	s1_len;
	size_t	sum_len;
	int	i;
	int	j;
	char *res;

	sum_len = strlen(s1) + strlen(s2);
	res = malloc(sizeof(char) * sum_len + 1);
	if (!res)
		return(0);
	i = 0;
	while (s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (i <= (int)sum_len)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

int	check(char *ch)
{
	int i;

	i = 0;
	while (ch[i])
	{
		if (ch[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	char *res;
	char *buf;
	// int i;
	int j;
	int buf_size;

	j = 0;
	buf_size = 5;
	buf = malloc(2);
	res = malloc(20);
	
	while (1)
	{
		j = read(fd, buf, 1);
		if (j <= 0)
			break ;
		if (check(buf))
			break ;
		res = ft_strjoin(res, buf);
	}
	// printf("%s\n", strchr(buf, 'h'));
	
	// read(fd, buf, 6);
	res[strlen(res) + 1] = '\0';
	// printf("%s", buf);
	// j += read (fd, buf, buf_size);
	// res[j] = '\0';
	return (res);
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
}
