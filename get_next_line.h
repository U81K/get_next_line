/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgannoun <bgannoun@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:05:59 by bgannoun          #+#    #+#             */
/*   Updated: 2022/11/07 13:19:58 by bgannoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

char *ft_strjoin(char *s1, char *s2);
int	check(char *ch);
int	cut_count(char *str);
char *cut_first(char *str);
char *cut_last(char *str);
char	*get_next_line(int fd);

#endif