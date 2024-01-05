/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: txisto-d <txisto-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 15:03:19 by txisto-d          #+#    #+#             */
/*   Updated: 2024/01/02 18:48:33 by txisto-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*prev;
	int				current;
	int				dest;
	int				cost;
	int				stacksize;
	int				nvs;
	int				intstack;
}	t_stack;

void	ft_swap(t_stack **stack);
void	ft_push(t_stack **stack_dst, t_stack **stack_source);
void	ft_rotate(t_stack **stack);
void	ft_reverse_rotate(t_stack **stack);
void	ft_sa(t_stack **stack_a);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rra(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_pb(t_stack **stack_b, t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rrb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_sort(t_stack **stack_a);
void	ft_inquotes(char *string);
int		ft_stackcheck(int argc, char **argv);
int		ft_argcheck(char *arg);
t_stack	*ft_newstack(char *value, t_stack **value_n1);
int		ft_cleanstack(t_stack **stack);
void	ft_sorted(t_stack **stack);
void	ft_repeated(t_stack **stack);
void	ft_error(t_stack **stack);
int		ft_stacksize(t_stack **stack);
void	ft_dest(t_stack **stack);
void	ft_reset(t_stack **stack_a);
void	ft_twostack(t_stack **stack_a);
void	ft_threestack(t_stack **stack_a);
void	ft_newtstack(t_stack **stack);
void	ft_biggerstack(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_b(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_smallestdest(t_stack **stack);
t_stack	*ft_biggestdest(t_stack **stack);
void	ft_cost(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size);
void	ft_cost2(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size);
void	ft_cost3(int len_a, int len_b, t_stack **aux, t_stack *save_b);
void	ft_exec(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size);
void	ft_rexec(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size);
void	ft_rd(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size);
void	ft_rd2(t_stack **stack_a, t_stack **stack_b, int a_size, int b_size);

#endif