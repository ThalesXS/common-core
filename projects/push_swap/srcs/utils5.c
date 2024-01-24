/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:47:35 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/22 11:26:37 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_exec(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux[2];
	int		size[2];
	int		act_cost;

	aux[0] = *stack_a;
	aux[1] = aux[0];
	size[0] = a_size;
	size[1] = b_size;
	while (aux[0])
	{
		if (aux[0]->cost < aux[1]->cost)
			aux[1] = aux[0];
		aux[0] = aux[0]->next;
	}
	act_cost = aux[1]->cost;
	while (act_cost > 1)
	{
		ft_ifexec(stack_a, stack_b, aux, size);
		act_cost--;
	}
	ft_pb(stack_b, stack_a);
}

void	ft_rexec(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux[2];
	int		size[2];
	int		act_cost;

	aux[0] = *stack_b;
	aux[1] = aux[0];
	size[0] = a_size;
	size[1] = b_size;
	while (aux[0])
	{
		if (aux[0]->cost < aux[1]->cost)
			aux[1] = aux[0];
		aux[0] = aux[0]->next;
	}
	act_cost = aux[1]->cost;
	while (act_cost > 1 && size[1] >= 1)
	{
		ft_ifrexec(stack_a, stack_b, aux, size);
		act_cost--;
	}
	ft_pa(stack_a, stack_b);
}

void	ft_rd(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux;

	aux = *stack_a;
	while (aux)
	{
		if (aux->current <= a_size / 2)
			aux->cost = aux->current;
		else
			aux->cost = a_size - aux->current;
		aux = aux->next;
	}
	ft_newrd(stack_a, stack_b, a_size, b_size);
}

void	ft_newrd(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux;
	t_stack	*bux;

	bux = *stack_b;
	if ((*stack_a)->target)
		ft_newtargetrd(stack_a, stack_b);
	while (bux)
	{
		aux = *stack_a;
		while (aux)
		{
			if (bux->current <= b_size / 2)
				bux->cost = bux->current + 1 + bux->target->cost;
			else
				bux->cost = b_size - bux->current + 1 + bux->target->cost;
			bux->nvs = bux->target->current;
			ft_cost3(a_size, b_size, &bux, bux->target);
			aux = aux->next;
		}
		bux = bux->next;
	}
}

void	ft_targetrd(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*bux;
	t_stack	*new_targ;

	bux = *stack_b;
	while (bux)
	{
		aux = *stack_a;
		new_targ = ft_biggestdest(stack_a);
		while (aux)
		{
			if (bux->dest < aux->dest && aux->dest < new_targ->dest)
				new_targ = aux;
			aux = aux->next;
		}
		if (new_targ->dest < bux->dest)
			new_targ = ft_smallestdest(stack_a);
		bux->target = new_targ;
		bux = bux->next;
	}
}
