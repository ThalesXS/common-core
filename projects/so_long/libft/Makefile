NAME = libft.a
FILES = ft_atoi.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strjoin.c ft_split.c ft_strtrim.c \
	ft_bzero.c ft_substr.c ft_strdup.c ft_calloc.c ft_strncmp.c ft_memchr.c \
	ft_memcmp.c ft_strnstr.c ft_isdigit.c ft_memset.c ft_strlen.c ft_isalnum.c \
	ft_isprint.c ft_strchr.c ft_strrchr.c ft_isalpha.c ft_memcpy.c ft_strlcat.c \
	ft_tolower.c ft_isascii.c ft_memmove.c ft_strlcpy.c ft_toupper.c \
	ft_print_c.c ft_printf.c ft_print_p.c ft_print_u.c ft_ptoa.c \
	ft_xtoa.c ft_printchar.c ft_print_s.c ft_print_x.c ft_specif.c \
	ft_xxtoa.c ft_print_d.c ft_printstr.c ft_print_xx.c ft_utoa.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c ft_line_no_n.c 
OBJ = $(FILES:.c=.o)
CCW = gcc -Wall -Wextra -Werror
BFILE = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BOBJ = $(BFILE:.c=.o)

vpath %.c libft
vpath %.o libft

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $(OBJ)

%.o: %.c
	$(CCW) -c $<

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(BOBJ) $(OBJ)
	ar rcs $(NAME) $(BOBJ) $(OBJ)
