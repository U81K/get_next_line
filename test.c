/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:18:58 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/05 23:26:16 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1

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

int	main(void)
{
	char str[] = "hello wor\ndld\ns";

	printf("%s\n", cut_str(str));
	printf("%s", cut_out(str));
	// printf("%d", cut_count(str));
	// printf("%s", strchr("helloZddfd", 'Z'));
	return (0);
}
