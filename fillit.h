/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:49:20 by avella            #+#    #+#             */
/*   Updated: 2015/12/19 19:25:00 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 1
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>

int all_try(char *chaine);
int try_1(char *chaine);
int try_2(char *chaine, int count, int time, int i);
int try_3(char *chaine, int count, int time, int i);
void	ft_putstr(char const *str);
void	ft_putchar(char c);
size_t	ft_strlen(const char *str);
char	*dp(const char *s1);
int		*go_right(char *c, char *p, int *ci_pi, int *c_l);
int		*go_down(char *c, char *p, int *ci_pi, int *c_l);
int		*go_up(char *c, char *p, int *ci_pi, int *c_l);
int		*go_left(char *c, char *p, int *ci_pi, int *c_l);
void	ft_all(char *piece);
int		*assign(int chainei, int piecei, int *chainei_piecei);
char	*malloc_chaine(char *chaine, int length);
int		*malloc_tetri_carac();
int		**double_v(int nbt);
char	**all_tetri(char *chaine, int i, int i2, int nb);
int		*create(int *count_length, int length);
char	*chaine_del_carac(char *chaine, char carac);
int		*all_task(int *tetri_carac, int n);
void	modify(char *chaine, int *tetri_carac, int n);
void	modify_2(char *chaine, int *tetri_carac, int *iactuel, int n);
char	*last_modify(char *chaine, int *tetri_carac, int length);
int		*iactuel_reset(int *iactuel, int nbt);
int		*index_return(int *ci_pi, char **tab, int *t_c, int *ia);
char	*trans_di(char *chaine, char c);
int		first_di(char *piece);
#endif
