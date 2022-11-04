/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 13:22:17 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/04 14:23:15 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strjoin(char *s1, char *s2)
{
	int	s1_len;
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
	while (i <= sum_len)
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}

int main(void)
{
	printf("%s", ft_strjoin("hello", " world"));
}