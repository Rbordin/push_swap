/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:40:49 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/09 15:10:23 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *stack, int flag)
{
	int	tmp;

	if (stack->last_a >= 1)
	{
		tmp = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = tmp;
	}
	if (flag == 0)
	{
		ft_printf("sa\n");
		stack->move_counter++;
	}
}

void	sb(t_data *stack, int flag)
{
	int	tmp;

	if (stack->last_b >= 2)
	{
		tmp = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = tmp;
	}
	if (flag == 0)
	{
		ft_printf("sb\n");
		stack->move_counter++;
	}
}

void	ss(t_data *stack, int flag)
{
	sa(stack, 1);
	sb(stack, 1);
	stack->move_counter++;
	if (flag == 0)
		ft_printf("ss\n");
}

void	pa(t_data *stack, int flag)
{
	int	i;

	i = 0;
	if (stack->last_b >= 0)
	{
		while (i <= stack->last_a)
		{
			stack->a[stack->last_a - i + 1] = stack->a[stack->last_a - i];
			i++;
		}
		stack->a[0] = stack->b[0];
		stack->last_a++;
		rb(stack, 1);
		stack->last_b--;
		stack->move_counter++;
		if (flag == 0)
			ft_printf("pa\n");
	}
}

void	pb(t_data *stack, int flag)
{
	int	i;

	i = 0;
	if (stack->last_a >= 0)
	{
		while (i <= stack->last_b)
		{
			stack->b[stack->last_b - i + 1] = stack->b[stack->last_b - i];
			i++;
		}
		stack->b[0] = stack->a[0];
		stack->last_b++;
		ra(stack, 1);
		stack->last_a--;
		stack->move_counter++;
		if (flag == 0)
			ft_printf("pb\n");
	}
}
