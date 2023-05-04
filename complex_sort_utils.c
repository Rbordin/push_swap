/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:42:51 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/03 15:03:25 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_move(t_data *stack)
{
	int	n_rot;

	if (stack->a_moves >= stack->b_moves)
	{
		n_rot = stack->b_moves;
		while (stack->b_moves-- > 0)
			rrr(stack, 0);
		while (n_rot++ != stack->a_moves)
			rra(stack, 0);
	}
	else
	{
		n_rot = stack->a_moves;
		while (stack->a_moves-- > 0)
			rrr(stack, 0);
		while (n_rot++ != stack->b_moves)
			rrb(stack, 0);
	}
}

void	rr_move(t_data *stack)
{
	int	n_rot;

	if (stack->a_moves >= stack->b_moves)
	{
		n_rot = stack->b_moves;
		while (stack->b_moves-- > 0)
			rr(stack, 0);
		while (n_rot++ != stack->a_moves)
			ra(stack, 0);
	}
	else
	{
		n_rot = stack->a_moves;
		while (stack->a_moves-- > 0)
			rr(stack, 0);
		while (n_rot++ != stack->b_moves)
			rb(stack, 0);
	}
}

void	rra_rb_move(t_data *stack)
{
	while (stack->a_moves-- > 0)
		rra(stack, 0);
	while (stack->b_moves-- > 0)
		rb(stack, 0);
}

void	ra_rrb_move(t_data *stack)
{
	while (stack->a_moves-- > 0)
		ra(stack, 0);
	while (stack->b_moves-- > 0)
		rrb(stack, 0);
}
