/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:46:33 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/22 12:10:16 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_twostack(t_stack **stack_a)
{
	ft_ra(stack_a);
}

void	ft_threestack(t_stack **stack_a)
{
	int		index;
	t_stack	*aux;

	aux = *stack_a;
	index = 0;
	ft_newtstack(stack_a);
	while (aux)
	{
		index = aux->intstack + index * 10;
		aux = aux->next;
	}
	if (index == 102)
		ft_sa(stack_a);
	else if (index == 201)
		ft_ra(stack_a);
	else if (index == 120)
		ft_rra(stack_a);
	else if (index != 12)
		ft_sa(stack_a);
	if (index == 21)
		ft_ra(stack_a);
	else if (index == 210)
		ft_rra(stack_a);
}

void	ft_newtstack(t_stack **stack)
{
	t_stack	*aux;

	aux = *stack;
	if (aux->dest > aux->next->dest && aux->dest > aux->next->next->dest)
		aux->intstack = 2;
	else if (aux->dest > aux->next->dest || aux->dest > aux->next->next->dest)
		aux->intstack = 1;
	else
		aux->intstack = 0;
	if (aux->next->dest > aux->dest && aux->next->dest > aux->next->next->dest)
		aux->next->intstack = 2;
	else if (aux->next->dest > aux->dest
		|| aux->next->dest > aux->next->next->dest)
		aux->next->intstack = 1;
	else
		aux->next->intstack = 0;
	if (aux->next->next->dest > aux->dest
		&& aux->next->next->dest > aux->next->dest)
		aux->next->next->intstack = 2;
	else if (aux->next->next->dest > aux->dest
		|| aux->next->next->dest > aux->next->dest)
		aux->next->next->intstack = 1;
	else
		aux->next->next->intstack = 0;
}

void	ft_biggerstack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top;
	int		a_size;

	top = ft_smallestdest(stack_a);
	ft_pb(stack_b, stack_a);
	ft_pb(stack_b, stack_a);
	ft_target(stack_a, stack_b);
	ft_sort_b(stack_a, stack_b);
	a_size = ft_stacksize(stack_a);
	while ((*stack_a)->dest != 0)
	{
		if (top->current <= a_size / 2)
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}

void	ft_sort_b(t_stack **stack_a, t_stack **stack_b)
{
	int	a_size;
	int	b_size;

	a_size = ft_stacksize(stack_a);
	b_size = ft_stacksize(stack_b);
	while (a_size > 3 || a_size == 2)
	{
		ft_cost(stack_a, stack_b, a_size, b_size);
		ft_exec(stack_a, stack_b, a_size, b_size);
		a_size--;
		b_size++;
	}
	if (a_size == 3)
		ft_threestack(stack_a);
	ft_targetrd(stack_a, stack_b);
	while (b_size > 0)
	{
		ft_rd(stack_a, stack_b, a_size, b_size);
		ft_rexec(stack_a, stack_b, a_size, b_size);
		b_size--;
		a_size++;
	}
}
