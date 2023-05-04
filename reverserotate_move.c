/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate_move.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:37:50 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/03 15:46:37 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *stack, int flag)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->a[stack->last_a];
	while (i < stack->last_a)
	{
		stack->a[stack->last_a - i] = stack->a[stack->last_a - i - 1];
		i++;
	}
	stack->a[0] = tmp;
	if (flag == 0)
	{
		ft_printf("rra\n");
		stack->move_counter++;
	}
}

void	rrb(t_data *stack, int flag)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack->b[stack->last_b - 1];
	while (i < stack->last_b)
	{
		stack->b[stack->last_b - i] = stack->b[stack->last_b - i - 1];
		i++;
	}
	stack->b[0] = tmp;
	if (flag == 0)
	{
		ft_printf("rrb\n");
		stack->move_counter++;
	}
}

void	rrr(t_data *stack, int flag)
{
	rra(stack, 1);
	rrb(stack, 1);
	stack->move_counter++;
	if (flag == 0)
		ft_printf("rrr\n");
}
