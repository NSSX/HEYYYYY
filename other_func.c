/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 19:25:15 by avella            #+#    #+#             */
/*   Updated: 2015/12/19 19:26:23 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*chaine_del_carac(char *chaine, char carac)
{
	int i;

	i = 0;
	while (chaine[i] != '\0')
	{
		if (chaine[i] == carac)
			chaine[i] = '.';
		i++;
	}
	return (chaine);
}

int		*all_task(int *tetri_carac, int n)
{
	if (n == 1)
	{
		tetri_carac[0]++;
		tetri_carac[1]++;
	}
	else if (n == 2)
	{
		tetri_carac[1]--;
		tetri_carac[0]--;
	}
	else if (n == 3)
	{
		tetri_carac[0] = 0;
		tetri_carac[1] = 'A';
	}
	return (tetri_carac);
}

void	modify(char *chaine, int *tetri_carac, int n)
{
	if (n == 1)
	{
		chaine = trans_di(chaine, tetri_carac[1]);
		tetri_carac = all_task(tetri_carac, 1);
	}
	else if (n == 2)
	{
		tetri_carac = all_task(tetri_carac, 2);
		chaine = chaine_del_carac(chaine, tetri_carac[1]);
	}
}

void	modify_2(char *chaine, int *tetri_carac, int *iactuel, int n)
{
	if (n == 1)
	{
		modify(chaine, tetri_carac, 1);
		iactuel[tetri_carac[0]] = 0;
	}
	else if (n == 2)
	{
		modify(chaine, tetri_carac, 2);
		iactuel[tetri_carac[0]]++;
	}
}

char	*last_modify(char *chaine, int *tetri_carac, int length)
{
	chaine = malloc_chaine(chaine, ++length);
	tetri_carac = all_task(tetri_carac, 3);
	return (chaine);
}
