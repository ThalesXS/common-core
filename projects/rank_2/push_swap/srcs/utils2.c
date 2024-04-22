/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:45:44 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/17 17:57:53 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_repeated(t_stack **stack)
{
	t_stack	*i;
	t_stack	*j;

	i = (*stack);
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (i->content == j->content)
				ft_error(stack);
			j = j->next;
		}
		i = i->next;
	}
}

void	ft_error(t_stack **stack)
{
	ft_putstr_fd("Error\n", 2);
	exit(ft_cleanstack(stack));
}

int	ft_stacksize(t_stack **stack)
{
	int		i;
	t_stack	*aux;

	aux = *stack;
	i = 0;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

void	ft_dest(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*actual;

	actual = *stack;
	while (actual)
	{
		aux = *stack;
		while (aux)
		{
			if (actual->content > aux->content)
				actual->dest++;
			aux = aux->next;
		}
		actual = actual->next;
	}
}

void	ft_reset(t_stack **stack_a)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = *stack_a;
	while (aux)
	{
		aux->current = i;
		i++;
		aux = aux->next;
	}
}
