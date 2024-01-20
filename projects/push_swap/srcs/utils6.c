/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:56:26 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/18 13:01:46 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_ifexec(t_stack **stack_a, t_stack **stack_b,
			t_stack *aux[2], int size[2])
{
	if (aux[1]->current <= size[0] / 2 && aux[1]->current != 0)
	{
		if (aux[1]->nvs <= size[1] / 2 && aux[1]->nvs != 0)
			ft_rr(stack_a, stack_b);
		else
			ft_ra(stack_a);
	}
	else if (aux[1]->current > size[0] / 2 && aux[1]->current != size[0])
	{
		if (aux[1]->nvs > size[1] / 2 && aux[1]->nvs != size[1])
			ft_rrr(stack_a, stack_b);
		else
		{
			ft_rra(stack_a);
		}
	}
	else
	{
		if (aux[1]->nvs <= size[1] / 2 && aux[1]->nvs != 0)
			ft_rb(stack_b);
		else
			ft_rrb(stack_b);
	}
	ft_cost(stack_a, stack_b, size[0], size[1]);
}

void	ft_ifrexec(t_stack **stack_a, t_stack **stack_b,
			t_stack *aux[2], int size[2])
{
	if (aux[1]->current <= size[0] / 2 && aux[1]->current != 0)
	{
		if (aux[1]->nvs <= size[1] / 2 && aux[1]->nvs != 0)
			ft_rr(stack_a, stack_b);
		else
			ft_rb(stack_b);
	}
	else if (aux[1]->current > size[0] / 2 && aux[1]->current != size[0])
	{
		if (aux[1]->nvs > size[1] / 2 && aux[1]->nvs != size[1])
			ft_rrr(stack_a, stack_b);
		else
			ft_rrb(stack_b);
	}
	else
	{
		if (aux[1]->nvs <= size[1] / 2 && aux[1]->nvs != 0)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
	ft_rd(stack_a, stack_b, size[0], size[1]);
}

void	ft_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*bux;
	t_stack	*bux2;

	aux = *stack_a;
	bux = *stack_b;
	bux2 = bux->next;
	while (aux)
	{
		if ((aux->dest > bux->dest && bux->dest > bux2->dest)
			|| (bux->dest > bux2->dest && bux2->dest > aux->dest)
			|| (bux2->dest > aux->dest && aux->dest > bux->dest))
			aux->target = bux;
		else
			aux->target = bux2;
		aux = aux->next;
	}
}

void	ft_newtarget(t_stack **stack_a, t_stack **new_b)
{
	t_stack	*aux;
	t_stack	*bux;
	t_stack	*targ;

	aux = *stack_a;
	bux = *new_b;
	while (aux)
	{
		targ = aux->target;
		if ((aux->dest > bux->dest && bux->dest > targ->dest)
			|| (bux->dest > targ->dest && targ->dest > aux->dest)
			|| (targ->dest > aux->dest && aux->dest > bux->dest))
			aux->target = bux;
		aux = aux->next;
	}
}

void	ft_newtargetrd(t_stack **new_a, t_stack **stack_b)
{
	t_stack	*aux;
	t_stack	*bux;
	t_stack	*targ;

	aux = *new_a;
	bux = *stack_b;
	while (bux)
	{
		targ = bux->target;
		if ((aux->dest > bux->dest && bux->dest > targ->dest)
			|| (bux->dest > targ->dest && targ->dest > aux->dest)
			|| (targ->dest > aux->dest && aux->dest > bux->dest))
			bux->target = aux;
		bux = bux->next;
	}
}
