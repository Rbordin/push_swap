/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:38:15 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/03 15:43:24 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_nb(t_data *stack)
{
	if ((stack->best_pos_a > stack->last_a / 2)
		&& (stack->best_pos_b > ((stack->last_b - 1) / 2)))
	{
		rrr_move(stack);
		pb(stack, 1);
	}
	else if ((stack->best_pos_a <= stack->last_a / 2)
		&& (stack->best_pos_b <= ((stack->last_b - 1) / 2)))
	{
		rr_move(stack);
		pb(stack, 1);
	}
	else if ((stack->best_pos_a > stack->last_a / 2)
		&& (stack->best_pos_b <= ((stack->last_b - 1) / 2)))
	{
		rra_rb_move(stack);
		pb(stack, 1);
	}
	else
	{
		ra_rrb_move(stack);
		pb(stack, 1);
	}
}

void	find_where_to_push(t_data *stack, int nb)
{
	int	min_diff;

	get_min(stack);
	get_max(stack);
	min_diff = stack->max;
	stack->b_pos = stack->min_pos;
	if (nb > stack->max)
		stack->b_pos = stack->max_pos;
	else if (nb < stack->min)
	{
		if (stack->min_pos > (stack->last_b - 1) / 2)
			stack->b_pos = stack->min_pos + 1;
		else
			stack->b_pos = stack->min_pos + 1;
	}
	else
		moving_b(stack, nb, min_diff);
}

void	moving_b(t_data *stack, int nb, int min_diff)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (i < stack->last_b)
	{
		x = nb - stack->b[i];
		if (x > 0 && x < min_diff)
		{
			stack->b_pos = i;
			min_diff = x;
		}
		i++;
	}
}

void	find_best_nb_to_push(t_data *stack)
{
	int	i;
	int	a;
	int	b;

	i = 0;
	a = 0;
	b = 0;
	while (i <= stack->last_a)
	{
		stack->a_pos = i;
		if (stack->a_pos > (stack->last_a / 2))
			a = (stack->last_a - stack->a_pos + 1);
		else
			a = stack->a_pos;
		find_where_to_push(stack, stack->a[i]);
		if (stack->b_pos > ((stack->last_b - 1) / 2))
			b = stack->last_b - stack->b_pos;
		else
			b = stack->b_pos;
		stack->tot_moves = a + b;
		if (stack->tot_moves < stack->best_moves)
			new_best(stack, a, b, i);
		i++;
	}
}

void	complex_case(t_data *stack)
{
	while (stack->last_a >= 0)
	{
		stack->best_moves = stack->len;
		stack->best_pos_a = 0;
		stack->best_pos_b = stack->last_b - 1;
		find_best_nb_to_push(stack);
		push_nb(stack);
	}
	get_min(stack);
	while (stack->b[stack->last_b - 1] != stack->min)
	{
		if (stack->min_pos > (stack->last_b - 1) / 2)
			rrb(stack, 0);
		else
			rb(stack, 0);
	}
	while (stack->last_b > 0)
		pa(stack, 0);
}
