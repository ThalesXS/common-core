/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:56:26 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/22 14:49:11 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_ifexec(t_stack **stack_a, t_stack **stack_b,
			t_stack *aux[2], int size[2])
{
	if (aux[1]->current <= size[0] / 2 && aux[1]->current != 0)
		ft_rotate_with_a(stack_a, stack_b, aux, size);
	else if (aux[1]->current > size[0] / 2 && aux[1]->current != size[0] + 1)
		ft_reverse_with_a(stack_a, stack_b, aux, size);
	else
	{
		if (aux[1]->nvs <= size[1] / 2 && aux[1]->nvs != 0)
		{
			ft_rb(stack_b);
			aux[1]->nvs--;
		}
		else
			ft_rrb(stack_b);
	}
}

void	ft_rotate_with_a(t_stack **stack_a, t_stack **stack_b,
			t_stack *aux[2], int size[2])
{
	if (aux[1]->nvs <= size[1] / 2 && aux[1]->nvs != 0)
	{
		ft_rr(stack_a, stack_b);
		aux[1]->nvs--;
	}
	else
		ft_ra(stack_a);
}

void	ft_reverse_with_a(t_stack **stack_a, t_stack **stack_b,
			t_stack *aux[2], int size[2])
{
	if (aux[1]->nvs > size[1] / 2 && aux[1]->nvs != size[1])
	{
		ft_rrr(stack_a, stack_b);
		aux[1]->nvs++;
	}
	else
		ft_rra(stack_a);
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
		aux[1]->nvs--;
	}
	else if (aux[1]->current > size[0] / 2 && aux[1]->current != size[0] + 1)
	{
		if (aux[1]->nvs > size[1] / 2 && aux[1]->nvs != size[1])
			ft_rrr(stack_a, stack_b);
		else
			ft_rrb(stack_b);
		aux[1]->nvs++;
	}
	else
	{
		if (aux[1]->nvs <= size[0] / 2 && aux[1]->nvs != 0)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
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
