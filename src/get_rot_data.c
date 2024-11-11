/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rot_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:22:55 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/09 16:22:55 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//not tested but makes sense
int find_index_up(int value, t_stack *stack_a)
{
    int closest;
    int current_index;
    int closest_diff; // Initialize with a large value
	int max_list_index;
	int max_value;

	closest = -1; //changed, was -1 before
	current_index = 0;
	closest_diff = INT_MAX;
	max_list_index = -1;
	max_value = max_lst(stack_a);

    while (stack_a)
	{
        if (stack_a->value > value || (stack_a->value == 0 && value < 0)) // Check if current value is greater than the input value
		{
            if ((stack_a->value - value) < closest_diff) // If difference is smaller than the current closest
			{
                closest_diff = stack_a->value - value;
                closest = current_index; // Update the closest index
            }
        }

		if(stack_a->value == max_value)
			max_list_index = current_index;
        stack_a = stack_a->next;
        current_index++;
    }
	if (closest == -1)
	{
        printf("max_lst(stack_a) because closest = -1 for value: %d\n", value);
		return (max_list_index);
    }
    return (closest);
}


/* int find_index_up(int value, t_stack *stack_a) {
    int closest = -1;
    int current_index = 0;
    int closest_diff = INT_MAX;

    while (stack_a) {
        if (stack_a->value > value) {
            if (stack_a->value - value < closest_diff) {
                closest_diff = stack_a->value - value;
                closest = current_index;
            }
        }
        stack_a = stack_a->next;
        current_index++;
    }

    if (closest == -1) {
        printf("No valid index found in find_index_up for value: %d\n", value);
    }

    return closest;
} */


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
	int min_list_index;
	int min_value;
	int found;

	max = INT_MIN;
	index = 0;
	current_index = 0;
	min_list_index = -1;
	min_value = INT_MAX;
	found = 0;
	while (stack_b)
	{
		if ((stack_b->value < value && stack_b->value > max) || (stack_b->value == 0 && value > 0))
		{
			max = stack_b->value;
			index = current_index;
			found = 1;
		}

		// Track the index of the smallest element in the stack
		if (stack_b->value < min_value)
		{
			min_value = stack_b->value;
			min_list_index = current_index;
		}
		stack_b = stack_b->next;
		current_index++;
	}

	if(!found)
	{
		printf("Returning min_list_index because closest = -1 for value: %d\n", value);
		return (min_list_index);
	}
	return (index);

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

// gets the min amout of rotation to bring a certain value to the top of stack depending
// on the value of stack a
// it returns the "cheapest" value to push in stack_b for a variable from stack_a
int min_rot_amount(t_stack *stack_a, t_stack *stack_b, int *rotation_type)
{
	int index;
	int sb_size;
	int rotation;
	int min_rot;

	if (!stack_b || get_stack_size(stack_b) == 0) // Handle empty stack_b
	{
		ft_printf("Stack_b empty in min_rot_amount function\n");
        return (-1); //was 0 previously
	}

	min_rot = get_stack_size(stack_b); //c'est pas possible que le nombre de rotation soit plus grand que la taille du stack elle même
	while(stack_a)
	{
		index = find_index_down(stack_a->value, stack_b);
		if (index == -1) // If index not found
			index = min_lst(stack_b);
		sb_size = get_stack_size(stack_b);
		rotation = 0;
		if (index <= (sb_size / 2)) //if (index <= ((sb_size / 2) + 1)) before, changed to chatgpt version
			rotation = index; //normal rotation
		else
			rotation = (sb_size - index); //reverse rotation //rotation = ((sb_size + 1) - index); before, now changed to chatgpt version
		if (rotation < min_rot)
		{
			min_rot = rotation;
			*rotation_type = get_rot_type(index, stack_b);
		}
		stack_a = stack_a->next;
	}
	return (min_rot);
}

/* int min_rot_amount_a(int index, t_stack *stack_a, int *rotation_type)
{
	int sb_size;
	int rotation;

	rotation = 0;
	sb_size = get_stack_size(stack_a);

 	if (index == -1 || sb_size == 0) // Handle invalid index
    {
        *rotation_type = -1;
		ft_printf("invalid index in min_rot_amount_a function\n");
        return (-1);
    }


	if (index <= (sb_size / 2)) //if (index <= ((sb_size / 2) + 1)) before, changed to chatgpt version
		rotation = index; //normal rotation
	else
		rotation = (sb_size - index); //reverse rotation //rotation = ((sb_size + 1) - index); before, changed to chatgpt version
	*rotation_type = get_rot_type(index, stack_a);
	return (rotation);
} */



int min_rot_amount_a(int index, t_stack *stack_a, int *rotation_type) {
    int sb_size = get_stack_size(stack_a);
    if (index == -1) {
        *rotation_type = -1;
        return -1;
    }

    if (index <= sb_size / 2) {
        *rotation_type = 0; // Normal rotation
        return index;
    } else {
        *rotation_type = 1; // Reverse rotation
        return sb_size - index;
    }
}

