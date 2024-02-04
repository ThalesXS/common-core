/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 01:38:18 by resilva           #+#    #+#             */
/*   Updated: 2023/12/06 00:10:17 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	rev_rotate(t_stack_node **stack)
{
	int				len;
	t_stack_node	*last;

	len = stack_len(*stack);
	if (!(*stack) || !stack || len == 1)
		return ;
	last = find_last(*stack);
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
	last->prev->next = NULL;
	last->prev = NULL;
}

void	rra(t_stack_node **a, bool check)
{
	rev_rotate(a);
	if (!check)
		write (1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool check)
{
	rev_rotate(b);
	if (!check)
		write (1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool check)
{
	rev_rotate(a);
	rev_rotate(b);
	if (!check)
		write (1, "rrr\n", 4);
}

void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*b != cheapest_node && *a != cheapest_node->target_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}
