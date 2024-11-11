/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pvalue.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:01:28 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/08 15:25:20 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//takes stack_A and stack_B

// 1. Determine pushing value of every element in stack A into the stackB.
// 2. Rotate stack_A until weakest value is on top
// 3. Rotate stack_B until biggest number is on the top of the stack
// 4. Push stack_A value to stack_B value
// 5. Repeat until 3 values are left on stack_A


int get_rot_a(t_stack **stack_a, t_stack **stack_b) //recently changed from single pointer to double pointer
{
	int i;
	int j;
	int min_rot_b;
	int min_rot_a;
	int rot_type_b;
	int rot_type_a;
	int tos; //top of stack
	int stack_a_value;
	int common_rot;
	int dif_rot;

	printf("print stack_b : ");
	print_list(*stack_b);

	printf("print stack_a : ");
	print_list(*stack_a);


/* 	if ((*stack_a)->value < find_index_up(min_lst(*stack_b), *stack_b))
	{
		if (get_node_index(min_lst(*stack_b), *stack_b) == (get_stack_size(*stack_b) - 1))
			rrb(stack_b);
		printf("DOING THE STUFF\n");
	}
 */

/* 	if (get_node_index(min_lst(*stack_b), *stack_b) == (get_stack_size(*stack_b) - 1))
		rrb(stack_b); //brings the min_list element to the top of stack
 */
	min_rot_b = min_rot_amount(*stack_a, *stack_b, &rot_type_b);
		//printf("min_rot_b : %d\n", min_rot_b);

	if (!*stack_b) {
		tos = (*stack_a)->value; // Choose the first value from `stack_a`
	} else {
		tos = max_lst(*stack_b);
	}

	stack_a_value = find_index_up(tos, *stack_a); //now we have the index of the value we want to bring up to the top of stack_a
		//printf("stack_a_value : %d\n", stack_a_value);
	if (stack_a_value == -1)
	{
    	printf("Invalid index found in find_index_up, skipping.\n");
    	return (-1); // Or continue to the next step if skipping is preferred
	}

	min_rot_a = min_rot_amount_a(stack_a_value, *stack_a, &rot_type_a); //gives us the amount of rotation needed to get the value on top of stack_a, and the rot type.
		//printf("min_rot_a : %d\n", min_rot_a);
	if (min_rot_a == -1) {
    	printf("Invalid index in min_rot_amount_a function\n");
    	return (-1); // Or handle as needed
	}

	i = 0;
	j = 0;

	if (rot_type_a == rot_type_b)
	{
		if (rot_type_a == 0 && rot_type_b == 0)
		{
			if (min_rot_b <= min_rot_a)
			{
				common_rot = min_rot_b; //number to represent the amout of rotations needed
				dif_rot = (min_rot_a - min_rot_b);
				while (i++ < common_rot)
					rr(stack_a, stack_b); //normal rotation for both stacks
				while (j++ < dif_rot)
					ra(stack_a);
			}
			else if (min_rot_a < min_rot_b)
			{
				common_rot = min_rot_a;
				dif_rot = (min_rot_b - min_rot_a);
				while (i++ < common_rot)
					rr(stack_a, stack_b);	//normal rotation for both stacks
				while (j++ < dif_rot)
					rb(stack_b);
			}
		}

		else if (rot_type_a == 1 && rot_type_b == 1)
		{
			if (min_rot_b <= min_rot_a)
			{
				common_rot = min_rot_b; //number to represent the amout of rotations needed
				dif_rot = (min_rot_a - min_rot_b);
				while (i++ < common_rot)
					rrr(stack_a, stack_b); //reverse rotation for both stacks
				while (j++ < dif_rot)
					rra(stack_a);
			}
			else if (min_rot_a < min_rot_b)
			{
				common_rot = min_rot_a;
				dif_rot = (min_rot_b - min_rot_a);
				while (i++ < common_rot)
					rrr(stack_a, stack_b);	//reverse rotation for both stacks
				while (j++ < dif_rot)
					rrb(stack_b);
			}
		}
		/* if (((*stack_a)->value < find_index_up(min_lst(*stack_b), *stack_b))
			&& get_node_index(min_lst(*stack_b), *stack_b) == (get_stack_size(*stack_b) - 1))
		{
			printf("We're in the if condition\n");
			rrb(stack_b);
		} */
	}

	else
	{
		if (rot_type_b == 0)
		{
			while(i++ < min_rot_b)
				rb(stack_b);
		}
		else if (rot_type_b == 1)
		{
			while(i++ < min_rot_b)
				rrb(stack_b);
		}

		i = 0;
		if (rot_type_a == 0)
		{
			while(i++ < min_rot_a)
				ra(stack_a);
		}
		else if (rot_type_a == 1)
		{
			while(i++ < min_rot_a)
				rra(stack_a);
		}
	}

	if ((*stack_a)->value < find_next_greater_than(min_lst(*stack_b), *stack_b) &&
		get_node_index(min_lst(*stack_b), *stack_b) == (get_stack_size(*stack_b) - 1))
	{
		printf("Condition met: performing rrb(stack_b)\n");
		rrb(stack_b);
	}

	pb(stack_b, stack_a);


	printf("print stack_b2 : ");
	print_list(*stack_b);


	return (0);
}
