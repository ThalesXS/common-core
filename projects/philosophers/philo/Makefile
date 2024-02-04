#	====================		Directories		====================

INC = includes

SRC = srcs
OBJ_DIR = objects

BONUS_SRC = srcs_bonus
BONUS_DIR = objects_bonus

#	====================		Files      		====================

NAME = philo
FILES = philosophers.c utils.c initializer.c routine.c routine2.c  
OBJ = $(FILES:.c=.o)
TARGET = $(addprefix $(OBJ_DIR)/, $(OBJ))

BONUS = philosophers_bonus
BONUS_FILES = 
			  
BONUS_OBJ = $(BONUS_FILES:.c=.o)
BONUS_TARGET = $(addprefix $(BONUS_DIR)/, $(BONUS_OBJ))

#	====================		Commands   		====================

CC = gcc
RM = rm

#	====================		Flags      		====================
W = -Wall -Wextra -Werror -pthread -fsanitize=thread
O = -c
I = -I $(INC)
WBLOCK = --no-print-directory

#	====================		Colors     		====================

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
RESET = \033[0m

#	====================		Rules      		====================

all: $(NAME)

$(NAME): $(OBJ_DIR) $(TARGET)
	@$(CC) $(W) $(I) $(TARGET) -o $(NAME)
	@echo "$(GREEN)$(NAME) created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC)/%.c
	@$(CC) $(W) $(I) $(O) $< -o $@
	@echo "$(GREEN)$(NAME) object files created$(RESET)"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

bonus: $(BONUS)

$(BONUS): $(BONUS_DIR) $(BONUS_TARGET)
	@$(CC) $(W) $(I) $(BONUS_TARGET) -o $(BONUS)
	@echo "$(GREEN)$(BONUS) created$(RESET)"

$(BONUS_DIR)/%.o: $(BONUS_SRC)/%.c
	@$(CC) $(W) $(I) $(O) $< -o $@
	@echo "$(GREEN)$(BONUS) object files created$(RESET)"

$(BONUS_DIR):
	@mkdir $(BONUS_DIR)

clean:
	@$(RM) -rf $(OBJ_DIR) $(BONUS_DIR)
	@echo "$(RED)$(NAME) object files deleted$(RESET)"

fclean: clean
	@$(RM) -rf $(NAME) $(BONUS)
	@echo "$(RED)$(NAME) deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus

#	====================		END        		====================
