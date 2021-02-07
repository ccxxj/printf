/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/18 13:46:06 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/07 17:40:28 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_listclear(t_ptflist *lst)
{
	t_ptflist	*head;
	t_ptflist	*next;

	head = lst;
	while (head)
	{
		next = head->next;
		free(head->result);
		head->result = NULL;
		free(head);
		head = NULL;
		head = next;
	}
}

int		ft_print(t_ptflist *node)
{
	t_ptflist	*head;
	int			a;

	a = 0;
	head = node;
	while (node)
	{
		a = a + ft_putstr(node->beginning);
		ft_process(node);
		a = a + node->check_c + ft_putstr(node->result);
		node = node->next;
	}
	ft_listclear(head);
	return (a);
}

void	width_adp(int a, t_ptflist *node)
{
	if (a < 0)
	{
		node->neg_width = 1;
		node->left_justify = 1;
		node->width = -(node->tempw);
	}
	else
		node->width = node->tempw;
}

int		ft_printf(const char *str, ...)
{
	va_list		args;
	t_ptflist	*node;
	int			return_va;

	va_start(args, str);
	node = ft_break(str);
	if (!node)
	{
		ft_listclear(node);
		va_end(args);
		return (-1);
	}
	node = ft_replace(node, args);
	if (!node)
	{
		ft_listclear(node);
		va_end(args);
		return (-1);
	}
	return_va = ft_print(node);
	return (return_va);
}
