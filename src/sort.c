/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:55:32 by sinawara          #+#    #+#             */
/*   Updated: 2024/11/04 15:06:48 by sinawara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_max(t_stack *stack)
{
    int max = stack->value;

    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return max;
}

int is_sorted(t_stack *stack)
{
    while (stack && stack->next)
    {
        if (stack->value > stack->next->value)
            return (0); // Not sorted
        stack = stack->next;
    }
    return (1); // Sorted
}

void free_stack(t_stack **stack)
{
    t_stack *temp;

    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
    *stack = NULL;
}

void counting_sort(t_stack **stack_a, t_stack **stack_b, int exp)
{
    int count[10] = {0}; // Count array for base 10
    t_stack *current = *stack_a;

    // Count occurrences of each digit in the current place
    while (current)
    {
        int digit = (current->value / exp) % 10;
        count[digit]++;
        current = current->next;
    }

    // Update count[i] to contain the actual position of this digit in output
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output stack
    current = *stack_a;
    while (current)
    {
        int digit = (current->value / exp) % 10;
        while (count[digit] > 0)
        {
            pb(stack_b, stack_a); // Push to stack_b
            count[digit]--;
        }
        current = current->next;
    }

    // Move elements back from stack_b to stack_a
    while (*stack_b)
    {
        pa(stack_a, stack_a); // Push back to stack_a
    }
}


void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max = get_max(*stack_a);

    // Loop through each digit place
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        counting_sort(stack_a, stack_b, exp);
    }
}

