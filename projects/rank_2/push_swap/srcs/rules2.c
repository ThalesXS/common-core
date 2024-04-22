/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:32:26 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/22 10:57:37 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	ft_reset(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
	ft_reset(stack_a);
	ft_reset(stack_b);
	ft_putstr_fd("pb\n", 1);
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	ft_reset(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	ft_reset(stack_b);
	ft_putstr_fd("rrb\n", 1);
}
