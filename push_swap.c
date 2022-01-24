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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)malloc(sizeof(t_stack));
	stack_b = (t_stack *)malloc(sizeof(t_stack));
	create_stack(stack_a);
	create_stack(stack_b);
	check_input(argc, argv, stack_a);
	push_swap_ab(stack_a, stack_b, stack_a->length);
	return (0);
}
