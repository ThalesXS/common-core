/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:47:49 by resilva           #+#    #+#             */
/*   Updated: 2023/12/18 20:56:28 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	final_index(t_stack_node *a, int len_a)
{
	t_stack_node	*curr_index;
	t_stack_node	*temp;
	int				temp_n;

	while (--len_a)
	{
		temp = a;
		temp_n = INT_MIN;
		curr_index = NULL;
		while (temp)
		{
			if (temp->nbr == INT_MIN && temp->final_index == 0)
				temp->final_index = 1;
			else if (temp->nbr > temp_n && temp->final_index == 0)
			{
				temp_n = temp->nbr;
				curr_index = temp;
			}
			else
				temp = temp->next;
		}
		if (curr_index)
			curr_index->final_index = len_a + 1;
	}
}

void	push_to_b(t_stack_node **b, t_stack_node **a)
{
	int	len_a;
	int	len_b;
	int	i;

	len_a = stack_len(*a);
	len_b = 0;
	i = 0;
	final_index(*a, len_a);
	while (len_a > 5 && i < len_a && len_b < len_a / 2)
	{
		if ((*a)->final_index <= len_a / 2)
		{
			pb(b, a, false);
			len_b++;
		}
		else
			ra(a, false);
		i++;
	}
	while (len_a - len_b > 3)
	{
		pb(b, a, false);
		len_b++;
	}
}
