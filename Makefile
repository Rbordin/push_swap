# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbordin <rbordin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/16 15:27:31 by dcologgi          #+#    #+#              #
#    Updated: 2023/05/04 16:00:21 by rbordin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variabili di compilazione

NAME = push_swap
B_NAME = checker

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
PRINTF_PATH = ./ft_printf
PRINTF = $(PRINTF_PATH)/libftprintf.a
GNL_PATH = ./get_next_line
MAKEFLAGS += --silent

MAIN = push_swap.c \
	
SRC = check_input.c \
	checking_strings.c \
	complex_sort_utils.c \
	complex_sort_utils2.c \
	complex_sort.c \
	fill_stack.c \
	lis_utils.c \
	print_stack.c \
	reverserotate_move.c \
	rotate_move.c \
	simple_sort_utils.c \
	simple_sort.c \
	swap_push_move.c \
	lis.c \
	push_swap_utils.c \
	string_input.c \

B_SRC = checker.c \
	${GNL_PATH}/get_next_line.c \
	${GNL_PATH}/get_next_line_utils.c \

M_OBJ = ${MAIN:.c=.o}

OBJ = ${SRC:.c=.o}

B_OBJ = ${B_SRC:.c=.o}

CC = gcc -g

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

.o:.c
		${cc} ${CFLAGS} -c $< -o $@
		

all: ${NAME}

${NAME}: ${M_OBJ} ${OBJ} ${LIBFT} ${PRINTF}
		${CC} ${M_OBJ} ${OBJ} ${LIBFT} ${PRINTF} -o ${NAME}
		@echo "\033[32mCompiled OK!\033[0m"


${LIBFT}:
		make -C $(LIBFT_PATH)

${PRINTF}:
		make -C ${PRINTF_PATH}		
		
clean:
		${RM} ${OBJ} ${B_OBJ} ${M_OBJ}
		make clean -C ${LIBFT_PATH}
		make clean -C ${PRINTF_PATH}
		@echo "\033[35mCleaned everything!\033[0m"
		
fclean: clean
		${RM} ${LIBFT}
		${RM} ${PRINTF}
		${RM} ${NAME}
		${RM} ${B_NAME}

re: fclean all

bonus: ${OBJ} ${B_OBJ} ${LIBFT} ${PRINTF} 
		${CC} ${OBJ} ${B_OBJ} ${LIBFT} ${PRINTF} -o ${B_NAME}
		@echo "\033[36mBonus compiled OK!\033[0m"