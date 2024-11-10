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

	min = stack_b->value;
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
        return (-5);
	}
	max = stack_b->value;
	while (stack_b)
	{
		if (stack_b->value > max)
			max = stack_b->value;
		stack_b = stack_b->next;
	}
	return (max);
}

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

t_stack *get_last_node(t_stack *stack)
{
    if (!stack)
        return NULL;
    while (stack->next != NULL)
        stack = stack->next;
    return stack;
}