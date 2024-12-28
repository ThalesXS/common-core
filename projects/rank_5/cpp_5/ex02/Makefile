#	====================		Directories		====================

INC = includes
SRC = srcs
OBJ_DIR = objects

#	====================		Files      		====================

NAME = GetTheRightForm
FILES = main.cpp Bureaucrat.cpp AForm.cpp ShruberryCreationForm.cpp RobotomyRequestForm.cpp
OBJ = $(FILES:.cpp=.o)
TARGET = $(addprefix $(OBJ_DIR)/, $(OBJ))

#	====================		Commands   		====================

CC = c++
RM = rm -rf

#	====================		Flags      		====================

W = -Wall -Wextra -Werror -std=c++98
O = -c
I = -I $(INC)
WBLOCK = --no-print-directory

#	====================		Colors     		====================

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
MAGENTA = \033[0;35m
CYAN = \033[0;36m

B_RED = \033[1;31m
B_GREEN = \033[1;32m
B_BLUE = \033[1;34m
B_YELLOW = \033[1;33m
B_MAGENTA = \033[1;35m
B_CYAN = \033[1;36m

L_BLUE = \033[1;94m

RESET = \033[0m

#	====================		Rules      		====================

all: $(NAME)

$(NAME):$(OBJ_DIR) $(TARGET)
	@$(CC) $(W) $(TARGET) -o $(NAME)
	@echo "$(B_GREEN)$(NAME) created$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC)/%.cpp
	@$(CC) $(W) $(O) $(I) $< -o $@
	@echo "$(B_YELLOW)$(NAME)$(RESET):$(YELLOW) $@ created$(RESET)"

clean:
	@$(RM) -rf $(OBJ_DIR)
	@echo "$(B_YELLOW)$(NAME)$(RESET):$(YELLOW) $(OBJ_DIR) deleted$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(B_YELLOW)$(NAME)$(RESET):$(YELLOW) $(NAME) deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus