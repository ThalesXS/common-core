/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:33:55 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/02 18:44:51 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

int	ft_stackcheck(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_argcheck(argv[i]) || ft_atol(argv[i]) < INT_MIN
			|| ft_atol(argv[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	ft_argcheck(char *arg)
{
	while (*arg)
	{
		if ((*arg < '0' || *arg > '9') && *arg != '-' && *arg != ' ')
			return (0);
		arg++;
	}
	return (1);
}

t_stack	*ft_newstack(char *value, t_stack **value_n1)
{
	t_stack		*newstack;
	t_stack		*temp;
	static int	index;

	if (!value_n1)
		index = 0;
	temp = *value_n1;
	if (ft_atol(value) > INT_MAX || ft_atol(value) < INT_MIN)
		ft_error(value_n1);
	newstack = (t_stack *) ft_calloc(1, sizeof(t_stack));
	if (!newstack)
		ft_error(value_n1);
	newstack->content = ft_atol(value);
	newstack->current = index++;
	newstack->dest = 0;
	newstack->nvs = 0;
	if (temp)
	{
		while ((temp)->next)
			(temp) = (temp)->next;
		(temp)->next = newstack;
	}
	newstack->prev = temp;
	newstack->next = NULL;
	return (newstack);
}

int	ft_cleanstack(t_stack **stack)
{
	t_stack	*nextnode;

	if (stack)
	{
		while (*stack)
		{
			nextnode = (*stack)->next;
			free(*stack);
			*stack = nextnode;
		}
	}
	return (1);
}

void	ft_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp->next)
	{
		if (temp->content > temp->next->content)
			return ;
		temp = temp->next;
	}
	exit(0);
}

void	ft_repeated(t_stack **stack)
{
	t_stack	*i;
	t_stack	*j;

	i = (*stack);
	while (i->next)
	{
		j = i->next;
		while (j)
		{
			if (i->content == j->content)
				ft_error(stack);
			j = j->next;
		}
		i = i->next;
	}
}

void	ft_error(t_stack **stack)
{
	ft_putstr_fd("Error\n", 2);
	exit(ft_cleanstack(stack));
}

int	ft_stacksize(t_stack **stack)
{
	int		i;
	t_stack	*aux;

	aux = *stack;
	i = 0;
	while (aux)
	{
		aux = aux->next;
		i++;
	}
	return (i);
}

void	ft_dest(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*actual;

	actual = *stack;
	while (actual)
	{
		aux = *stack;
		while (aux)
		{
			if (actual->content > aux->content)
				actual->dest++;
			aux = aux->next;
		}
		actual = actual->next;
	}
}

void	ft_reset(t_stack **stack_a)
{
	int		i;
	t_stack	*aux;

	i = 0;
	aux = *stack_a;
	while (aux)
	{
		aux->current = i;
		i++;
		aux = aux->next;
	}
}

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
	while (b_size > 0)
	{
		ft_rd(stack_a, stack_b, a_size, b_size);
		ft_rexec(stack_a, stack_b, a_size, b_size);
		b_size--;
		a_size++;
	}
}

t_stack	*ft_smallestdest(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*save;

	aux = *stack;
	save = aux;
	while (aux)
	{
		if (aux->dest < save->dest)
			save = aux;
		aux = aux->next;
	}
	return (save);
}

t_stack	*ft_biggestdest(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*save;

	aux = *stack;
	save = aux;
	while (aux)
	{
		if (aux->dest > save->dest)
			save = aux;
		aux = aux->next;
	}
	return (save);
}

void	ft_cost(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*bux;

	bux = *stack_b;
	while (bux)
	{
		if (bux->current <= b_size / 2)
			bux->cost = bux->current;
		else
			bux->cost = b_size - bux->current;
		bux = bux->next;
	}
	ft_cost2(stack_a, stack_b, a_size, b_size);
}

void	ft_cost2(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux;
	t_stack	*bux;
	t_stack	*save_bux;
	t_stack	*smallest;

	aux = *stack_a;
	smallest = ft_smallestdest(stack_b);
	while (aux)
	{
		bux = *stack_b;
		save_bux = smallest;
		while (bux)
		{
			if (bux->dest >= save_bux->dest && bux->dest < aux->dest)
				save_bux = bux;
			else if (smallest->dest > aux->dest)
				save_bux = ft_biggestdest(stack_b);
			if (aux->current <= a_size / 2)
				aux->cost = aux->current + 1 + save_bux->cost;
			else
				aux->cost = a_size - aux->current + 1 + save_bux->cost;
			aux->nvs = save_bux->current;
			ft_cost3(a_size, b_size, &aux, save_bux);
			bux = bux->next;
		}
		aux = aux->next;
	}
}

void	ft_cost3(int len_a, int len_b, t_stack **aux, t_stack *save_b)
{
	t_stack	*temp;
	int		i;
	int		limit;
	int		change;

	temp = *aux;
	i = 0;
	limit = temp->cost - save_b->cost - 1;
	change = 0;
	if (temp->current <= len_a / 2 && save_b->current <= len_b / 2
		&& temp->current != 0 && save_b->current != 0)
		change = 1;
	else if (temp->current > len_a / 2 && save_b->current > len_b / 2)
		change = 1;
	if (change == 1)
	{
		while (i < save_b->cost && i < limit)
		{
			temp->cost--;
			i++;
		}
	}
}

void	ft_exec(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux;
	t_stack	*act;

	aux = *stack_a;
	act = aux;
	while (aux)
	{
		if (aux->cost < act->cost)
			act = aux;
		aux = aux->next;
	}
	while (act->cost > 1)
	{
		if (act->current <= a_size / 2 && act->current != 0)
		{
			if (act->nvs <= b_size / 2 && act->nvs != 0)
				ft_rr(stack_a, stack_b);
			else
				ft_ra(stack_a);
		}
		else if (act->current > a_size / 2 && act->current != a_size)
		{
			if (act->nvs > b_size / 2 && act->nvs != b_size)
				ft_rrr(stack_a, stack_b);
			else
			{
				ft_rra(stack_a);
			}
		}
		else
		{
			if (act->nvs <= b_size / 2 && act->nvs != 0)
				ft_rb(stack_b);
			else
				ft_rrb(stack_b);
		}
		ft_cost(stack_a, stack_b, a_size, b_size);
	}
	ft_pb(stack_b, stack_a);
}

void	ft_rexec(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size)
{
	t_stack	*aux;
	t_stack	*act;

	aux = *stack_b;
	act = aux;
	while (aux)
	{
		if (aux->cost < act->cost)
			act = aux;
		aux = aux->next;
	}
	while (act->cost > 1 && b_size >= 1)
	{
		if (act->current <= a_size / 2 && act->current != 0)
		{
			if (act->nvs <= b_size / 2 && act->nvs != 0)
				ft_rr(stack_a, stack_b);
			else
				ft_rb(stack_b);
		}
		else if (act->current > a_size / 2 && act->current != a_size)
		{
			if (act->nvs > b_size / 2 && act->nvs != b_size)
				ft_rrr(stack_a, stack_b);
			else
				ft_rrb(stack_b);
		}
		else
		{
			if (act->nvs <= b_size / 2 && act->nvs != 0)
				ft_ra(stack_a);
			else
				ft_rra(stack_a);
		}
		ft_rd(stack_a, stack_b, a_size, b_size);
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
