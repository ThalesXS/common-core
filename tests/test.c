#include <stdio.h>

int	ft_sum(int a, int b)
{
	return (a + b);
}

int ft_sub(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	int	(*op[2])(int, int);

	op[0] = ft_sum;
	op[1] = ft_sub;
	printf("%d \n", (*op[0])(2, 3));
	return (0);
}