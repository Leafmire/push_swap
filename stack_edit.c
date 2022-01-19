#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	int	temp_num;

	temp_num = stack->top->num;
	stack->top->num = stack->top->next->num;
	stack->top->next->num = temp_num;
}

void	push_stack(t_stack *out, t_stack *put)
{
	int	num;

	num = out->top->num;
	push(put, num);
	pop(out);
}

void	rotate_stack(t_stack *stack)
{
	t_node	*node;

	if (ft_lstsize(stack) <= 1)
		return ;
	node = stack->top;
	stack->head->next = node->next;
	node->next->prev = stack->head;
	node->next = stack->tail;
	node->prev = stack->tail->prev;
	stack->tail->prev = node;
	node->prev->next = node;
	stack->top = stack->head->next;
}

void	reverse_rotate_stack(t_stack *stack)
{
	t_node	*node;

	if (ft_lstsize(stack) <= 1)
		return ;
	node = stack->tail->prev;
	stack->tail->prev = node->prev;
	node->prev->next = stack->tail;
	node->prev = stack->head;
	stack->head->next = node;
	node->next = stack->top;
	stack->top->prev = node;
	stack->top = node;
}
