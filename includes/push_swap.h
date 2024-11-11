/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 14:55:43 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/04 15:07:08 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_stack
{
	int	value;
	int index;
	struct s_stack *next;
} t_stack;

// push //
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);

// swap //
void	swap(t_stack *stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

// normal rotate //
void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

// reverse rotate //
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);


// get_rot_data //
int find_index_up(int value, t_stack *stack_a);
int	find_index_down(int value, t_stack *stack_b);
int get_rot_type(int index, t_stack *stack_b);
int min_rot_amount(t_stack *stack_a, t_stack *stack_b, int *rotation_type);
int min_rot_amount_a(int index, t_stack *stack_a, int *rotation_type);

// pvalue_utils //
int	min_lst(t_stack *stack_b);
int	max_lst(t_stack *stack_b);
int get_stack_size(t_stack *stack);
int get_last_node_index(t_stack *stack);
int get_last_node_value(t_stack *stack);
t_stack *get_last_node(t_stack *stack);
int get_node_index(int value, t_stack *stack);
int find_next_greater_than(int value, t_stack *stack);

// pvalue //
int get_rot_a(t_stack **stack_a, t_stack **stack_b);

// first_steps //
int check_and_push(t_stack **stack_a);

// main //
void print_list(t_stack *head);
#endif