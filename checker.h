/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 09:10:33 by rbordin           #+#    #+#             */
/*   Updated: 2023/05/03 14:37:12 by rbordin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "./push_swap.h"
# include "get_next_line/get_next_line.h"

void	interate(t_data *stack, char *str);
int		checking_stack(t_data *stack);
int		main(int argc, char **argv);
void	check_rotate(t_data *stack, char *str);
void	stamp(t_data *stack);

#endif