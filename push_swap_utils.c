/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:34:34 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/08 14:14:04 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cleaner(t_data *stack)
{
	free (stack->a);
	free (stack->b);
	exit (0);
}

void	init(t_data *stack)
{
	stack->a = calloc(sizeof(int), stack->len);
	stack->b = calloc(sizeof(int), stack->len);
	stack->last_a = stack->len - 1;
	stack->last_b = 0;
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
