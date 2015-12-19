/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcour.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:42:56 by avella            #+#    #+#             */
/*   Updated: 2015/12/19 20:01:24 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*assign(int ci, int pi, int *ci_pi)
{
	ci_pi[0] = ci;
	ci_pi[1] = pi;
	return (ci_pi);
}

int		*go_right(char *c, char *p, int *ci_pi, int *c_l)
{
	int ci;
	int pi;

	ci = ci_pi[0];
	pi = ci_pi[1];
	c_l[0]++;
	p[pi] = 'x';
	pi = pi + 1;
	ci = ci + 1;
	c[ci] = 'x';
	if (p[pi + 1] == '#' && c[ci + 1] == '.')
		c_l = go_right(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi + 5] == '#' && c[ci + c_l[1]] == '.')
		c_l = go_down(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi - 5] == '#' && c[ci - c_l[1]] == '.')
		c_l = go_up(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi - 1] == '#' && c[ci - 1] == '.')
		c_l = go_left(c, p, assign(ci, pi, ci_pi), c_l);
	return (c_l);
}

int		*go_down(char *c, char *p, int *ci_pi, int *c_l)
{
	int ci;
	int pi;

	ci = ci_pi[0];
	pi = ci_pi[1];
	c_l[0]++;
	p[pi] = 'x';
	pi = pi + 5;
	ci = ci + c_l[1];
	c[ci] = 'x';
	if (p[pi + 1] == '#' && c[ci + 1] == '.')
		c_l = go_right(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi + 5] == '#' && c[ci + c_l[1]] == '.')
		c_l = go_down(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi - 5] == '#' && c[ci - c_l[1]] == '.')
		c_l = go_up(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi - 1] == '#' && c[ci - 1] == '.')
		c_l = go_left(c, p, assign(ci, pi, ci_pi), c_l);
	return (c_l);
}

int		*go_up(char *c, char *p, int *ci_pi, int *c_l)
{
	int ci;
	int pi;

	ci = ci_pi[0];
	pi = ci_pi[1];
	c_l[0]++;
	p[pi] = 'x';
	pi = pi - 5;
	ci = ci - c_l[1];
	c[ci] = 'x';
	if (p[pi + 1] == '#' && c[ci + 1] == '.')
		c_l = go_right(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi + 5] == '#' && c[ci + c_l[1]] == '.')
		c_l = go_down(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi - 5] == '#' && c[ci - c_l[1]] == '.')
		c_l = go_up(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi - 1] == '#' && c[ci - 1] == '.')
		c_l = go_left(c, p, assign(ci, pi, ci_pi), c_l);
	return (c_l);
}

int		*go_left(char *c, char *p, int *ci_pi, int *c_l)
{
	int ci;
	int pi;

	ci = ci_pi[0];
	pi = ci_pi[1];
	c_l[0]++;
	p[pi] = 'x';
	pi = pi - 1;
	ci = ci - 1;
	c[ci] = 'x';
	if (p[pi + 1] == '#' && c[ci + 1] == '.')
		c_l = go_right(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi + 5] == '#' && c[ci + c_l[1]] == '.')
		c_l = go_down(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi - 5] == '#' && c[ci - c_l[1]] == '.')
		c_l = go_up(c, p, assign(ci, pi, ci_pi), c_l);
	if (p[pi - 1] == '#' && c[ci - 1] == '.')
		c_l = go_left(c, p, assign(ci, pi, ci_pi), c_l);
	return (c_l);
}
