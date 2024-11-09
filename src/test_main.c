#include "../includes/push_swap.h"

void print_list(t_stack *head)
{
	while (head) {
		ft_printf("%d ", head->value);
		head = head->next;
	}
	ft_printf("\n");
}

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

void free_list(t_stack *head)
{
	t_stack *temp;
	while (head) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

int main(void)
{
    // Create sample stacks for testing
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    // Fill stack_a with test data
    append_node(&stack_a, 3);
    append_node(&stack_a, 1);
    append_node(&stack_a, 8);
    append_node(&stack_a, 5);

    // Print initial stack state
    ft_putendl_fd("Initial Stack A:", 1);
    print_list(stack_a);

    // Test rotation functions
    ft_putendl_fd("\nTesting ra (rotate stack_a):", 1);
    ra(&stack_a);
    print_list(stack_a);

    ft_putendl_fd("\nTesting rra (reverse rotate stack_a):", 1);
    rra(&stack_a);
    print_list(stack_a);

    // Test push function (pa and pb)
    ft_putendl_fd("\nTesting pb (push top of stack_a to stack_b):", 1);
    pb(&stack_b, &stack_a);
    ft_putendl_fd("Stack A after pb:", 1);
    print_list(stack_a);
    ft_putendl_fd("Stack B after pb:", 1);
    print_list(stack_b);

    ft_putendl_fd("\nTesting pa (push top of stack_b to stack_a):", 1);
    pa(&stack_a, &stack_b);
    ft_putendl_fd("Stack A after pa:", 1);
    print_list(stack_a);
    ft_putendl_fd("Stack B after pa:", 1);
    print_list(stack_b);

    // Test swap functions
    ft_putendl_fd("\nTesting sa (swap first two elements of stack_a):", 1);
    sa(&stack_a);
    print_list(stack_a);

    // Test get_rot_data functions
    int index_up = find_index_up(4, stack_a);
    ft_printf("\nIndex of first element greater than 4 in stack_a: %d\n", index_up);

    int index_down = find_index_down(6, stack_b);
    ft_printf("Index of largest element less than 6 in stack_b: %d\n", index_down);

    // Free all stacks after testing
    free_list(stack_a);
    free_list(stack_b);

    return 0;
}
