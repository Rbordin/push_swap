/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:40:34 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/03 14:40:38 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_lis(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->lis_len)
	{
		while (stack->lis[i] != stack->a[0])
			ra(stack, 0);
		pb(stack, 0);
		i++;
	}
}

void	lis_finder(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		stack->lis_raw[i] = 0;
		stack->dp[i] = 1;
		stack->prev[i] = -1;
		i++;
	}
	lis_raw_check(stack);
	find_max_pos_lis(stack);
	lis_raw_gen(stack);
	lis_gen(stack);
	push_lis(stack);
	stack->lis_used = 1;
}
