/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:03:21 by resilva           #+#    #+#             */
/*   Updated: 2023/12/09 21:36:32 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	swap(t_stack_node **stack)
{
	int	len;

	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_stack_node **a, bool check)
{
	swap(a);
	if (!check)
		write (1, "sa\n", 3);
}

void	sb(t_stack_node **b, bool check)
{
	swap(b);
	if (!check)
		write (1, "sb\n", 3);
}

void	ss(t_stack_node **a, t_stack_node **b, bool check)
{
	swap(a);
	swap(b);
	if (!check)
		write (1, "ss\n", 3);
}
