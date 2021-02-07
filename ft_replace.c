/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_replace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/15 10:56:49 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/07 16:48:13 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			ft_extractnbr(char *str, int i, t_ptflist *node, int j)
{
	while (str[i] < 58 && str[i] > 47 && str[i])
	{
		node->temp = node->temp * 10 + str[i] - 48;
		i++;
	}
	if (j == 1)
		node->precision = node->temp;
	else
		node->width = node->temp;
	node->temp = 0;
	return (i);
}

void		ft_allocate(t_ptflist *node, va_list args)
{
	int	i;

	i = 0;
	while (node->flag[i])
	{
		if (node->flag[i] == '-')
			node->left_justify = 1;
		if (node->flag[i] == '*')
			width_adp(node->tempw = va_arg(args, int), node);
		if (node->flag[i] == '0')
			node->zero = 1;
		if (node->flag[i] == '.')
		{
			if (node->flag[i + 1] == '*')
			{
				node->precision = va_arg(args, int);
				i++;
			}
			else
				i = ft_extractnbr(node->flag, i + 1, node, 1);
		}
		if (node->flag[i] < 57 && node->flag[i] > 47)
			i = ft_extractnbr(node->flag, i, node, 0) - 1;
		i++;
	}
}

int			ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	if (!dst && !src)
		return (-1);
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

int			str_transfer(char *dest, char *src, t_ptflist *node)
{
	int m;

	if (!src)
		return (-1);
	m = ft_strcpy(dest, src);
	if ((node->spcf == 'd' || node->spcf == 'i') &&
	src[0] == '-')
		node->size = m - 1;
	else
		node->size = m;
	free(src);
	src = NULL;
	return (0);
}

t_ptflist	*ft_replace(t_ptflist *node, va_list args)
{
	t_ptflist	*head;

	head = node;
	while (node->next)
	{
		ft_allocate(node, args);
		if (node->spcf == 'c')
			node->result[0] = va_arg(args, int);
		if (node->spcf == '%')
			node->result[0] = '%';
		if (node->spcf == 'd' || node->spcf == 'i')
			str_transfer(node->result, ft_itoa(va_arg(args, int)), node);
		if (node->spcf == 'u')
			str_transfer(node->result, ft_itoa((unsigned int)va_arg(args, int)), node);
		if (node->spcf == 'x' || node->spcf == 'X')
			str_transfer(node->result, ft_htoa(((unsigned int)va_arg(args,
			int)), node->spcf, 0), node);
		if (node->spcf == 's')
			node->size = ft_strcpy(node->result, va_arg(args, char *));
		if (node->spcf == 'p')
			str_transfer(node->result,
			ft_htoa((uintptr_t)(va_arg(args, void *)), 'x', 1), node);
		node = node->next;
	}
	return (head);
}
