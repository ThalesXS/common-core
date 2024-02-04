# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-carv <fde-carv@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/30 10:11:22 by fde-carv          #+#    #+#              #
#    Updated: 2024/02/01 20:08:11 by fde-carv         ###   ########.fr        #
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
NAME			=	account
OBJSDIR    		=	objs
OBJS			=	${SRC:%.cpp=${OBJSDIR}/%.o}
INCLUDES		=	-I .
CC				=	c++
CFLAGS			=	-Wall -Wextra -Werror -std=c++98
RM				=	rm -f
SRC				=	Account.cpp\
					tests.cpp\

# -=-=-=-=-=-=- EXECUTION -=-=-=-=-=-=- #
$(NAME):		${OBJS}
				@${CC} ${CFLAGS} ${OBJS} -o ${NAME}
				@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${GREEN}--> created${RESET}\n"

all:			${NAME}

${OBJSDIR}/%.o: %.cpp
				@mkdir -p $(@D)
				@${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
				@echo "[${CYAN}Object $(basename $(notdir $@)) files${WHITE}] ${GREEN}--> created${WHITE}"

clean:
				@${RM} -rf ${OBJSDIR} ${OBJS} ${NAME}
				@rm -f fred.log
				@echo "\n[${WHITE}${YELLOW}$(SBLINK)$$(echo ${NAME} | tr '[:lower:]' '[:upper:]')$(RESET)${WHITE}] ${RED}--> removed${RESET}\n"

fclean:			clean
				@rm -f 19920104_091532.log
				@echo "[${WHITE}${BLUE}Downloaded Files$(RESET)${WHITE}] ${RED}--> $(SBLINK)ERASED${RESET}\n"

download:
				@wget https://cdn.intra.42.fr/document/document/22619/19920104_091532.log > /dev/null 2>&1
				@echo "\n[${WHITE}${BLUE}CPP00 ex02 files$(RESET)${WHITE}] ${GREEN}--> $(SBLINK)Downloaded and Ready${RESET}\n"
#@wget https://cdn.intra.42.fr/document/document/22618/Account.hpp > /dev/null 2>&1
#@wget https://cdn.intra.42.fr/document/document/22620/tests.cpp > /dev/null 2>&1
#@wget https://cdn.intra.42.fr/document/document/22619/19920104_091532.log > /dev/null 2>&1

re: clean all

.PHONY: all clean re