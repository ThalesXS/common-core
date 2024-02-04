/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:33:53 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/02 18:47:48 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	i = 1;
	stack_a = NULL;
	if (ft_stackcheck(argc, argv) && argc > 2)
	{
		while (i < argc)
		{
			if (!stack_a)
				stack_a = ft_newstack(argv[i], &stack_a);
			else
				ft_newstack(argv[i], &stack_a);
			i++;
		}
		ft_sort(&stack_a);
		ft_cleanstack(&stack_a);
	}
	else if (argc == 2 && ft_stackcheck(argc, argv))
		ft_inquotes(argv[1]);
	else if (!ft_stackcheck(argc, argv))
		ft_putstr_fd("Error\n", 2);
	return (0);
}

void	ft_inquotes(char *string)
{
	int		i;
	char	**argv;
	t_stack	*stack_a;

	i = 0;
	argv = ft_split(string, ' ');
	stack_a = NULL;
	if (argv[1] != 0)
	{
		while (argv[i])
		{
			if (!stack_a)
				stack_a = ft_newstack(argv[i], &stack_a);
			else
				ft_newstack(argv[i], &stack_a);
			i++;
		}
		ft_sort(&stack_a);
		ft_cleanstack(&stack_a);
	}
	i = 0;
	while (argv[i])
		free(argv[i++]);
	free(argv);
}

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		size;

	stack_b = NULL;
	while (stack_b)
	{
		ft_printf("%d\n", stack_b->content);
		stack_b = stack_b->next;
	}
	size = ft_stacksize(stack_a);
	ft_repeated(stack_a);
	ft_sorted(stack_a);
	ft_dest(stack_a);
	if (size == 2)
		ft_twostack(stack_a);
	else if (size == 3)
		ft_threestack(stack_a);
	else
		ft_biggerstack(stack_a, &stack_b);
}
