#include "push_swap.h"

int	ft_lstsize(t_stack *stack)
{
	t_node	*cur;
	int		i;

	cur = stack->top;
	i = 0;
	while (cur != stack->tail)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

int	calc_range_ba(int range, t_stack *a, t_stack *b)
{
	if (range == 1)
	{
		push_stack(b, a, A);
		return (1);
	}
	else if (range == 2)
	{
		if (b->top->num < b->top->next->num)
			swap_stack(b, B);
		push_stack(b, a, A);
		push_stack(b, a, A);
		return (1);
	}
	else if (range == 0)
		return (1);
	else
		return (0);
}

int	Max(int a, int b, int c)
{
	if (a > b && a > c)
		return (a);
	else if (b > a && b > c)
		return (b);
	else
		return (c);
}

int	Min(int a, int b, int c)
{
	if (a < b && a < c)
		return (a);
	else if (b < a && b < c)
		return (b);
	else
		return (c);
}
