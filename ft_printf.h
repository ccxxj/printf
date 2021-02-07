/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 11:33:57 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/07 17:43:34 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef	struct		s_ptflist
{
	int				left_justify;
	int				precision;
	int				width;
	int				temp;
	int				tempw;
	int				size;
	int				zero;
	int				neg_width;
	int				check_c;
	char			flag[30];
	char			spcf;
	char			beginning[1000];
	char			*result;
	struct s_ptflist	*next;
}					t_ptflist;

char				*ft_itoa(int n);
void				ft_bzero(void *str, size_t n);
void				*ft_calloc(size_t count, size_t size);
char				*ft_htoa(unsigned long long int n, char c, int i);

int					ft_putstr(char *str);
void				ft_listclear(t_ptflist *lst);
int					ft_print(t_ptflist *node);
int					ft_printf(const char *str, ...);
void				width_adp(int a, t_ptflist *node);

t_ptflist			*ft_newlist(void);
void				*ft_strlcpy2(char *dst, const char *src, unsigned int n);
char				check_spcf(char c);
int					ft_extract(const char *str, char *comp, int i, char *dest);
t_ptflist			*ft_break(const char *str);

int					ft_extractnbr(char *str, int i, t_ptflist *node, int j);
void				ft_allocate(t_ptflist *node, va_list args);
int					ft_strcpy(char *dst, char *src);
int					str_transfer(char *dest, char *src, t_ptflist *node);
t_ptflist			*ft_replace(t_ptflist *node, va_list args);

void				neg_check(int n, int size, char *str, t_ptflist *node);
void				nbrprocess(t_ptflist *node);
char				*ft_expand(int n, int size, char *str, t_ptflist *node);
void				ft_process(t_ptflist *node);

char				*ft_leftexpand(int n, int size, char *str, char c);
char				*ft_rightexpand(int n, int size, char *str, char c);

#endif
