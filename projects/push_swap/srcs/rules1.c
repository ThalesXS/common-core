/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:31:42 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/02 18:45:06 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	ft_reset(stack_a);
	ft_printf("sa\n");
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	ft_reset(stack_a);
	ft_reset(stack_b);
	ft_printf("pa\n");
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	ft_reset(stack_a);
	ft_printf("ra\n");
}

void	ft_rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	ft_reset(stack_a);
	ft_printf("rra\n");
}
