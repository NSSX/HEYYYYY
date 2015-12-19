/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkerkeb <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:05:16 by zkerkeb           #+#    #+#             */
/*   Updated: 2015/12/18 16:27:34 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_read(int fd, char *buf)
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

char	*ft_write(int fd, char *buf, char *str)
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

int		main(int argc, char **argv)
{
	int		fd;
	char	buf[BUF_SIZE + 1];
	char	*tetris;
	int		nt;

	if (argc != 2)
	{
		ft_putstr("error\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	nt = ft_read(fd, buf);
	tetris = (char *)malloc(sizeof(char *) * (nt + 1));
	fd = open(argv[1], O_RDONLY);
	tetris = ft_write(fd, buf, tetris);
	if(!all_try(tetris))
	  {
	    ft_putstr("error\n");
	    return (0);
	  }
	  ft_all(tetris);
	  return (0);
}
