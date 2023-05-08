/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:57:59 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/08 14:11:40 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	stack;

	if (argc < 2)
		return (0);
	if (argc == 2)
		string_input(&stack, argv[1]);
	else
	{
		stack.len = argc - 1;
		init(&stack);
		if (check_input(&stack, argv) == 0)
			return (0);
		fill_stack_a(&stack, argv);
	}
	if (check_sorted_input(&stack) == 0)
		return (0);
	if (stack.len <= 5)
		simple_case(&stack);
	if (stack.len > 5)
		complex_case(&stack);
	ft_cleaner(&stack);
}
