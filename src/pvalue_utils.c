/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pvalue_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:33:28 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/09 20:33:28 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	min_lst(t_stack *stack_b)
{
	int	min;

	if(!stack_b)
	{
		ft_printf("Error, empty stack");
        return (INT_MAX); // Use INT_MAX to indicate an error state
	}

	min = INT_MAX;
	while (stack_b)
	{
		if (stack_b->value < min)
			min = stack_b->value;
		stack_b = stack_b->next;
	}
	return (min);
}

int	max_lst(t_stack *stack_b)
{
	int	max;

	if (!stack_b) // Handle empty stack
	{
		ft_printf("Error, empty stack");
        return (INT_MIN);
	}
	max = INT_MIN;
	while (stack_b)
	{
		if (stack_b->value > max)
			max = stack_b->value;
		stack_b = stack_b->next;
	}
	return (max);
}

/* int	min_lst(t_stack *stack_b)
{
	int	min;

	min = stack_b->value;
	while (stack_b)
	{
		if (stack_b->value < min)
			min = stack_b->value;
		stack_b = stack_b->next;
	}
	return (min);
} */

/* int	max_lst(t_stack *stack_b)
{
	int	max;

	if (!stack_b) // Handle empty stack
	{
		ft_printf("Error, empty stack");
        return (-1);
	}
	max = stack_b->value;
	while (stack_b)
	{
		if (stack_b->value > max)
			max = stack_b->value;
		stack_b = stack_b->next;
	}
	return (max);
} */

//pour calculer le type de rotation necessaire (normal vs reverse)
int get_stack_size(t_stack *stack)
{
	int size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int get_last_node_index(t_stack *stack)
{
    int index = 0;

    if (!stack)
        return (-1); // indicates an empty stack
    while (stack->next != NULL)
    {
        stack = stack->next;
        index++;
    }
    return index;
}

int get_last_node_value(t_stack *stack)
{
    if (!stack)
        return (-1);
    while (stack->next != NULL)
        stack = stack->next;
    return stack->value;
}

t_stack *get_last_node(t_stack *stack) {
    if (!stack) return NULL;
    while (stack->next)
        stack = stack->next;
    return stack;
}

int get_node_index(int value, t_stack *head)
{
    int index;
    t_stack *current;

	index = 0;
	current = head;
    while (current != NULL) {
        if (current->value == value) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1; // Value not found
}


int find_next_greater_than(int value, t_stack *stack)
{
	int next_greater = INT_MAX;
	int found = 0;

	while (stack) {
		if (stack->value > value && stack->value < next_greater) {
			next_greater = stack->value;
			found = 1;
		}
		stack = stack->next;
	}
	return (found ? next_greater : INT_MAX);
}

/* int find_next_greater_than(int value, t_stack *stack)
{
    int closest = -1; // Initialize to indicate no closest found
    int min_diff = INT_MAX;
    t_stack *current = stack;

    while (current) {
        int diff = current->value - value;
        if (diff > 0 && diff < min_diff) { // Closest positive difference
            min_diff = diff;
            closest = current->value;
        }
        current = current->next;
    }
    if (closest == -1) // No greater found, so get smallest value
        closest = min_lst(stack);
    return closest;
} */
