/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:36:41 by gson              #+#    #+#             */
/*   Updated: 2022/01/25 20:36:41 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, int num)
{
	t_node	*newNode;

	newNode = (t_node *)malloc(sizeof(t_node));
	newNode->num = num;
	stack->top->prev = newNode;
	stack->head->next = newNode;
	newNode->prev = stack->head;
	newNode->next = stack->top;
	stack->top = newNode;
	stack->length++;
}

int	pop(t_stack *stack)
{
	t_node	*deleteNode;
	int		num;

	if (stack->top != stack->tail)
	{
		deleteNode = stack->top;
		stack->top = deleteNode->next;
		stack->head->next = stack->top;
		stack->top->prev = stack->head;
		num = deleteNode->num;
		stack->length--;
		free(deleteNode);
		return (num);
	}
	else
		return (0);
}

void	show(t_stack *stack)
{
	t_node	*cur;

	cur = stack->head->next;
	while (cur != stack->tail)
	{
		printf("%d\n", cur->num);
		cur = cur->next;
	}
}

void	show_all(t_stack *a, t_stack *b)
{
	printf("--------a-------\n");
	show(a);
	printf("----------------\n");
	printf("--------b-------\n");
	show(b);
	printf("----------------\n\n");
}

void	set_mid(t_stack *a)
{
	t_node	*cur;
	int		max;
	int		min;

	if (a->top == a->tail)
		return ;
	cur = a->top;
	if (ft_lstsize(a) >= 3)
	{
		max = Max(cur->num, cur->next->num,
				cur->next->next->num);
		min = Min(cur->num, cur->next->num,
				cur->next->next->num);
		a->median = (cur->num + cur->next->num
				+ cur->next->next->num) - max - min;
	}
	else
		a->median = cur->num;
}
