/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:47:02 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/17 18:09:53 by txisto-d         ###   ########.fr       */
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
	ft_cost2(stack_a, stack_b, a_size, b_size);
}

void	ft_cost2(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux[2];
	t_stack	*save_b[2];

	aux[0] = *stack_a;
	save_b[1] = ft_smallestdest(stack_b);
	while (aux[0])
	{
		aux[1] = *stack_b;
		save_b[0] = save_b[1];
		while (aux[1])
		{
			if (aux[1]->dest >= save_b[0]->dest && aux[1]->dest < aux[0]->dest)
				save_b[0] = aux[1];
			else if (save_b[1]->dest > aux[0]->dest)
				save_b[0] = ft_biggestdest(stack_b);
			if (aux[0]->current <= a_size / 2)
				aux[0]->cost = aux[0]->current + 1 + save_b[0]->cost;
			else
				aux[0]->cost = a_size - aux[0]->current + 1 + save_b[0]->cost;
			aux[0]->nvs = save_b[0]->current;
			ft_cost3(a_size, b_size, &aux[0], save_b[0]);
			aux[1] = aux[1]->next;
		}
		aux[0] = aux[0]->next;
	}
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
