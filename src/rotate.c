/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:54:37 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/02 11:54:37 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;

	// Traverse to the end and append `first` there
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
}

void	ra(t_stack **stack_a)
{
	rotate(*stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(*stack_b);
	ft_putendl_fd("rb", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	rotate(*stack_a);
	rotate(*stack_b);
	ft_putendl_fd("rr", 1);
}