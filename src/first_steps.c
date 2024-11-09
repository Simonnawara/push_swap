/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_steps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:33:38 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/09 20:33:38 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int check_and_push(t_stack **stack_a)
{
	int stack_size;
	t_stack *stack_b;

	stack_b = NULL;
	stack_size = get_stack_size(*stack_a);
	if(stack_size >= 3)
	{
		pb(&stack_b, stack_a); //pushing the first 2 values on top of stack b;
		pb(&stack_b, stack_a); // " " " " " " " " " " " " " " " " " " " " " "
		stack_size = get_stack_size(*stack_a);
		if (stack_size <= 3)
		{
			//go to the bruteforce algorithm
		}
		else
		{
			while (stack_size > 0) // I can change it to stack_size > 3 to add the bruteforce method.
			{
				get_rot_a(stack_a, &stack_b);
				stack_size--;
			}
		}
		//go to bruteforce algorithm
	}
	return (0);

}