/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 19:27:40 by avella            #+#    #+#             */
/*   Updated: 2015/12/19 19:29:03 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		first_di(char *p)
{
	int i;

	i = 0;
	while (p[i] != '\0' && p[i] != '#')
		i++;
	return (i);
}

int		try(char *c, char *p, int *ci_pi, int length)
{
	int *c_l;
	int ci;
	int pi;

	c_l = NULL;
	ci = ci_pi[0];
	pi = ci_pi[1];
	c_l = create(c_l, length);
	if (c[ci] == '.' && p[pi] == '#')
		c_l[0]++;
	else
		return (0);
	c[ci] = 'x';
	p[pi] = 'x';
	if (p[pi + 1] == '#' && c[ci + 1] == '.')
		c_l = go_right(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi + 5] == '#' && c[ci + c_l[1]] == '.')
		c_l = go_down(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi - 5] == '#' && c[ci - c_l[1]] == '.')
		c_l = go_up(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi - 1] == '#' && c[ci - 1] == '.')
		c_l = go_left(c, p, assign(ci, pi, ci_pi), c_l);
	if (c_l[0] == 4)
		return (1);
	return (0);
}

int		nb_tetri(char *c)
{
	int count;
	int time;
	int i;

	i = 0;
	time = 0;
	count = 0;
	while (c[i] != '\0')
	{
		while (time < 4)
		{
			while (c[i] != '\n')
			{
				i++;
			}
			i++;
			time++;
		}
		count++;
		time = 0;
		if (c[i] == '\0')
			return (count);
		i++;
	}
	return (count);
}

char	*backtrack(char *c, int l, char **t, int nbt)
{
	int *t_c;
	int **dv;

	t_c = malloc_tetri_carac();
	dv = double_v(nbt);
	while (t_c[1] != 'A' + nbt)
	{
		dv[1] = index_return(dv[1], t, t_c, dv[0]);
		while (!try(dp(c), dp(t[t_c[0]]), dv[1], l) && c[dv[0][t_c[0]]] != '\0')
			dv[1][0] = ++dv[0][t_c[0]];
		if (try(dp(c), dp(t[t_c[0]]), dv[1], l))
		{
			try(c, dp(t[t_c[0]]), dv[1], l);
			modify_2(c, t_c, dv[0], 1);
		}
		else if (t_c[1] != 'A')
			modify_2(c, t_c, dv[0], 2);
		else
		{
			dv[0] = iactuel_reset(dv[0], nbt);
			c = last_modify(c, t_c, l++);
			l++;
		}
	}
	return (c);
}

void	ft_all(char *p)
{
	char	*c;
	char	**tab;
	int		length;
	int		*iactuel;
	int		nbt;

	c = NULL;
	nbt = nb_tetri(p);
	tab = all_tetri(dp(p), 0, 0, nb_tetri(p));
	length = 2;
	c = malloc_chaine(c, length);
	length++;
	c = backtrack(c, length, tab, nbt);
	ft_putstr(c);
}
