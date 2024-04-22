# ============================ {Directories} ============================

INC = includes
SRC = srcs
OBJ_DIR = objects

# ============================ {Files      } ============================

NAME = push_swap
FILES = push_swap.c utils.c utils2.c utils3.c utils4.c utils5.c utils6.c utils7.c rules0.c rules1.c rules2.c rules3.c
OBJ = $(FILES:.c=.o)
ARQ = push_swap.a
TARGET = $(addprefix $(OBJ_DIR)/, $(OBJ))
# ============================ {Commands   } ============================

CC = gcc
AR = ar rc

# ============================ {Flags      } ============================

W = -Wall -Wextra -Werror
O = -c
I = -I $(INC)
WBLOCK = --no-print-directory

LIBPRINT = -L ./ft_printf -lftprintf
LIBFT = -L ./ft_printf/libft -lft

# ============================ {Rules      } ============================

all: $(NAME)

$(NAME): $(OBJ_DIR) $(TARGET)
	make $(WBLOCK) -C ft_printf
	cp ft_printf/libftprintf.a libps.a
	ar rsc libps.a $(TARGET)
	$(CC) $(W) $(TARGET) $(LIBPRINT) -o $(NAME) $(I)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC)/%.c
	$(CC) $(W) $(O) $< -o $@ $(I)

clean:
	make clean -C ft_printf
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C ft_printf
	rm -f libps.a
	rm -f $(NAME)


re: fclean all
