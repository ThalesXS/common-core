# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: resilva <resilva@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 02:54:43 by resilva           #+#    #+#              #
#    Updated: 2023/12/13 23:28:50 by resilva          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME = push_swap

# Directories
INC = inc/
SRC_DIR = srcs/
OBJ_DIR = obj/

# Compiler and CFlags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror -I
RM = rm -f

# Source Files
COMMANDS_DIR =		$(SRC_DIR)moves/push.c \
								$(SRC_DIR)moves/rev_rotate.c \
								$(SRC_DIR)moves/rotate.c \
								$(SRC_DIR)moves/sort_stacks.c \
								$(SRC_DIR)moves/sort_three.c \
								$(SRC_DIR)moves/swap.c
								
PUSH_SWAP_DIR = 	$(SRC_DIR)push_swap/handle_errors.c \
								$(SRC_DIR)push_swap/ft_split.c \
								$(SRC_DIR)push_swap/init_b_to_a.c \
								$(SRC_DIR)push_swap/push_swap.c \
							 	$(SRC_DIR)push_swap/stack_init.c \
								$(SRC_DIR)push_swap/stack_utils.c \
								$(SRC_DIR)push_swap/utils_sort.c
# Concatenate all source files
SRCS = $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules

all: $(NAME)

$(NAME): $(OBJ)
			@$(CC) $(CFLAGS) $(INC) $(OBJ) -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c 
			@mkdir -p $(@D)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
			@$(RM) -r $(OBJ_DIR)

fclean: clean
			@$(RM) $(NAME)

re: 	fclean all

# Phony targets represent actions not files
.PHONY: all clean fclean re