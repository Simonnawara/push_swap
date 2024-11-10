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

	min_rot_b = min_rot_amount(*stack_a, *stack_b, &rot_type_b);
		printf("min_rot_b : %d\n", min_rot_b);

	tos = max_lst(*stack_b); //stack_n is empty, so it's trying to go through an empty list
		printf("tos (max number in stack b) : %d\n", tos);

	stack_a_value = find_index_up(tos, *stack_a); //now we have the index of the value we want to bring up to the top of stack_a
		printf("stack_a_value : %d\n", stack_a_value);
	if (stack_a_value == -1)
	{
    	printf("Invalid index found in find_index_up, skipping.\n");
    	return (-1); // Or continue to the next step if skipping is preferred
	}

	min_rot_a = min_rot_amount_a(stack_a_value, *stack_a, &rot_type_a); //gives us the amount of rotation needed to get the value on top of stack_a, and the rot type.
		printf("min_rot_a : %d\n", min_rot_a);
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
	pb(stack_b, stack_a);
	printf("print stack_b2 : ");
	print_list(*stack_b);
	return (0);
}
















	// get the min_rot from min_rot_amount, which gives us the amout of rotation needed for the value to go
	// on top of stack_b
	//
	// get the rotation type from get_rot_type(), which tells us the way we do the rotation.
	//
	// With these values, we can determine the value of stack b that is going to end up on the top of stack_b.
	// With the value stocked, we can then determine the value that we are looking for in stack_a. And then determine it's position
	// and the operations needed for it.

/* int push_value2(t_stack *stack_a, t_stack *stack_b)
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
		// actually follow the algorithm described in :
		// https://medium.com/@ayogun/push-swap-c1f5d2d41e97
		if ((stack_a->value < min) &&
			(stack_b->value == min || (last_b && last_b->value == min)))
			pa(&stack_a, &stack_b); //this counts as a 1 for push expense, which automatically makes it the cheapest one, so the first one to use.
		//if ()
		// ...

		stack_a = stack_a->next;
		i++;
	}

	return (0);
} */
