/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_util2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 19:53:32 by gson              #+#    #+#             */
/*   Updated: 2022/01/27 21:47:15 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*bubble_sort(int list[], int n)
{
	int	j;
	int	i;
	int	temp;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - 1 - i)
		{
			if (list[j] > list[j + 1])
			{
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (list);
}

int	check_mid_five(t_stack *a, int range)
{
	t_node	*cur;
	int		i;
	int		list[5];
	int		*sorted_list;

	i = 0;
	cur = a->top;
	while (cur != a->tail)
	{
		list[i] = cur->num;
		cur = cur->next;
		i++;
	}
	sorted_list = bubble_sort(list, range);
	return (sorted_list[2]);
}
