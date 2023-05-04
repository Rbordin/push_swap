/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:34:34 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/03 15:45:20 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cleaner(t_data *stack)
{
	free (stack->a);
	free (stack->b);
	free (stack->lis_raw);
	free (stack->dp);
	free (stack->prev);
	if (stack->lis_used == 1)
		free (stack->lis);
	exit (0);
}

void	init(t_data *stack)
{
	stack->a = calloc(sizeof(int), stack->len);
	stack->b = calloc(sizeof(int), stack->len);
	stack->lis_raw = (int *)malloc(stack->len * sizeof(int));
	stack->dp = (int *)malloc(stack->len * sizeof(int));
	stack->prev = (int *)malloc(stack->len * sizeof(int));
	stack->last_a = stack->len - 1;
	stack->last_b = 0;
	stack->lis_used = 0;
	stack->move_counter = 0;
}

int	check_sorted_input(t_data *stack)
{
	int	i;

	i = 1;
	while (i < stack->len)
	{
		if (stack->a[i] < stack->a[i - 1])
			return (1);
		i++;
	}
	ft_cleaner(stack);
	return (0);
}
