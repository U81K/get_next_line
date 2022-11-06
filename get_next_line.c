/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:04:54 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/06 17:33:19 by bgannoun         ###   ########.fr       */
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

// char *cut_str(char *str)
// {
// 	int i;
// 	char *n_str;

// 	i = 0;
// 	while (str[i] != '\n' && str[i] != '\0')
// 	{
// 		n_str[i] = str[i];
// 		i++;
// 	}
// 	n_str[i] = '\0';
// 	return (n_str);
// }

//to cut out to add it to line
int	cut_count(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char *cut_first(char *str)
{
	int i;
	char *n_str;
	
	n_str = malloc(sizeof(char) * cut_count(str) + 1);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		n_str[i] = str[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}

//cut out

char *cut_last(char *str)
{
	int i;
	int j;
	int count;
	char *res;
	char *chr;

	i = 0;
	j = 0;
	count = strlen(strchr(str, '\n')) - 1;
	res = malloc(sizeof(char) * count + 1);
	res = strchr(str, '\n') + 1;
	res[count + 1] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char *line;
	static char *out;
	char *buf;
	int j;
	
	j = 0;
	buf = malloc(5);
	out = malloc(20);
	while (1)
	{
		j = read(fd, buf, 5);
		if (j <= 0)
			break;
		if (check(buf))
			break ;
		out = ft_strjoin(out, buf);
	}
	line = ft_strjoin(out, cut_first(buf));
	out = ft_strjoin(out, buf);
	if (check(buf))
		out = cut_last(out);
	// out = strchr(out, '\n');
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
	printf("%s\n", get_next_line(fd));
	// printf("%s\n", get_next_line(fd));
	// printf("%s", get_next_line(fd));
}
