#include "push_swap.h"

void	init_count(t_count *count)
{
	count->ra = 0;
	count->pb = 0;
	count->pa = 0;
	count->rb = 0;
}

t_count	do_ab(t_stack *a, t_stack *b, int range, t_count count)
{
	init_count(&count);
	while (range-- > 0)
	{
		if (a->top->num > a->median)
		{
			rotate_stack(a, A);
			count.ra++;
		}
		else
		{
			push_stack(a, b, B);
			count.pb++;
		}
	}
	return (count);
}

void	push_swap_ab(t_stack *a, t_stack *b, int range)
{
	int		i;
	t_count	count;

	if (range <= 1)
		return ;
	set_mid(a);
	i = 0;
	count = do_ab(a, b, range, count);
	if (ft_lstsize(a) != count.ra)
	{
		while (i < (count.ra))
		{
			reverse_rotate_stack(a, A);
			i++;
		}
	}
	push_swap_ab(a, b, count.ra);
	push_swap_ba(a, b, count.pb);
}

t_count	do_ba(t_stack *a, t_stack *b, int range, t_count count)
{
	init_count(&count);
	while (range-- > 0)
	{
		if (b->top->num > b->median)
		{
			push_stack(b, a, A);
			count.pa++;
		}
		else
		{
			rotate_stack(b, B);
			count.rb++;
		}
	}
	return (count);
}

void	push_swap_ba(t_stack *a, t_stack *b, int range)
{
	int		i;
	t_count	count;

	if (calc_range_ba(range, a, b) == 1)
		return ;
	set_mid(b);
	i = 0;
	count = do_ba(a, b, range, count);
	if (ft_lstsize(b) != count.rb)
	{
		while (i < (count.rb))
		{
			reverse_rotate_stack(b, B);
			i++;
		}
	}
	push_swap_ab(a, b, count.pa);
	push_swap_ba(a, b, count.rb);
}
