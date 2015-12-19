/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefull_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 19:26:40 by avella            #+#    #+#             */
/*   Updated: 2015/12/19 19:27:14 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*iactuel_reset(int *iactuel, int nbt)
{
	int i;

	i = 0;
	while (i < nbt)
	{
		iactuel[i] = 0;
		i++;
	}
	return (iactuel);
}

int		*index_return(int *ci_pi, char **tab, int *t_c, int *ia)
{
	ci_pi[1] = first_di(tab[t_c[0]]);
	ci_pi[0] = ia[t_c[0]];
	return (ci_pi);
}

char	*trans_di(char *chaine, char c)
{
	int i;

	i = 0;
	while (chaine[i] != '\0')
	{
		if (chaine[i] == 'x')
			chaine[i] = c;
		i++;
	}
	return (chaine);
}
