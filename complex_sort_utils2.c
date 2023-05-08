/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:01 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/08 14:10:27 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max(t_data *stack)
{
	int	i;

	i = 0;
	stack->max = stack->b[0];
	while (i < stack->last_b)
	{
		if (stack->max <= stack->b[i])
		{
			stack->max = stack->b[i];
			stack->max_pos = i;
		}
		i++;
	}
}

void	get_min(t_data *stack)
{
	int	i;

	i = 0;
	stack->min = stack->b[0];
	while (i < stack->last_b)
	{
		if (stack->min >= stack->b[i])
		{
			stack->min = stack->b[i];
			stack->min_pos = i;
		}
		i++;
	}
}

void	new_best(t_data *stack, int a, int b, int i)
{
	stack->a_moves = a;
	stack->b_moves = b;
	stack->best_moves = stack->tot_moves;
	stack->best_pos_a = stack->a_pos;
	stack->best_pos_b = stack->b_pos;
	stack->best_nb = stack->a[i];
}
