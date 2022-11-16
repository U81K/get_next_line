/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:22:17 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/16 17:39:41 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(char *ch)
{
	size_t	i;

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

char	*cut_last(char *out)
{
	char	*reserve;
	int		i;
	int		j;
	int		count;

	i = 0;
	while (out[i] && out[i] != '\n')
		i++;
	if (out[i] == '\n')
		i++;
	if (out[i] == '\0')
	{
		free(out);
		return (NULL);
	}
	count = ft_strlen(strchr(out, '\n')) - 1;
	reserve = malloc(sizeof(char) * count + 1);
	j = 0;
	while (out[i])
		reserve[j++] = out[i++];
	reserve[j] = '\0';
	free(out);
	return (reserve);
}
