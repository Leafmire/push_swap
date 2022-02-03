/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:36:36 by gson              #+#    #+#             */
/*   Updated: 2022/02/04 03:29:55 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_init(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == 0)
		return (0);
	stack->length = 0;
	stack->top = 0;
	return (stack);
}

void	create_stack(t_stack *stack)
{
	t_node	*head;
	t_node	*tail;

	head = (t_node *)malloc(sizeof(t_node));
	tail = (t_node *)malloc(sizeof(t_node));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
	stack->head = head;
	stack->tail = tail;
	stack->length = 0;
	stack->top = tail;
}

void	push_swap(t_stack *a, t_stack *b, int range)
{
	if (range == 3)
		push_swap_three(a);
	else if (range == 5)
		push_swap_five(a, b, range);
	else
		push_swap_ab(a, b, range);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	create_stack(stack_a);
	create_stack(stack_b);
	check_input(argc, argv, stack_a);
	push_swap(stack_a, stack_b, stack_a->length);
	return (0);
}
