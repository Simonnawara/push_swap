/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pvalue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:01:28 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/04 23:01:28 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//takes stack_A and stack_B

// 1. Determine pushing value of every element in stack A into the stackB.
// 2. Rotate stack_A until weakest value is on top
// 3. Rotate stack_B until biggest number is on the top of the stack
// 4. Push stack_A value to stack_B value
// 5. Repeat until 3 values are left on stack_A

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

	max = stack_b->value;
	while (stack_b)
	{
		if (stack_b->value > max)
			max = stack_b->value;
		stack_b = stack_b->next;
	}
	return (max);
}

t_stack *get_last_node(t_stack *stack)
{
    if (!stack)
        return NULL;
    while (stack->next != NULL)
        stack = stack->next;
    return stack;
}

int push_value(t_stack *stack_a, t_stack *stack_b)
{
	//this function will have to be called with stack_b with 2 values from stack_a.
	//function only gets called if stack_b has 2 values min
	int	i;
	int	count;
	int	min;
	int	max;
	t_stack *last_b;

	i = 0;
	count = 0;
	while (stack_a)
	{
		count++;
		stack_a = stack_a->next;
	}
	count -= 3; //because we're stopping until there is 3 elements left in stack_a

	min = 0;
	max = 0;
	last_b = get_last_node(stack_b);
	while ((i < count) && stack_a)
	{
		min = min_lst(stack_b);
		max = max_lst(stack_b);
		//actually follow the algorithm described in :
		// https://medium.com/@ayogun/push-swap-c1f5d2d41e97
		if ((stack_a->value < min) &&
			(stack_b->value == min || (last_b && last_b->value == min)))
			pa(&stack_a, &stack_b); //this counts as a 1 for push expense, which automatically makes it the cheapest one, so the first one to use.
		stack_a = stack_a->next;
		i++;
	}

	return (0);
}
