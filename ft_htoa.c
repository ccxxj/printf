/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_htoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/31 13:22:25 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/07 17:43:23 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

size_t	ft_hlen(size_t n)
{
	size_t	len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void	dealp(char *str, int len)
{
	ft_strlcpy2(str + 2, str, len);
	str[0] = '0';
	str[1] = 'x';
}

void	hexprocess(size_t n, size_t len, char c, char *str)
{
	size_t	a;

	while (n > 0)
	{
		a = n % 16;
		if (a > 9)
			str[len - 1] = c + a - 33;
		else
			str[len - 1] = a + '0';
		len--;
		n = n / 16;
	}
}

char	*ft_htoa(unsigned long long int n, char c, int i)
{
	char	*str;
	size_t	len;
	size_t	lenth;

	lenth = ft_hlen(n);
	len = lenth;
	str = (char *)malloc((len + 3) * sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, len + 3);
	if (n == 0)
	{
		str[len] = '0';
		lenth = 1;
	}
	hexprocess(n, len, c, str);
	if (i == 1)
		dealp(str, lenth);
	return (str);
}
