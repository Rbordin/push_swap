/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:43:45 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/08 14:15:43 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_a(t_data *stack)
{
	int	i;

	i = 0;
	while (i <= stack->last_a)
	{
		ft_printf("%d\n", stack->a[i]);
		i++;
	}
}

void	print_stack_b(t_data *stack)
{
	int	i;

	i = 0;
	while (i < stack->last_b)
	{
		ft_printf("%d\n", stack->b[i]);
		i++;
	}
}
