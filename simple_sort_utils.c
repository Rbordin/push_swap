/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:44:07 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/16 16:26:12 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (-nb);
}

void	find_min(t_data *stack)
{
	int	i;

	i = 0;
	stack->min_pos = 0;
	stack->min = stack->a[0];
	while (i <= stack->last_a)
	{
		if (stack->a[i] <= stack->min)
		{
			stack->min_pos = i;
			stack->min = stack->a[i];
		}
		i++;
	}
}

void	find_max(t_data *stack)
{
	int	i;

	i = 0;
	stack->max_pos = 0;
	stack->max = stack->a[0];
	while (i <= stack->last_a)
	{
		if (stack->a[i] >= stack->max)
		{
			stack->max_pos = i;
			stack->max = stack->a[i];
		}
		i++;
	}
}

void	push_max(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->a[0] == stack->max)
		{
			pb(stack, 0);
			break ;
		}
		else
		{
			if (stack->last_a > 2)
				check_better_rot_a(stack, stack->max_pos);
		}
		i++;
	}
}

void	push_min(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->a[0] == stack->min)
		{
			pb(stack, 0);
			break ;
		}
		else
		{
			if (stack->last_a > 2)
				check_better_rot_a(stack, stack->min_pos);
		}
		i++;
	}
}
