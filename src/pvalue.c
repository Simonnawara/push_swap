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

int	pvalue(int value, t_stack *stack_b)
{
	int	min;
	int max;

	min = stack_b->value;
	max = stack_b->value;
	while (stack_b)
	{
		if (stack_b->value < stack_b->next-> value)
			rb(&stack_b);
		if (stack_b->value < min)
			min = stack_b->value;
		if (stack_b->value > max)
			max = stack_b->value;
		stack_b = stack_b->next;
	}
	ft_printf("Min: %d, Max: %d\n", min, max);

	if (value > max)
	{
		max = value;
	}
	else if (value < min)
	{
		min = value;
	}
	else
	{

	}
	return (0);
}
