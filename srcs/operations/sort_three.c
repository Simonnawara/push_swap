/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:03:28 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/15 09:58:04 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Rotates the largest element of the stack to the bottom.
// Checks the first two nodes are in ascending order.
// If not, swap them with sa(a, false) to complete the sorting.
void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = max_lst(*a);
	if (biggest_node == *a)
		ra(a, false);
	else if ((*a)->next == biggest_node)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

// Rotates both the top `a` and `b` nodes to
// the bottom of their stacks, if it's the cheapest move
void	rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}

// Rotates both the bottom `a` and `b` nodes to
// the top of their stacks, if it's the cheapest move
void	rev_rotate_both(t_stack_node **a, t_stack_node **b,
		t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}
