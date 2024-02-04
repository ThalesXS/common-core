# ============================ {Directories} ============================

INC = includes

SRC = srcs
OBJ_DIR = objects

BONUS_SRC = srcs_bonus
BONUS_DIR = objects_bonus

# ============================ {Files      } ============================

NAME = so_long
FILES = so_long.c map.c utils.c flood_fill.c initializers.c texture_loader.c \
		rend.c move.c hook.c destroy.c
OBJ = $(FILES:.c=.o)
TARGET = $(addprefix $(OBJ_DIR)/, $(OBJ))

BONUS = so_long_bonus
BONUS_FILES = so_long_bonus.c map_bonus.c utils_bonus.c flood_fill_bonus.c \
			  initializers_bonus.c texture_loader_bonus.c rend_bonus.c \
			  move_bonus.c hook_bonus.c destroy_bonus.c enemy_bonus.c \
			  
BONUS_OBJ = $(BONUS_FILES:.c=.o)
BONUS_TARGET = $(addprefix $(BONUS_DIR)/, $(BONUS_OBJ))

# ============================ {Commands   } ============================

CC = gcc
RM = rm

# ============================ {Flags      } ============================
W = -Wall -Wextra -Werror
O = -c
I = -I $(INC)
WBLOCK = --no-print-directory

LIBFT = -L ./libft -lft
MLX = -L ./minilibx-linux -lmlx -lXext -lX11

# ============================ {Colors     } ============================

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
RESET = \033[0m

# ============================ {Rules      } ============================

all: $(NAME)

$(NAME): $(OBJ_DIR) $(TARGET)
	@make $(WBLOCK) -C ./libft
	@make $(WBLOCK) -C ./minilibx-linux
	@$(CC) $(W) $(TARGET) $(LIBFT) $(MLX) -o $(NAME)
	@echo "$(GREEN)$(NAME)$(RESET) created"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC)/%.c
	@$(CC) $(W) $(O) $(I) $< -o $@

clean:
	@make $(WBLOCK) clean -C ./libft
	@make $(WBLOCK) clean -C ./minilibx-linux
	@$(RM) -rf $(OBJ_DIR) $(BONUS_DIR)
	@echo "$(RED)$(OBJ_DIR)$(RESET) deleted"

fclean: clean
	@make $(WBLOCK) fclean -C ./libft
	@$(RM) -rf $(NAME) $(BONUS)
	@echo "$(RED)$(NAME)$(RESET) deleted"

re: fclean all

bonus: $(BONUS)

$(BONUS): $(BONUS_DIR) $(BONUS_TARGET)
	@make $(WBLOCK) -C ./libft
	@make $(WBLOCK) -C ./minilibx-linux
	@$(CC) $(W) $(BONUS_TARGET) $(LIBFT) $(MLX) -o $(BONUS)
	@echo "$(GREEN)$(BONUS)$(RESET) created"

$(BONUS_DIR):
	@mkdir $(BONUS_DIR)

$(BONUS_DIR)/%.o: $(BONUS_SRC)/%.c
	@$(CC) $(W) $(O) $(I) $< -o $@

reb: fclean bonus

.PHONY: all clean fclean re

# ============================ {END        } ============================