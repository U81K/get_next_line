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

char *cut_str(char *str)
{
	int i;
	char *n_str;
	
	n_str = malloc(sizeof(char) * strlen(str) + 1);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		n_str[i] = str[i];
		i++;
	}
	n_str[i] = '\0';
	return (n_str);
}

int	main(void)
{
	char str[] = "hello wordl";
	printf("%s", cut_str(str));
	// printf("%s", strchr("helloZddfd", 'Z'));
	return (0);
}
