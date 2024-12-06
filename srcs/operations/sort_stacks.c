/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:50:00 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/15 09:56:31 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Moves “cheapest” node from stack `a` to stack `b` based on optimal rotations
// Determines if both nodes should rotate forward or reverse
// Aligns `a` and `b` with `cheapest_node` and its target
// Then pushes the node from `a` to `b`.
static void	push_a_to_b(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	rotate_stack(a, cheapest_node, 'a');
	rotate_stack(b, cheapest_node->target_node, 'b');
	pb(b, a, false);
}

// Pushes nodes from stack `b` back to stack `a` in optimal order.
// Rotates stack `a` to align `(*b)->target_node` at the top,
// then pushes the top of `b` to `a` to maintain sorted order.
static void	push_b_to_a(t_stack_node **a, t_stack_node **b)
{
	rotate_stack(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

// Moves the smallest number to the top
static void	min_on_top(t_stack_node **a)
{
	while ((*a)->nbr != min_lst(*a)->nbr)
	{
		if (min_lst(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

// Sorts stack `a` if it contains more than 3 nodes. 
// Pushes the first two nodes from `a` to `b` blindly, 
// Pushes nodes from `a` to `b` based on node positions until 
// `a` has three nodes left, which are sorted in-place. 
// Afterward, nodes are pushed back from `b` to `a` in sorted order.
// Final adjustments ensure all nodes in `a` are correctly indexed and aligned.
void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = get_stack_size(*a);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !is_stack_sorted(*a))
	{
		define_nodes_a(*a, *b);
		push_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		define_nodes_b(*a, *b);
		push_b_to_a(a, b);
	}
	current_index(*a);
	min_on_top(a);
}
