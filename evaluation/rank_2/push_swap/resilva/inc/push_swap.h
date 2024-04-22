/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: resilva <resilva@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:51:45 by resilva           #+#    #+#             */
/*   Updated: 2023/12/13 23:28:21 by resilva          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	int					final_index;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

// Handle errors
void			free_av(char **av);
void			free_stack(t_stack_node **stack);
int				error_duplicate(t_stack_node *a, int n);
int				error_syntax(char *str);
void			free_errors(t_stack_node **a, char **av, int ac);

// Stack initiation
bool			stack_sorted(t_stack_node *stack);
void			init_stack_a(t_stack_node **a, char **av, int ac);

// Nodes initiation
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
char			**ft_split(char *s, char c);

// Stack utils
t_stack_node	*find_cheapest(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *node);
int				stack_len(t_stack_node *stack);

// Commands
void			pa(t_stack_node **a, t_stack_node **b, bool check);
void			pb(t_stack_node **b, t_stack_node **a, bool check);
void			rra(t_stack_node **a, bool check);
void			rrb(t_stack_node **b, bool check);
void			rrr(t_stack_node **a, t_stack_node **b, bool check);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			ra(t_stack_node **a, bool check);
void			rb(t_stack_node **b, bool check);
void			rr(t_stack_node **a, t_stack_node **b, bool check);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			sa(t_stack_node **a, bool check);
void			sb(t_stack_node **b, bool check);
void			ss(t_stack_node **a, t_stack_node **b, bool check);

// Algorithms
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			push_to_b(t_stack_node **b, t_stack_node **a);

#endif