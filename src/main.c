/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:46:05 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/04 16:47:15 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

//https://medium.com/@ayogun/push-swap-c1f5d2d41e97

/* static int check_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1); // Duplicate found
		stack = stack->next;
	}
	return (0);
} */

static int is_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0); // Not a valid digit
		str++;
	}
	return (1);
}

void print_list(t_stack *head)
{
	while (head) {
		ft_printf("%d ", head->value);
		head = head->next;
	}
	ft_printf("\n");
}

void free_list(t_stack *head)
{
	t_stack *temp;
	while (head) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

/////////////////   Create and fill linked list   /////////////////


t_stack *create_node(int value)
{
	t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		exit(EXIT_FAILURE); //handle malloc failure ?
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

void append_node(t_stack **head, int value)
{
	t_stack *new_node = create_node(value);
	if(!*head)
		*head = new_node;
	else
	{
		t_stack *temp = *head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

int	parse_and_append(t_stack **stack, char *str)
{
	long num;

	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		return (-1);
	append_node(stack, (int)num);
	return (0);
}

int main(int argc, char **argv)
{
	t_stack	*stack_a;
	int		i;

	stack_a = NULL;
	i = 1;
	if (argc < 2)
	{
		ft_putendl_fd("Error: No arguments provided", 2);
		return (0);
	}
	while (i < argc)
	{
		if (!is_number(argv[i]) ||
			(parse_and_append(&stack_a, argv[i]) == -1))
			{
				ft_putendl_fd("Error", 2);
				free_list(stack_a);
				exit(EXIT_FAILURE);
			}
		i++;
	}


	ft_putendl_fd("Stack contents:", 1);
	print_list(stack_a);
	printf("\n");
	check_and_push(&stack_a);
	free_list(stack_a);
	return (0);
}
