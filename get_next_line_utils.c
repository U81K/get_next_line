/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:22:17 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/08 16:46:11 by bgannoun         ###   ########.fr       */
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

	if (!s1)
		s1 = strdup("");
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	res = (char *)malloc(sizeof(char) * (len_s2 + len_s1 + 1));
	if (!res)
		return (0);
	i = 0;
	while (i != len_s1)
	{
		res[i] = (char)s1[i];
		i++;
	}
	j = 0;
	while (i != (len_s1 + len_s2))
		res[i++] = (char)s2[j++];
	res[(len_s1 + len_s2)] = '\0';
	free(s1);
	return (res);
}

// char *ft_strjoin(char *s1, char *s2)
// {
// 	size_t	sum_len;
// 	size_t	i;
// 	int	j;
// 	char *res;

// 	sum_len = ft_strlen(s1) + ft_strlen(s2);
// 	res = malloc(sizeof(char) * sum_len + 1);
// 	if (!res)
// 		return(0);
// 	i = 0;
// 	while (s1 && s1[i] != '\0')
// 	{
// 		res[i] = s1[i];
// 		i++;
// 	}
// 	j = 0;
// 	while (s2 && s2[j] != '\0')
// 	{
// 		res[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	res[i] = '\0';
// 	// free(s1);
// 	return (res);
// }

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

int	cut_count(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char *cut_first(char *str)
{
	int i;
	int j;
	char *n_str;
	
	n_str = malloc(sizeof(char) * cut_count(str) + 2);
	i = 0;
	if (!str)
		return(NULL);
	while (str[i] != '\0' && str[i] != '\n')
	{
		n_str[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
		return(NULL);
	if (str[i] == '\n')
	{
		n_str[i] = str[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}

//cut out

char *cut_last(char *buf)
{
	int i;
	int j;
	int count;
	char *res;
	
	count = strlen(strchr(buf, '\n')) - 1;
	res = malloc(sizeof(char) * count + 1);
	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	if (buf[i] == '\0')
	{
		free(buf);
		return (NULL);
	}
	j = 0;
	while (buf[i])
	{
		res[j] = buf[i];
		i++;
		j++;
	}
	res[j] = '\0';
	free(buf);
	return (res);
}

// int main(void)
// {
// 	// printf("%d\n", cut_count("abcd\n"));
// 	printf("%s", cut_last("abcd\nefj"));
// }