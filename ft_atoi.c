/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 00:18:17 by gson              #+#    #+#             */
/*   Updated: 2022/01/25 20:37:14 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_overint(void)
{
	ft_putstr_fd("Error : There's a value that's beyond the INT range.\n", 2);
	exit(1);
}

void	error_other(void)
{
	ft_putstr_fd("Error : Non numeric arguments found\n", 2);
	exit(1);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	minus;
	long	num;

	i = 0;
	minus = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		minus *= -1;
	else if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			error_other();
		num = (num * 10) + (str[i] - '0');
		if ((num > 2147483647 && minus == 1)
			|| (num > 2147483648 && minus == -1))
			error_overint();
		i++;
	}
	return (minus * num);
}
