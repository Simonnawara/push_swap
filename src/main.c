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
void print_list(t_stack *head) {
    while (head) {
        ft_printf("%d ", head->value);
        head = head->next;
    }
    ft_printf("\n");
}

void free_list(t_stack *head) {
    t_stack *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

t_stack *create_node(int value) {
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
	long num = ft_atoi(str);
	if(num < INT_MIN || num > INT_MAX)
		return (-1);
	append_node(stack, (int)num);
	return (0);
}


int main(int argc, char **argv)
{
	t_stack *stack_a;
	int	i;

	stack_a = NULL; //add pointer ?
	i = 1;
	if (argc < 2)
		return (0); //Error message ?
	while (i < argc)
	{
		if (parse_and_append(&stack_a, argv[i]) == -1)
		{
			ft_putendl_fd("Error", 2);
			exit(EXIT_FAILURE); //is this a correct error message ?
		}
	}

	//further processing needed
}
