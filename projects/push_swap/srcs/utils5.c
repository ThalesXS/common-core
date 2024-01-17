/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:47:35 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/17 22:19:15 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_exec(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux[2];
	int		size[2];

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
	while (aux[1]->cost > 1)
	{
		ft_ifexec(stack_a, stack_b, aux, size);
	}
	ft_pb(stack_b, stack_a);
}

void	ft_rexec(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux[2];
	int		size[2];

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
	while (aux[1]->cost > 1 && size[1] >= 1)
	{
		ft_ifrexec(stack_a, stack_b, aux, size);
	}
	ft_pa(stack_a, stack_b);
}

void	ft_rd(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux;
	t_stack	*bux;

	aux = *stack_a;
	bux = *stack_b;
	while (aux)
	{
		if (aux->current <= a_size / 2)
			aux->cost = aux->current;
		else
			aux->cost = a_size - aux->current;
		aux = aux->next;
	}
	while (bux)
	{
		if (bux->current <= b_size / 2)
			bux->cost = bux->current + 1;
		else
			bux->cost = b_size - bux->current + 1;
		bux = bux->next;
	}
	ft_rd2(stack_a, stack_b, a_size, b_size);
}

void	ft_rd2(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux;
	t_stack	*bux;
	t_stack	*save_aux;
	t_stack	*biggest;

	bux = *stack_b;
	biggest = ft_biggestdest(stack_a);
	while (bux)
	{
		aux = *stack_a;
		save_aux = biggest;
		while (aux)
		{
			if (aux->dest <= save_aux->dest && aux->dest > bux->dest)
				save_aux = aux;
			else if (biggest->dest < bux->dest)
				save_aux = ft_smallestdest(stack_a);
			bux->cost = bux->current + 1 + save_aux->cost;
			bux->nvs = save_aux->current;
			ft_cost3(b_size, a_size, &bux, save_aux);
			aux = aux->next;
		}
		bux = bux->next;
	}
}

void	printall(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *sa;
	t_stack	*sb;

	sa = *stack_a;
	sb = *stack_b;
	while (sa)
	{
		ft_printf("A: V = %d, T = %d, C = %d\n", sa->content, sa->target->dest, sa->cost); //APAGAR++++++++++++
		sa = sa->next;
	}
	ft_putchar_fd('\n', 1);
	while (sb)
	{
		ft_printf("B: V = %d, T = %d, C = %d\n", sb->content, 0, 0); //APAGAR++++++++++++
		sb = sb->next;
	}
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('\n', 1);
}