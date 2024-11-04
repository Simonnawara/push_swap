/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:54:21 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/04 13:04:42 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!src || !*src)
		return ; //include error message?
	temp = *src;
	*src = (*src)->next;
	temp->next = *dest;
	*dest = temp;
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pb", 1);
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
void	test_push(void)
{
	t_stack *stack_a = NULL;
	t_stack *stack_b = NULL;

	// Initialize stack_a with values 3 -> 2 -> 1
	stack_push(&stack_a, 1, 0);
	stack_push(&stack_a, 2, 1);
	stack_push(&stack_a, 3, 2);

	printf("Initial state:\n");
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Test pb: Push top of A to B
	printf("\nPerforming pb (push top of A to B):\n");
	pb(&stack_a, &stack_b);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Test pa: Push top of B to A
	printf("\nPerforming pa (push top of B to A):\n");
	pa(&stack_a, &stack_b);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Clean up dynamically allocated memory
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(void)
{
	test_push();
	return (0);
} */