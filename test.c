#include <stdio.h>
#include "ft_printf.h"

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

// int main()
// {
// 	char *str;
// 	t_ptflist test;

// 	test.result = (char *)malloc(100 * sizeof(char));

// 	// str = (char *)malloc(100 * sizeof(char));
// 	// ft_leftexpand(2, 5, str + 1, 65);
// 	ft_leftexpand(1000, 5, test.result, 65);
// 	printf("str is %s\n", test.result);
// 	return (0);
// }

int main()
{
	t_ptflist	*a;

	a = malloc(sizeof(t_ptflist));
	// if (!a)
	// 	return (NULL);
	a->left_justify = -1;
	// a->precision = -1;
	// a->width = -1;
	a->temp = 0;
	a->tempw = 0;
	a->size = 2;
	a->check_c = 0;
	a->neg_width = -1;
	a->next = NULL;
	ft_bzero(a->beginning, 1000);
	a->result = ft_calloc(1001, sizeof(char));
	// ft_bzero(a->result, 1000);
	ft_bzero(a->flag, 30);
	a->zero = -1;





	a->width = 1234;
	a->precision = 6;
	a->result = (char *)malloc(3 * sizeof(char));
	a->result[0] = '2';
	a->result[1] = '2';
	printf("result is %s", a->result);
	a->spcf = 'd';
	// node->result[3] = '\0';
	// node->next = NULL;

	ft_process(a);
	printf("sr is %s", a->result);
}