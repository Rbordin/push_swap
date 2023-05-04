/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:10:40 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/03 15:02:36 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
		i++;
	return (i);
}

int	control(t_data *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j <= stack->len)
		{
			if (stack->a[i] == stack->a[j])
				exit (1);
			j++;
		}
		i++;
	}
	return (1);
}

void	cntr_n_pop(t_data *stack, char **temp)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (i < stack->len)
	{
		if (is_valid(temp[i]) == 1)
		{
			y = ft_atoi(temp[i]);
			if ((y >= INT_MIN) && (y <= INT_MAX))
			{
				stack->a[i] = y;
			}
			else
				print_error();
		}
		else
			print_error();
		i++;
	}
	if (control(stack) == 0)
		exit (1);
}

int	is_valid(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!((argv[i] >= '0' && argv[i] <= '9') || argv[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			sign;
	int			i;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i])
	{
		if (ft_is_digit(str[i]) == 0)
			print_error();
		result = result * 10;
		result = result + str[i] - '0';
		i++;
	}
	if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
		print_error();
	return (result * sign);
}
