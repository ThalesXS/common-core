# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:11:22 by fde-carv          #+#    #+#              #
#    Updated: 2024/02/01 20:12:06 by fde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -=-=-=-=-=-=- COLORS -=-=-=-=-=-=- #
RESET			=	\033[0m
BLACK 			=	\033[1;30m
RED 			=	\033[1;31m
GREEN 			=	\033[1;32m
YELLOW 			=	\033[1;33m
BLUE			=	\033[1;34m
PURPLE 			=	\033[1;35m
CYAN 			=	\033[1;36m
WHITE 			=	\033[1;37m
SBLINK			=	\033[5m
FBLINK			=	\033[6m

# -=-=-=-=-=-=- VARIABLES -=-=-=-=-=-=- #
NAME			=	megaphone
SRC				=	megaphone.cpp
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -f

# -=-=-=-=-=-=- EXECUTION -=-=-=-=-=-=- #
$(NAME):
				@${CC} ${CFLAGS} ${SRC} -o ${NAME}
				@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

all:			${NAME}

clean:
				@${RM} ${NAME}
				@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${RED}--> removed${RESET}\n"

re: 			clean all

.PHONY: 		all clean re
