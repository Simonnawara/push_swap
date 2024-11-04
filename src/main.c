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
//keeping
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

//keeping
static int check_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1); // Duplicate found
		stack = stack->next;
	}
	return (0);
}

//keeping
void print_stack(t_stack *stack)
{
	while (stack)
	{
		ft_putnbr_fd(stack->value, 1);
		ft_putchar_fd(' ', 1);
		stack = stack->next;
	}
	ft_putchar_fd('\n', 1);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return (0); //Error message ?
	ft_printf("Your Makefile Works\n");
}
