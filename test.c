/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:18:58 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/04 13:22:00 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 1

int	main(void)
{
	int	fd;
	int	res;
	char buf[BUF_SIZE + 1];
	
	fd = open("fd.txt", O_RDWR | O_CREAT, S_IRWXO);
	if (fd == -1)
		return (0);
	
	res = read (fd, buf, 5);
	buf[res] = '\0';
	printf("%d\n", res);
	printf("%s\n", buf);
	
	// printf("%d", fd);
	close(fd);
	return (0);
}
