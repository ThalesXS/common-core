#	====================		Directories		====================

INC = includes

SRC = srcs
OBJ_DIR = objects

#	====================		Files      		====================

NAME = minishell

FILES =
OBJ = $(FILES:.c=.o)
TARGET = $(addprefix $(OBJ_DIR)/, $(OBJ))

#	====================		Commands   		====================

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

#	====================		Colors     		====================

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
RESET = \033[0m

#	====================		Rules      		====================

all: $(NAME)

$(NAME):$(OBJ_DIR) $(TARGET)
	@$(CC) $(CFLAGS) -o $@ $^
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(NAME) objects removed$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) removed$(RESET)"

re: fclean all

.PHONY: all clean fclean re