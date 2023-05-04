/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:28 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/03 14:43:31 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lis_raw_check(t_data *stack)
{
	int	i;
	int	j;

	i = 1;
	while (i < stack->len)
	{
		j = 0;
		while (j < i)
		{
			if (stack->a[j] < stack->a[i] && stack->dp[j] + 1 > stack->dp[i])
			{
				stack->dp[i] = stack->dp[j] + 1;
				stack->prev[i] = j;
			}
			j++;
		}
		i++;
	}
}

void	find_max_pos_lis(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->dp[i] > stack->dp[stack->lis_raw_len])
			stack->lis_raw_len = i;
		i++;
	}
}

void	lis_raw_gen(t_data *stack)
{
	int	i;
	int	j;

	i = stack->lis_raw_len;
	j = stack->dp[stack->lis_raw_len] - 1;
	while (i >= 0)
	{
		stack->lis_raw[j] = stack->a[i];
		i = stack->prev[i];
		j--;
	}
}

static int	get_lis_len(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->lis_raw_len)
	{
		if (stack->lis_raw[i] > stack->lis_raw[i + 1])
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

void	lis_gen(t_data *stack)
{
	int	i;

	i = 0;
	stack->lis_len = get_lis_len(stack);
	stack->lis = (int *)malloc(stack->lis_len * sizeof(int));
	while (i < stack->lis_len)
	{
		stack->lis[i] = stack->lis_raw[i];
		i++;
	}
}
