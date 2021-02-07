/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: Xiaojing <Xiaojing@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/29 11:32:59 by Xiaojing      #+#    #+#                 */
/*   Updated: 2021/02/07 16:44:35 by Xiaojing      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
// #include <stdint.h>
#include "ft_printf.h"

/*
when the number is negative, below situation:
1. precision + width both above 0, only pad 0 when precision bigger than size(not includ -) even if there is 0 flag
2. when only with width, pad 0 after - if there is 0 flag
*/


int main()
{
	char *a;
	a = "cdesd";
	
	// ft_printf("%\n");
	// printf("%\n");
	
	// ft_printf(123);
	// printf(123);

	// int		aa = -4;
	// int		b = 0;
	char	c = 'a';
	// int		d = 2147483647;
	// int		e = -2147483648;
	// int		f = 42;
	// int		g = 25;
	// int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	// char	*o = "-a";
	// char	*p = "-12";
	// char	*q = "0";
	// char	*r = "%%";
	// char	*s = "-2147483648";
	// char	*t = "0x12345678";
	// char	*u = "-0";

	// ft_printf("");
	// printf("");

	ft_printf("result is %d\n", ft_printf("this is ddddddddddddddddddddd kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n"));
	printf("result is %d\n", printf("this is ddddddddddddddddddddd kkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk\n"));

	ft_printf("result is %d\n", ft_printf("what is %0.6d\n", 12345));
	printf("result is %d\n", printf("what is %0.6d\n", 12345));

	ft_printf("result is %d\n", ft_printf("what is %5c\n", 'd'));
	printf("result is %d\n", printf("what is %5c\n", 'd'));

	ft_printf("result is %d\n", ft_printf("what is %5s\n", a));
	printf("result is %d\n", printf("what is %5s\n", a));

	ft_printf("result is %d\n", ft_printf("what is %10c\n", 'd'));
	printf("result is %d\n", printf("what is %10c\n", 'd'));

	ft_printf("result is %d\n", ft_printf("what is %*.6d\n", -10, 12345));
	printf("result is %d\n", printf("what is %*.6d\n",-10, 12345));

	ft_printf("result is %d\n", ft_printf("what is %-*.6d\n", -10, 12345));
	printf("result is %d\n", printf("what is %-*.6d\n", 10, 12345));

	ft_printf("result is %d\n", ft_printf("what is %0*.6d\n", -10, 12345));
	printf("result is %d\n", printf("what is %0*.6d\n", -10, 12345));

	ft_printf("result is %d\n", ft_printf("what is %*.6d %5c %x\n", 1234, 22, 'a', 55));
	printf("result is %d\n", printf("what is %*.6d %5c %x\n", 1234, 22, 'a', 55));

	ft_printf("result is %d\n", ft_printf("what is %*.6d\n", 1234, 22));
	printf("result is %d\n", printf("what is %*.6d\n", 1234, 22));

	system("leaks a.out");

	// ft_printf("what is %0-10.6d\n", 12345);//if input * is -10, printf can handle 0 + -, ignore the 0
	// printf("what is %0-10.6d\n", 12345);

	ft_printf("result is %d\n", ft_printf("what is %010.6i\n", -12345));
	printf("result is %d\n", printf("what is %010.6i\n", -12345));

	ft_printf("result is %d\n", ft_printf("what is %10.6i\n", -12));
	printf("result is %d\n", printf("what is %10.6i\n", -12));

	ft_printf("result is %d\n", ft_printf("what is %0.6u\n", -12345));
	printf("result is %d\n", printf("what is %0.6u\n", -12345));//real print f function print undefined behavior

	ft_printf("result is %d\n", ft_printf("today is %*x\n", 123, 555));//22b345 it is printing some left over from last node
	printf("result is %d\n", printf("today is %*x\n", 123, 555));//22b

	ft_printf("result is %d\n", ft_printf("today is %*X\n", 123, 555));//same as above -> check
	printf("result is %d\n", printf("today is %*X\n", 123, 555));//same as above

	ft_printf("result is %d\n", ft_printf("the address is %100p\n", &a));//left justified (no need, to change)
	printf("result is %d\n", printf("the address is %100p\n", &a));

	ft_printf("result is %d\n", ft_printf("the address is %*p\n", 10, &a));
	printf("result is %d\n", printf("the address is %*p\n", 10, &a));

	ft_printf("result is %d\n", ft_printf("the address is %-*p\n", 50, &a));//need to make sure the sequency: *- does not work, but -* works -> add some condition
	printf("result is %d\n", printf("the address is %-*p\n", 50, &a));

	ft_printf("result is %d\n", ft_printf("what is %0.6d and blabalbal is %50.60s yeah%%\n", 12345, a));//space wrong, it take 60 instead of 50->should only take the smaller one???
	printf("result is %d\n", printf("what is %0.6d and blabalbal is %50.60s yeah%%\n", 12345, a));

	ft_printf("result is %d\n", ft_printf("what is %010i\n", -12345));
	printf("result is %d\n", printf("what is %010i\n", -12345));

	ft_printf("result is %d\n", ft_printf("what is %010.5i\n", -12345));
	printf("result is %d\n", printf("what is %010.5i\n", -12345));

	ft_printf("result is %d\n", ft_printf("what is %010.6i\n", -12345));
	printf("result is %d\n", printf("what is %010.6i\n", -12345));

	ft_printf("result is %d\n", ft_printf("what is %0.8i\n", -12345));
	printf("result is %d\n", printf("what is %0.8i\n", -12345));
	
	ft_printf("result is %d\n", ft_printf("what is %02i\n", -12345));
	printf("result is %d\n", printf("what is %02i\n", -12345));

	ft_printf("return is %d\n", ft_printf("%12.12i, %12.12d", -42, 42));
	printf("return is %d\n", printf("%12.12i, %12.12d", -42, 42));

	ft_printf("result is %d\n", ft_printf("test string precision %.0saa\n", a));
	printf("result is %d\n", printf("test string precision %.0saa\n", a));

	ft_printf("result is %d\n", ft_printf("test string precision %10.0saa\n", a));
	printf("result is %d\n", printf("test string precision %10.0saa\n", a));

	ft_printf("result is %d\n", ft_printf("test string precision %2.0saa\n", a));
	printf("result is %d\n", printf("test string precision %2.0saa\n", a));

	ft_printf("result is %d\n", ft_printf("test string precision %*.0saa\n", -10, a));
	printf("result is %d\n", printf("test string precision %*.0saa\n", -10, a));

	ft_printf("result is %d\n", ft_printf("test string precision %10.1saa\n", a));
	printf("result is %d\n", printf("test string precision %10.1saa\n", a));

	ft_printf("result is %d\n", ft_printf("test string precision %10.*saa\n", -2, a));
	printf("result is %d\n", printf("test string precision %10.*saa\n", -2, a));

	ft_printf("result is %d\n", ft_printf("test string precision %2.*saa\n", -2, a));
	printf("result is %d\n", printf("test string precision %2.*saa\n", -2, a));

	ft_printf("result is %d\n", ft_printf("test character %5caa\n", 0));
	printf("result is %d\n", printf("test character %5caa\n", 0));
	
	ft_printf("result is %d\n", ft_printf("test character %*caa\n", 0, 66));
	printf("result is %d\n", printf("test character %*caa\n", 0, 66));

	ft_printf("result is %d\n", ft_printf("test character %*.caa\n", 0, 66));
	printf("result is %d\n", printf("test character %*.caa\n", 0, 66));

	// ft_printf("result is %d", ft_printf("test character %*.*caa\n", 0, 5, 66));
	// printf("result is %d", printf("test character %*.*caa\n", 0, 5, 66));
	
	ft_printf("result is %d\n", ft_printf("test character %5caa\n", 66));
	printf("result is %d\n", printf("test character %5caa\n", 66));
	
	ft_printf("result is %d\n", ft_printf("test character %*caa\n", -5, 66));
	printf("result is %d\n", printf("test character %*caa\n", -5, 66));
	
	ft_printf("result is %d\n", ft_printf("test character %-*caa\n", -5, 66));
	printf("result is %d\n", printf("test character %-*caa\n", -5, 66));
	
	ft_printf("result is %d\n", ft_printf("test percentage %%%%aa\n"));
	printf("result is %d\n", printf("test percentage %%%%aa\n"));

	ft_printf("result is %d\n", ft_printf("test percentage %u\n", -10));
	printf("result is %d\n", printf("test percentage %u\n", -10));

	ft_printf("result is %d\n", ft_printf("test percentage %x\n", -12));
	printf("result is %d\n", printf("test percentage %x\n", -12));

	ft_printf("result is %d\n", ft_printf("test percentage %X\n", -12));
	printf("result is %d\n", printf("test percentage %X\n", -12));

	ft_printf(" --- Return : %d\n", ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j));
	printf(" --- Return : %d\n", printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j));

	ft_printf("result is  %d\n", ft_printf("test null %s\n", NULL));
	printf("result is  %d\n", printf("test null %s\n", NULL));

	ft_printf("result is  %d\n", ft_printf("test multiple %*.*d %c %10c %10.5x %s\n", -10, 5, 22, 65, 'c', 333, "yes"));
	printf("result is  %d\n", printf("test multiple %*.*d %c %10c %10.5x %s\n", -10, 5, 22, 65, 'c', 333, "yes"));

	ft_printf("result is  %d\n", ft_printf("test multiple %10.5x\n", 333));
	printf("result is  %d\n", printf("test multiple %10.5x\n", 333));

	// ft_printf("what is %i\n");
	// printf("what is %i\n");
	
	return (0);
}