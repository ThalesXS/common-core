/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:47:02 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/18 12:59:08 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

t_stack	*ft_smallestdest(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*save;

	aux = *stack;
	save = aux;
	while (aux)
	{
		if (aux->dest < save->dest)
			save = aux;
		aux = aux->next;
	}
	return (save);
}

t_stack	*ft_biggestdest(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*save;

	aux = *stack;
	save = aux;
	while (aux)
	{
		if (aux->dest > save->dest)
			save = aux;
		aux = aux->next;
	}
	return (save);
}

void	ft_cost(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*bux;

	bux = *stack_b;
	while (bux)
	{
		if (bux->current <= b_size / 2)
			bux->cost = bux->current;
		else
			bux->cost = b_size - bux->current;
		bux = bux->next;
	}
	ft_newcost(stack_a, stack_b, a_size, b_size);
}

void	ft_cost3(int len_a, int len_b, t_stack **aux, t_stack *save_b)
{
	t_stack	*temp;
	int		i;
	int		limit;
	int		change;

	temp = *aux;
	i = 0;
	limit = temp->cost - save_b->cost - 1;
	change = 0;
	if (temp->current <= len_a / 2 && save_b->current <= len_b / 2
		&& temp->current != 0 && save_b->current != 0)
		change = 1;
	else if (temp->current > len_a / 2 && save_b->current > len_b / 2)
		change = 1;
	if (change == 1)
	{
		while (i < save_b->cost && i < limit)
		{
			temp->cost--;
			i++;
		}
	}
}

void	ft_newcost(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux;
	t_stack	*bux;

	aux = *stack_a;
	if ((*stack_b)->target)
		ft_newtarget(stack_a, stack_b);
	while (aux)
	{
		bux = *stack_b;
		while (bux)
		{
			if (aux->current <= a_size / 2)
				aux->cost = aux->current + 1 + aux->target->cost;
			else
				aux->cost = a_size - aux->current + 1 + aux->target->cost;
			aux->nvs = aux->target->current;
			ft_cost3(a_size, b_size, &aux, aux->target);
			bux = bux->next;
		}
		aux = aux->next;
	}
}
