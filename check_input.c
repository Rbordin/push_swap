/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:39:53 by dcologgi          #+#    #+#             */
/*   Updated: 2023/05/03 15:00:45 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_if_double(int nb, int	*array, int pos)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (array[i] == nb)
			return (0);
		i++;
	}
	return (1);
}

int	check_input(t_data *stack, char **argv)
{
	int	i;
	int	nb;
	int	*array_seen;

	i = 0;
	array_seen = calloc(sizeof(int), stack->len);
	while (i < stack->len)
	{
		nb = ft_atoi(argv[i + 1]);
		if (check_if_double(nb, array_seen, i) == 0)
			print_error();
		array_seen[i] = nb;
		i++;
	}
	free (array_seen);
	return (1);
}
