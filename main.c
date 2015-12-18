/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:05:16 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/07 18:11:41 by zkerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_read(int fd, char *buf)
{
	int ret;
	int len;

	len = 0;	
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		len += ret;
	}
	return (len); 
}

char *ft_write(int fd, char *buf, char *str)
{
	int	i;
	int ret;
	
	i = 0;
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		str[i] = *buf;
		i++;
	}
	str[i] = '\0';
	return (str);
}

int ft_check_open(int fd)
{
	if (fd == -1)
	{
		return(1);		
	}
	return (0);
}

int main(int argc, char **argv)
{
	int fd;
	char buf[BUF_SIZE];
	char *tetris;

	if (argc > 2 || argc == 1)
		return(0);
	fd = open(argv[1], O_RDONLY); 
	ft_check_open(fd);
	tetris = (char *)malloc(sizeof(char *) * (ft_read(fd, buf) + 1));
	fd = open(argv[1], O_RDONLY); 
	tetris = ft_write(fd, buf, tetris);
	printf("%s",tetris);
	printf("%d", all_try(tetris));
	return(0);
}
