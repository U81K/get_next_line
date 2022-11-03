/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:18:58 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/03 18:58:44 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

#define BUF_SIZE 4096

int	main(void)
{
	int	fd;
	int	res;
	char buf[BUF_SIZE + 1];
	
	fd = open("fd.txt", O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1)
		return (0);
	
	res = read (fd, buf, BUF_SIZE);
	buf[res] = '\0';
	printf("%s\n", buf);
	
	printf("%d", fd);
	close(fd);
	return (0);
}
