/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:48:47 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/22 14:49:29 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

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
