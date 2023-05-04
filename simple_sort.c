/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:44:14 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/03 14:44:17 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_data *stack)
{
	if (stack->a[0] > stack->a[1])
		sa(stack, 0);
}

void	sort_3(t_data *stack)
{
	if (stack->a[0] > stack->a[1] && stack->a[2] > stack->a[0])
		sa(stack, 0);
	if (stack->a[0] > stack->a[1] && stack->a[2] < stack->a[0])
		ra(stack, 0);
	if (stack->a[0] < stack->a[1] && stack->a[0] > stack->a[2])
		rra(stack, 0);
	if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2])
	{
		sa(stack, 0);
		rra(stack, 0);
	}
	if (stack->a[0] < stack->a[2] && stack->a[1] > stack->a[2])
	{
		sa(stack, 0);
		ra(stack, 0);
	}
}

void	sort_4(t_data *stack)
{
	int	i;

	i = 0;
	find_min(stack);
	while (i < stack->len)
	{
		if (stack->a[0] == stack->min)
			pb(stack, 0);
		else
		{
			if (stack->last_a > 2)
				check_better_rot_a(stack, stack->min_pos);
		}
		i++;
	}
	sort_3(stack);
	pa(stack, 0);
}

void	sort_5(t_data *stack)
{
	find_min(stack);
	find_max(stack);
	if ((ft_abs(stack->max_pos - (stack->last_a / 2)))
		> (ft_abs(stack->min_pos - (stack->last_a / 2))))
	{
		push_max(stack);
		find_min(stack);
		push_min(stack);
	}
	else
	{
		push_min(stack);
		find_max(stack);
		push_max(stack);
		sb(stack, 0);
	}
	sort_3(stack);
	pa(stack, 0);
	pa(stack, 0);
	ra(stack, 0);
}

void	simple_case(t_data *stack)
{
	if (stack->len == 2)
	{
		sort_2(stack);
		ft_cleaner(stack);
	}
	if (stack->len == 3)
	{
		sort_3(stack);
		ft_cleaner(stack);
	}
	if (stack->len == 4)
	{
		sort_4(stack);
		ft_cleaner(stack);
	}
	if (stack->len == 5)
	{
		sort_5(stack);
		ft_cleaner(stack);
	}
}
