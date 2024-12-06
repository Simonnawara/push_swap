/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:03:45 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/15 10:03:50 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/* // Function to print the current state of the stack
void print_stack(t_stack_node *stack)
{
    t_stack_node *current;

    if (!stack)
    {
        printf("Stack is empty\n");
        return;
    }
    current = stack;
    while (current)
    {
        printf("%d\n", current->nbr);
        current = current->next;
    }
}
		printf("Sorted stack A:\n");
		print_stack(a);

*/

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = split(argv[1], ' ');
	define_stack_a(&a, argv + 1);
	if (!is_stack_sorted(a))
	{
		if (get_stack_size(a) == 2)
			sa(&a, false);
		else if (get_stack_size(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	return (0);
}
