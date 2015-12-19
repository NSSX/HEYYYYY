/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 19:19:28 by avella            #+#    #+#             */
/*   Updated: 2015/12/19 19:23:36 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*malloc_chaine(char *chaine, int length)
{
	int i;
	int j;
	int index;

	index = 0;
	i = 0;
	j = 0;
	chaine = (char*)malloc(sizeof(char) * (length * (length + 1)) + 1);
	while (i < length)
	{
		while (j < length)
		{
			chaine[index] = '.';
			j++;
			index++;
		}
		chaine[index] = '\n';
		index++;
		j = 0;
		i++;
	}
	chaine[index] = '\0';
	return (chaine);
}

int		*malloc_tetri_carac(void)
{
	int *tetri_carac;

	tetri_carac = (int *)malloc(sizeof(int) * 3);
	tetri_carac[0] = 0;
	tetri_carac[1] = 'A';
	return (tetri_carac);
}

int		**double_v(int nbt)
{
	int **dv;

	dv = (int **)malloc(sizeof(int *) * 3);
	dv[0] = (int *)malloc(sizeof(int) * nbt + 1);
	dv[1] = (int *)malloc(sizeof(int) * 3);
	return (dv);
}

char	**all_tetri(char *chaine, int i, int i2, int nb)
{
	char	**tab;
	int		index;

	index = 0;
	tab = (char **)malloc(sizeof(char *) * nb + 1);
	while (i < nb + 1)
	{
		tab[i] = (char *)malloc(sizeof(char) * 20);
		i++;
	}
	i = 0;
	while (i < nb)
	{
		while (i2 < 20 && chaine[index] != '\0')
		{
			tab[i][i2] = chaine[index];
			i2++;
			index++;
		}
		tab[i][i2] = '\0';
		i2 = 0;
		index++;
		i++;
	}
	return (tab);
}

int		*create(int *count_length, int length)
{
	count_length = (int *)malloc(sizeof(int) * 3);
	count_length[0] = 0;
	count_length[1] = length;
	return (count_length);
}
