/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_break.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 10:26:46 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/07 17:41:39 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_ptflist	*ft_newlist(void)
{
	t_ptflist	*a;

	a = malloc(sizeof(t_ptflist));
	if (!a)
		return (NULL);
	a->left_justify = -1;
	a->precision = -1;
	a->width = -1;
	a->temp = 0;
	a->tempw = 0;
	a->size = 0;
	a->check_c = 0;
	a->neg_width = -1;
	a->next = NULL;
	ft_bzero(a->beginning, 1000);
	a->result = ft_calloc(1001, sizeof(char));
	ft_bzero(a->flag, 30);
	a->zero = -1;
	return (a);
}

void		*ft_strlcpy2(char *dst, const char *src, unsigned int n)
{
	unsigned int i;

	i = n;
	if (!dst && !src)
		return (NULL);
	while (i > 0)
	{
		((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
		i--;
	}
	dst[n] = '\0';
	return (dst);
}

int			ft_extract(const char *str, char *comp, int i, char *dest)
{
	int	len;
	int	j;

	len = 0;
	while (str[i])
	{
		j = 0;
		while (comp[j])
		{
			if (comp[j] == str[i])
			{
				ft_strlcpy2(dest, str + i - len, len);
				return (i);
			}
			else
				j++;
		}
		len++;
		i++;
	}
	ft_strlcpy2(dest, str + i - len, len);
	return (i);
}

int			ft_breakii(t_ptflist *node, const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i = ft_extract(str, "%", i, node->beginning);
		if (!str[i])
			break ;
		if (str[i] == '%')
			i++;
		i = ft_extract(str, "cspdsiuxX%", i, node->flag);
		if ((str[i] == 'c' || str[i] == 's' || str[i] == 'p' || str[i] == 'd' ||
		str[i] == 'i' || str[i] == 'u' || str[i] == 'x' || str[i] == 'X' ||
		str[i] == '%') && str[i])
			node->spcf = str[i];
		i++;
		node->next = ft_newlist();
		if (!node)
			return (-1);
		node = node->next;
	}
	node = NULL;
	return (0);
}

t_ptflist	*ft_break(const char *str)
{
	t_ptflist	*head;
	t_ptflist	*node;

	if (!str)
		return (NULL);
	node = ft_newlist();
	if (!node)
		return (NULL);
	head = node;
	if (ft_breakii(node, str) == -1)
		return (NULL);
	return (head);
}
