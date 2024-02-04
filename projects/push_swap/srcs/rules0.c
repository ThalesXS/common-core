/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:29:17 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/02 18:45:29 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*new_top;
	t_stack	*next;

	new_top = (*stack)->next;
	next = *stack;
	if (new_top)
	{
		next->next = new_top->next;
		new_top->next = next;
		new_top->prev = 0;
		next->prev = new_top;
		next->next->prev = next;
		*stack = new_top;
	}
}

void	ft_push(t_stack **stack_dst, t_stack **stack_source)
{
	t_stack	*new_top_dst;
	t_stack	*new_top_source;

	if ((*stack_source)->next)
		new_top_source = (*stack_source)->next;
	else
		new_top_source = 0;
	new_top_dst = (*stack_source);
	if (new_top_source)
		new_top_source->prev = 0;
	if ((*stack_dst))
	{
		new_top_dst->next = (*stack_dst);
		(*stack_dst)->prev = new_top_dst;
	}
	else
		new_top_dst->next = 0;
	(*stack_source) = new_top_source;
	(*stack_dst) = new_top_dst;
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*new_bottom;

	new_bottom = (*stack);
	(*stack) = (*stack)->next;
	(*stack)->prev = 0;
	temp = (*stack);
	while (temp->next)
		temp = temp->next;
	temp->next = new_bottom;
	new_bottom->prev = temp;
	new_bottom->next = 0;
	new_bottom->current = new_bottom->prev->current - 1;
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*new_top;

	temp = (*stack);
	while (temp->next)
		temp = temp->next;
	new_top = temp;
	(temp->prev)->next = 0;
	(*stack)->prev = new_top;
	new_top->prev = 0;
	new_top->next = (*stack);
	(*stack) = new_top;
	new_top->current = new_top->next->current - 1;
}
