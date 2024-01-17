/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:56:26 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/17 18:56:37 by txisto-d         ###   ########.fr       */
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
