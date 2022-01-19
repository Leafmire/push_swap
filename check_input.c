#include "push_swap.h"

int	check_sorted(t_stack *a)
{
	t_node	*cur;

	cur = a->top;
	while (cur != a->tail)
	{
		if (cur->num > cur->next->num)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int	iscontain_char(char *str)
{
	int	i;

	i = 0;
	while (i < ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	is_duplicated(t_stack *a)
{
	t_node	*cur;
	t_node	*move;

	cur = a->top;
	while (cur != a->tail)
	{
		move = cur->next;
		while (move != a->tail)
		{
			if (cur->num == move->num)
			{
				ft_putstr_fd("Error : Duplicated number found.\n", 2);
				exit(1);
			}
			move = move->next;
		}
		cur = cur->next;
	}
}

int	check_input(int argc, char **argv, t_stack *stack_a)
{
	if (argc <= 1)
		exit(1);
	else
	{
		while (argc > 1)
		{
			push(stack_a, ft_atoi(argv[argc - 1]));
			argc--;
		}
	}
	is_duplicated(stack_a);
	return (1);
}