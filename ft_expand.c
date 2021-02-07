/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_expand.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 10:49:05 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/07 17:42:50 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_realloc(char *str, size_t n, size_t size)
{
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = (char *)malloc((n + size + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strcpy(new_str, str);
	free(str);
	str = NULL;
	return (new_str);
}

char	*ft_leftexpand(int n, int size, char *str, char c)
{
	if (n < 0)
		return (str);
	if (n + size > 1000)
	{
		str = ft_realloc(str, n, size);
		if (!str)
			return (NULL);
	}
	while (size > 0)
	{
		str[n + size - 1] = str[size - 1];
		size--;
	}
	while (n > 0)
	{
		str[n - 1] = c;
		n--;
	}
	return (str);
}

char	*ft_rightexpand(int n, int size, char *str, char c)
{
	if (n + size > 1000)
	{
		str = ft_realloc(str, n, size);
		if (!str)
			return (NULL);
	}
	while (n > 0 && size >= 0)
	{
		str[size + n - 1] = c;
		n--;
	}
	return (str);
}
