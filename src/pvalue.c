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

//gets the index of the value right under the one we give in parameter inside of a stack
// actually : before calling the function, add a protection saying :
// if(value < min_lst(stack_b)) //this means that if would be the new minimun value if pushed to stack_b
// 		do something (maybe push ?)

//hasn't been tested yet
int	find_index_down(int value, t_stack *stack_b)
{
	int	max;
	int	index;
	int	current_index;

	max = value;
	index = -1;
	current_index = 0;
	while (stack_b)
	{
		if (stack_b->value < value && stack_b->value > max)
		{
			max = stack_b->value;
			index = current_index;
		}
		stack_b = stack_b->next;
		current_index++;
	}
	return (index);
}


//not tested but makes sense
int find_index_up(int value, t_stack *stack_a)
{
    int closest;
    int current_index;
    int closest_diff; // Initialize with a large value

	closest = -1;
	current_index = 0;
	closest_diff = INT_MAX;
    while (stack_a)
	{
        if (stack_a->value > value) // Check if current value is greater than the input value
		{
            if (stack_a->value - value < closest_diff) // If difference is smaller than the current closest
			{
                closest_diff = stack_a->value - value;
                closest = current_index; // Update the closest index
            }
        }
        stack_a = stack_a->next;
        current_index++;
    }
    return (closest);
}


t_stack *get_last_node(t_stack *stack)
{
    if (!stack)
        return NULL;
    while (stack->next != NULL)
        stack = stack->next;
    return stack;
}

//gets the type of rotation needed depending on the index of a value within the stack
int get_rot_type(int index, t_stack *stack_b)
{
	int sb_size;
	int fwd_rotation;
	int rev_rotation;

	fwd_rotation = 0;
	rev_rotation = 0;
	sb_size = get_stack_size(stack_b);

	if (index <= (sb_size / 2))	//on fait un rb //index <= ((sb_size / 2) + 1) ??? Idk if I add +1 or not :/
	{
		fwd_rotation = index;
		rev_rotation = ((sb_size + 1) - index);

		if (fwd_rotation <= rev_rotation)
			return (0);
		else
			return (1);
	}
	return (-1); //Error
}

int min_rot_amount_a(int index, t_stack *stack_a, int *rotation_type)
{
	int sb_size;
	int rotation;

	rotation = 0;
	sb_size = get_stack_size(stack_a);
	if (index <= ((sb_size / 2) + 1))
		rotation += index; //normal rotation
	else
		rotation += ((sb_size + 1) - index); //reverse rotation
		*rotation_type = get_rot_type(index, stack_a);
	return (rotation);
}

// gets the min amout of rotation to bring a certain value to the top of stack depending
// on the value of stack a
// it returns the "cheapest" value to push in stack_b for a variable from stack_a
int min_rot_amount(t_stack *stack_a, t_stack *stack_b, int *rotation_type)
{
	int index;
	int sb_size;
	int rotation;
	int min_rot;

	min_rot = get_stack_size(stack_b); //c'est pas possible que le nombre de rotation soit plus grand que la taille du stack elle même

	while(stack_a)
	{
		index = find_index_down(stack_a->value, stack_b);
		sb_size = get_stack_size(stack_b);
		rotation = 0;
		if (index <= ((sb_size / 2) + 1))
			rotation += index; //normal rotation
		else
			rotation += ((sb_size + 1) - index); //reverse rotation
		if (rotation < min_rot)
		{
			min_rot = rotation;
			*rotation_type = get_rot_type(index, stack_b);
		}
		stack_a = stack_a->next;
	}
	return (min_rot);
}

int get_rot_a(t_stack *stack_a, t_stack *stack_b)
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

	min_rot_b = min_rot_amount(stack_a, stack_b, &rot_type_b);
	tos = max_lst(stack_b);
	stack_a_value = find_index_up(tos, stack_a); //now we have the index of the value we want to bring up to the top of stack_a
	min_rot_a = min_rot_amount_a(stack_a_value, stack_a, rot_type_a); //gives us the amount of rotation needed to get the value on top of stack_a, and the rot type.

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

	pa(stack_a, stack_b);
}


	// get the min_rot from min_rot_amount, which gives us the amout of rotation needed for the value to go
	// on top of stack_b
	//
	// get the rotation type from get_rot_type(), which tells us the way we do the rotation.
	//
	// With these values, we can determine the value of stack b that is going to end up on the top of stack_b.
	// With the value stocked, we can then determine the value that we are looking for in stack_a. And then determine it's position
	// and the operations needed for it.














int push_value2(t_stack *stack_a, t_stack *stack_b)
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
}
