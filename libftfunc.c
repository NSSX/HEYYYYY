/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftfunc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 19:32:32 by avella            #+#    #+#             */
/*   Updated: 2015/12/19 20:34:14 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*dp(const char *s1)
{
	int		index;
	char	*dupli;

	index = 0;
	dupli = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (dupli == NULL)
	{
		return (NULL);
	}
	while (s1[index] != '\0')
	{
		dupli[index] = s1[index];
		index++;
	}
	dupli[index] = '\0';
	return (dupli);
}

size_t	ft_strlen(const char *str)
{
	size_t index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}
