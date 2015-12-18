#ifndef FILLIT_H
# define FILLIT_H
# define BUF_SIZE 1 
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
typedef struct	s_list
{
	void	*content;
	size_t	content_size;
	size_t	position;
	struct s_list	*up;
	struct s_list	*right;
	struct s_list	*left;
	struct s_list	*bottom;
}				t_list;

t_list *ft_lstnew(void const *content, size_t content_size);
void ft_putstr(char *str);
int ft_first_link(char *str);
void *ft_memcpy(void *dest, const void *src, size_t n);
int	ft_try(char *str, int i, int l);
char ***ft_split(char *str, char ***tab, int nt);
int go_down(char *piece, int i, int count);
int go_right(char *piece, int i, int count);
int go_up(char *piece, int i, int count);
int go_left(char *piece, int i, int count);
int ft_test_form(char *piece);
int ft_all(char *piece);
#endif
