/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:22:17 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/07 13:22:54 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strjoin(char *s1, char *s2)
{
	size_t	sum_len;
	size_t	i;
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
	while (i <= sum_len)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	free(s1);
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
	
	n_str = malloc(sizeof(char) * cut_count(str) + 1);
	i = 0;
	j = cut_count(str);
	while (str[i] != '\0' && str[i] != '\n')
	{
		n_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
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
	// char *chr;

	i = 0;
	j = 0;
	count = strlen(strchr(str, '\n')) - 1;
	res = malloc(sizeof(char) * count + 1);
	res = strchr(str, '\n') + 1;
	res[count + 1] = '\0';
	return (res);
}
