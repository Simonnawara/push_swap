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


void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_b, t_stack **stack_a);

void	reverse_rotate(t_stack **stack);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

void	rotate(t_stack **stack);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);

void	swap(t_stack *stack);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);

int get_max(t_stack *stack);
void radix_sort(t_stack **stack_a, t_stack **stack_b);
void counting_sort(t_stack **stack_a, t_stack **stack_b, int exp);
int is_sorted(t_stack *stack);
void free_stack(t_stack **stack);
void print_stack(t_stack *stack);

#endif