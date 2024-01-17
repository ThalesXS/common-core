/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:33:55 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/17 17:46:12 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	ft_stackcheck(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_argcheck(argv[i]) || ft_atol(argv[i]) < INT_MIN
			|| ft_atol(argv[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	ft_argcheck(char *arg)
{
	while (*arg)
	{
		if ((*arg < '0' || *arg > '9') && *arg != '-' && *arg != ' ')
			return (0);
		arg++;
	}
	return (1);
}

t_stack	*ft_newstack(char *value, t_stack **value_n1)
{
	t_stack		*newstack;
	t_stack		*temp;
	static int	index;

	if (!value_n1)
		index = 0;
	temp = *value_n1;
	if (ft_atol(value) > INT_MAX || ft_atol(value) < INT_MIN)
		ft_error(value_n1);
	newstack = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!newstack)
		ft_error(value_n1);
	newstack->content = ft_atol(value);
	newstack->current = index++;
	newstack->dest = 0;
	newstack->nvs = 0;
	if (temp)
	{
		while ((temp)->next)
			(temp) = (temp)->next;
		(temp)->next = newstack;
	}
	newstack->prev = temp;
	newstack->next = NULL;
	return (newstack);
}

int	ft_cleanstack(t_stack **stack)
{
	t_stack	*nextnode;

	if (stack)
	{
		while (*stack)
		{
			nextnode = (*stack)->next;
			free(*stack);
			*stack = nextnode;
		}
	}
	return (1);
}

void	ft_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return ;
		temp = temp->next;
	}
	exit(0);
}
