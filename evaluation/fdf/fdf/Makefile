# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ecarvalh <ecarvalh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/26 11:33:41 by ecarvalh          #+#    #+#              #
#    Updated: 2024/03/18 18:59:46 by ecarvalh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB		= libft
MLX		= mlx
SRCS	= main.c $(wildcard utils/*.c)
ODIR	= objs
OBJS	= $(SRCS:%.c=$(ODIR)/%.o)
CFLAGS	= -O3 -Wall -Wextra -Werror -pedantic -I. -I$(LIB) -I$(MLX)
LDFLAGS	= -L$(LIB) -L$(MLX)
LDLIBS	= -lft -l$(MLX) -lX11 -lXext -lm -no-pie
NAME	= fdf

all: $(NAME) test

test: $(NAME)
	./$(NAME) test_maps/t2.fdf

$(LIB):
	@make -sC $@

$(MLX):
	@make -sC $@

$(NAME): $(OBJS) | $(LIB) $(MLX)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

clean:
	$(RM)r $(ODIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) checker

re: fclean all

$(ODIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all bonus clean fclean re $(LIB) $(MLX)
