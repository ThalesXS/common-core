# ============================ {Directories} ============================

INC = includes
SRC = srcs
SRC_BONUS = srcs_bonus
OBJ_DIR = objects
OBJ_DIR_BONUS = objects_bonus

# ============================ {Files      } ============================

NAME = server client
SERVER = server
SV_FILES = server.c
SV_OBJ = $(SV_FILES:.c=.o)
CL_FILES = client.c
CL_OBJ = $(CL_FILES:.c=.o)
CLIENT = client
FILES = utils.c
OBJ = $(FILES:.c=.o)
ARQ = minitalk.a
SV_TARGET = $(addprefix $(OBJ_DIR)/, $(OBJ)) $(addprefix $(OBJ_DIR)/, $(SV_OBJ))
CL_TARGET = $(addprefix $(OBJ_DIR)/, $(OBJ)) $(addprefix $(OBJ_DIR)/, $(CL_OBJ))

# ============================ {Bonus     } ============================

BONUS = server_bonus client_bonus
SERVER_BONUS = server_bonus
SVB_FILES = server_bonus.c
SVB_OBJ = $(SVB_FILES:.c=.o)
CLB_FILES = client_bonus.c
CLB_OBJ = $(CLB_FILES:.c=.o)
CLIENT_BONUS = client_bonus
FILES_BONUS = utils_bonus.c
OBJ_BONUS = $(FILES_BONUS:.c=.o)
ARQ_BONUS = minitalk.a
SVB_TARGET = $(addprefix $(OBJ_DIR_BONUS)/, $(OBJ_BONUS)) $(addprefix $(OBJ_DIR_BONUS)/, $(SVB_OBJ))
CLB_TARGET = $(addprefix $(OBJ_DIR_BONUS)/, $(OBJ_BONUS)) $(addprefix $(OBJ_DIR_BONUS)/, $(CLB_OBJ))

# ============================ {Commands   } ============================

CC = gcc

# ============================ {Flags      } ============================

W = -Wall -Wextra -Werror
O = -c
I = -I $(INC)
WBLOCK = --no-print-directory

LIBFT = -L ./libft -lft

# ============================ {Colors     } ============================

RED = \033[0;31m
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
WHITE = \033[0;37m

# ============================ {Rules      } ============================

all: $(NAME)

$(NAME): $(OBJ_DIR) $(SV_TARGET) $(CL_TARGET)
	make -C ./libft $(WBLOCK)
	$(CC) $(W) $(I) $(SV_TARGET) $(LIBFT) -o $(SERVER)
	$(CC) $(W) $(I) $(CL_TARGET) $(LIBFT) -o $(CLIENT)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC)/%.c
	$(CC) $(W) $(O) $(I) $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_BONUS)
	make clean -C ./libft $(WBLOCK)

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	rm -f $(SERVER_BONUS) $(CLIENT_BONUS)
	make fclean -C ./libft $(WBLOCK)

bonus: $(BONUS)

$(BONUS): $(OBJ_DIR_BONUS) $(SVB_TARGET) $(CLB_TARGET)
	make -C ./libft $(WBLOCK)
	$(CC) $(W) $(I) $(SVB_TARGET) $(LIBFT) -o $(SERVER_BONUS)
	$(CC) $(W) $(I) $(CLB_TARGET) $(LIBFT) -o $(CLIENT_BONUS)

$(OBJ_DIR_BONUS):
	mkdir -p $(OBJ_DIR_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(SRC_BONUS)/%.c
	$(CC) $(W) $(O) $(I) $< -o $@

re: fclean all
