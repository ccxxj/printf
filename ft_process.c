/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_process.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 10:56:54 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/07 22:18:03 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_expand(int n, int size, char *str, t_ptflist *node)
{
	if (node->left_justify == -1 && node->zero == -1)
	{
		if ((node->spcf == 'd' || node->spcf == 'i') && str[0] == '-')
			str = ft_leftexpand(n - 1, size + 1, str, ' ');
		else
			str = ft_leftexpand(n, size, str, ' ');
	}
	if (node->left_justify == -1 && node->zero == 1)
	{
		if ((node->spcf == 'd' || node->spcf == 'i') && str[0] == '-')
			ft_leftexpand(n - 1, size, str + 1, '0');
		else
			str = ft_leftexpand(n, size, str, '0');
	}
	if (node->left_justify == 1 && (node->zero == -1 || node->zero == 1))
	{
		if ((node->spcf == 'd' || node->spcf == 'i') && str[0] == '-')
			str = ft_rightexpand(n - 1, size + 1, str, ' ');
		else
			str = ft_rightexpand(n, size, str, ' ');
	}
	return (str);
}

void	nbrprocess(t_ptflist *node)
{
	int	len;

	len = node->size > node->precision ? node->size : node->precision;
	if (node->precision >= 0)
		node->zero = -1;
	if (node->precision == 0 && node->result[0] == '0' &&
	node->result[1] == '\0')
	{
		if (node->width == 0 || node->width == -1)
			node->result[0] = '\0';
		else
			node->result[0] = ' ';
	}
	else if (node->precision > node->size)
	{
		if (node->result[0] == '-')
			ft_leftexpand(len - node->size, node->size, node->result + 1, '0');//need to adjust//change method
		else
			// node->result = ft_leftexpand(len - node->size, node->size, node->result, '0');
			ft_leftexpand(len - node->size, node->size, node->result, '0');
	}
	if (node->width > len)
		node->result = ft_expand(node->width - len, len, node->result, node);
}

void	ft_process(t_ptflist *node)
{
	if (node->spcf == 'd' || node->spcf == 'i' || node->spcf == 'u'
	|| node->spcf == 'x' || node->spcf == 'X')
		nbrprocess(node);
	if (node->spcf == 's' || node->spcf == 'p')
	{
		if (node->spcf == 's' && node->precision >= 0 &&
		node->precision < node->size)
		{
			ft_bzero(node->result + node->precision,
			node->size - node->precision);
			node->size = node->precision;
		}
		if (node->width > node->size)
			node->result = ft_expand(node->width - node->size, node->size, node->result, node);
	}
	if (node->spcf == 'c' || node->spcf == '%')
	{
		if (node->spcf == 'c' && node->result[0] == '\0')
		{
			node->check_c = 1;
			node->result = ft_expand(node->width - 1, 0, node->result, node);
		}
		else
			node->result = ft_expand(node->width - 1, 1, node->result, node);
	}
}
