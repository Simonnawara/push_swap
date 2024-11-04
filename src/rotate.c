/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:54:37 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/04 11:33:36 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;

	// Traverse to the end and append `first` there
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = first;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", 1);
}


/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////

void	ft_putendl_fd(char *s, int fd)
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

	// Test ra: Rotate stack A
	printf("\nPerforming ra (rotate stack A):\n");
	ra(&stack_a);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Test rb: Rotate stack B
	printf("\nPerforming rb (rotate stack B):\n");
	rb(&stack_b);
	print_stack(stack_a, "A");
	print_stack(stack_b, "B");

	// Test rr: Rotate both stack A and stack B
	printf("\nPerforming rr (rotate both stacks):\n");
	rr(&stack_a, &stack_b);
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
}