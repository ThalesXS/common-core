# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsilva-e < rsilva-e@student.42porto.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 13:12:54 by rsilva-e          #+#    #+#              #
#    Updated: 2023/10/23 19:00:25 by rsilva-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	pipex
CC		=	cc -g
CFLAGS	=	-Wall -Wextra -Werror 
RM		=	rm -rf

SRCS	=	pipe.c\
			path_name.c\
			pipe_utils.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS	=	pipe_bonus.c\
				path_name_bonus.c\
				pipe_utils_bonus.c\
				here_doc.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

MINI_LIBFT = libft/libft.a


$(NAME): $(OBJS) $(MINI_LIBFT)
		$(CC) $(CFLAGS) $(SRCS) $(MINI_LIBFT) -o $(NAME)

$(MINI_LIBFT):
		${MAKE} -C ./libft

all: $(NAME)

bonus: $(BONUS_OBJS) $(MINI_LIBFT)
		$(CC) $(CFLAGS) $(BONUS_SRCS) $(MINI_LIBFT) -o $(NAME)

leak:
		valgrind --trace-children=yes  --leak-check=full --show-leak-kinds=all ./$(NAME) here_doc "ola" "grep a1" "wc -l" out

		#--track-fds=yes

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)
		$(MAKE) clean -C ./libft
fclean: clean
		$(RM) $(NAME)
		$(MAKE) fclean -C ./libft

re: fclean all

rebonus: fclean bonus


.PHONY: all clean fclean re
