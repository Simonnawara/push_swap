/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:54:34 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/04 11:43:59 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;

	// Find the second last element
	second_last = *stack;
	while (second_last->next->next)
		second_last = second_last->next;

	// Separate the last node and place it at the beginning
	last = second_last->next;
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putendl_fd("rrr", 1);
}



/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

/* void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		fprintf(fd == 1 ? stdout : stderr, "%s\n", s);
	}
}

void	print_stack(t_stack *stack, char *name)
{
	printf("Stack %s: ", name);
	while (stack)
	{
		printf("[%d] ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

t_stack	*new_node(int value, int index)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}

void	stack_push(t_stack **stack, int value, int index)
{
	t_stack	*node = new_node(value, index);
	node->next = *stack;
	*stack = node;
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
void	test_rotate(void)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;

	// Initialize stack_a with values 3 -> 2 -> 1
	stack_push(&stack_a, 1, 0);
	stack_push(&stack_a, 2, 1);
	stack_push(&stack_a, 3, 2);

	// Initialize stack_b with values 6 -> 5 -> 4
	stack_push(&stack_b, 4, 0);
	stack_push(&stack_b, 5, 1);
	stack_push(&stack_b, 6, 2);

	printf("Initial state:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Test rra: Reverse rotate stack A
	printf("\nPerforming rra (reverse rotate stack A):\n");
	rra(&stack_a);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Test rrb: Reverse rotate stack B
	printf("\nPerforming rrb (reverse rotate stack B):\n");
	rrb(&stack_b);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Test rrr: Reverse rotate both stacks
	printf("\nPerforming rrr (reverse rotate both stacks):\n");
	rrr(&stack_a, &stack_b);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Clean up dynamically allocated memory
	free_stack(&stack_a);
	free_stack(&stack_b);
}


int	main(void)
{
	test_rotate();
	return (0);
} */