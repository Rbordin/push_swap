/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 14:41:15 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/08 14:15:03 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include "limits.h"

typedef struct s_data{
	int	*a;
	int	*b;

	int	len;

	int	last_a;
	int	last_b;
	int	move_counter;

	int	min;
	int	min_pos;
	int	max;
	int	max_pos;

	int	a_moves;
	int	b_moves;
	int	tot_moves;
	int	best_moves;
	int	a_pos;
	int	b_pos;
	int	best_pos_a;
	int	best_pos_b;
	int	best_nb;
}	t_data;

int		ft_is_digit(char c);
int		ft_abs(int nb);
int		check_input(t_data *stack, char **argv);
int		check_if_double(int nb, int	*array, int pos);
void	sa(t_data *stack, int flag);
void	sb(t_data *stack, int flag);
void	ss(t_data *stack, int flag);
void	pa(t_data *stack, int flag);
void	pb(t_data *stack, int flag);
void	ra(t_data *stack, int flag);
void	rb(t_data *stack, int flag);
void	rr(t_data *stack, int flag);
void	rra(t_data *stack, int flag);
void	rrb(t_data *stack, int flag);
void	rrr(t_data *stack, int flag);
void	fill_stack_a(t_data *stack, char **argv);
void	simple_case(t_data *stack);
void	sort_2(t_data *stack);
void	sort_3(t_data *stack);
void	sort_4(t_data *stack);
void	sort_5(t_data *stack);
void	find_min(t_data *stack);
void	find_max(t_data *stack);
void	push_min(t_data *stack);
void	push_max(t_data *stack);
void	check_better_rot_a(t_data *stack, int pos);
void	check_better_rot_b(t_data *stack);
void	print_error(void);
void	moving_b(t_data *stack, int nb, int min_diff);

void	get_max(t_data *stack);
void	get_min(t_data *stack);
void	complex_case(t_data *stack);
void	find_best_nb_to_push(t_data *stack);
void	find_where_to_push(t_data *stack, int nb);
void	push_nb(t_data *stack);
void	rrr_move(t_data *stack);
void	rr_move(t_data *stack);
void	rra_rb_move(t_data *stack);
void	ra_rrb_move(t_data *stack);
int		ft_atoi(const char *str);
void	init(t_data *stack);
int		check_sorted_input(t_data *stack);
void	new_best(t_data *stack, int a, int b, int i);

void	string_input(t_data *stack, char *argv);
int		is_valid(char *argv);
void	control_fill_stack(t_data *stack, char **temp);
int		control_doubles(t_data *stack);

void	ft_cleaner(t_data *stack);

void	print_stack_a(t_data *stack);
void	print_stack_b(t_data *stack);
void	cntr_n_pop(t_data *stack, char **temp);
int		control(t_data *stack);
int		count(char **temp);
int		is_valid(char *argv);

#endif
