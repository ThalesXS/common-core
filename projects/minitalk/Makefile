# ============================ {Directories} ============================

INC = includes
SRC = srcs
OBJ_DIR = objects

# ============================ {Files      } ============================

SERVER = server
SV_FILES = server.c #utils.c
SV_OBJ = $(SV_FILES:.c=.o)
CL_FILES = client.c #utils.c
CL_OBJ = $(CL_FILES:.c=.o)
CLIENT = client
FILES = utils.c
OBJ = $(FILES:.c=.o)
ARQ = minitalk.a
SV_TARGET = $(addprefix $(OBJ_DIR)/, $(OBJ)) $(addprefix $(OBJ_DIR)/, $(SV_OBJ))
CL_TARGET = $(addprefix $(OBJ_DIR)/, $(OBJ)) $(addprefix $(OBJ_DIR)/, $(CL_OBJ))

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

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJ_DIR) $(SV_TARGET)
	make -C ./libft $(WBLOCK)
	$(CC) $(W) $(I) $(SV_TARGET) $(LIBFT) -o $(SERVER)

$(CLIENT): $(OBJ_DIR) $(CL_TARGET)
	make -C ./libft $(WBLOCK)
	$(CC) $(W) $(I) $(CL_TARGET) $(LIBFT) -o $(CLIENT)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC)/%.c
	$(CC) $(W) $(O) $(I) $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C ./libft $(WBLOCK)

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	make fclean -C ./libft $(WBLOCK)

re: fclean all