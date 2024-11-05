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

// Initialize empty linked list B;

//function : push_two
// pushes two first elements of stack_A

/////// Call pvalue.c with stack_A and stack_B


