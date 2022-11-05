/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:04:54 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/05 23:23:30 by bgannoun         ###   ########.fr       */
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

char *cut_str(char *str)
{
	int i;
	char *n_str;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		n_str[i] = str[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}

char	*get_next_line(int fd)
{
	char *line;
	char *out;
	char *buf;
	int j;
	
	j = 0;
	while (1)
	{
		j = read(fd, buf, 5);
		if (j <= 0)
			break;
		out = ft_strjoin(out, buf);
		if (check(buf))
			break ;
	}
	line =  
	out = strchr(out, '\n');
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
}
