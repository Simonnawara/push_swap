/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:54:39 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/04 13:07:17 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || stack->next == NULL)
		return ; //include error message?
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putendl_fd("ss", 1);
}

//////////////////////////////////////////////////////////////////////////////////////////


/* void	print_stack(t_stack *stack, char *name)
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

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		fprintf(fd == 1 ? stdout : stderr, "%s\n", s);
	}
}


void	test_swap(void)
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

	// Test sa: Swap top of A
	printf("\nPerforming sa (swap top of A):\n");
	sa(&stack_a);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Test sb: Swap top of B
	printf("\nPerforming sb (swap top of B):\n");
	sb(&stack_b);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Test ss: Swap top of A and B simultaneously
	printf("\nPerforming ss (swap top of A and B):\n");
	ss(&stack_a, &stack_b);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Test sa on a single-element stack
	free_stack(&stack_a);
	stack_push(&stack_a, 1, 0);

	printf("\nSingle-element stack A test:\n");
	print_stack(stack_a, "A");
	sa(&stack_a);
	print_stack(stack_a, "A");

	// Clean up dynamically allocated memory
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(void)
{
	test_swap();
	return (0);
} */