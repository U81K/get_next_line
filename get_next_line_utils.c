/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:22:17 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/16 13:04:13 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t ft_strlen(char *ch)
{
	size_t i;
	
	i = 0;
	if (!ch)
		return (0);
	while (ch[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;
	size_t	j;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i != len_s1)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (i != (len_s1 + len_s2))
		res[i++] = s2[j++];
	res[(len_s1 + len_s2)] = '\0';
	free(s1);
	return (res);
}

int	check_n(char *ch)
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

// int	cut_count(char *str)
// {
// 	int i;

// 	i = 0;
// 	return (i);
// }

char *cut_first(char *out)
{
	int i;
	char *line;
	
	if (!out)
		return(NULL);
	i = 0;
	while (out[i] && out[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (out[i] != '\0' && out[i] != '\n')
	{
		line[i] = out[i];
		i++;
	}
	if (out[i] && out[i] == '\n')
	{
		line[i] = out[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char *cut_last(char *buf)
{
	int i;
	int j;
	int count;
	char *out;
	
	if (!check_n(buf))
	{
		free(buf);
		return (NULL);
	}
	count = strlen(strchr(buf, '\n')) - 1;
	out = malloc(sizeof(char) * count + 1);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		free(out);
		return (NULL);
	}
	j = 0;
	while (buf[i])
	{
		out[j] = buf[i];
		i++;
		j++;
	}
	out[j] = '\0';
	free(buf);
	return (out);
}

// int main(void)
// {
// 	char *s1;
// 	printf("%s", cut_first("abcd\nfsfs"));
// 	// printf("%s", cut_last("abcd\nefj"));
// 	// printf("%zu", ft_strlen("1"));
// }