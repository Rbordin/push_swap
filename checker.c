/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:09:45 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/04 12:39:52 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_data	stack;
	char	**temp;

	temp = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
		stack.len = count(temp);
		init(&stack);
		cntr_n_pop(&stack, temp);
	}
	else
	{
		stack.len = argc - 1;
		init(&stack);
		if (check_input(&stack, argv) == 0)
			print_error();
		fill_stack_a(&stack, argv);
	}
	interate(&stack, get_next_line(0));
	ft_cleaner(&stack);
	return (0);
}

void	interate(t_data *stack, char *str)
{
	while (str)
	{
		if (ft_strncmp(str, "pa", 2) == 0)
			pa(stack, 1);
		else if (ft_strncmp(str, "pb", 2) == 0)
			pb(stack, 1);
		else if (ft_strncmp(str, "sa", 2) == 0)
			sa(stack, 1);
		else if (ft_strncmp(str, "sb", 2) == 0)
			sb(stack, 1);
		else if (ft_strncmp(str, "ss", 2) == 0)
			ss(stack, 1);
		else
			check_rotate(stack, str);
		free(str);
		str = get_next_line(0);
	}
	stamp(stack);
}

void	check_rotate(t_data *stack, char *str)
{
	if (ft_strncmp(str, "ra", 2) == 0)
		ra(stack, 1);
	else if (ft_strncmp(str, "rb", 2) == 0)
		rb(stack, 1);
	else if (ft_strncmp(str, "rra", 3) == 0)
		rra(stack, 1);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		rrb(stack, 1);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		rrr(stack, 1);
	else if (ft_strncmp(str, "rr", 2) == 0)
		rr(stack, 1);
}

int	checking_stack(t_data *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < (stack->len - 1))
	{
		j = i + 1;
		if (stack->a[i] > stack->a[j])
			return (0);
		i++;
	}
	return (1);
}

void	stamp(t_data *stack)
{
	if (checking_stack(stack) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
