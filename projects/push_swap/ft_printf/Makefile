NAME = libftprintf.a
FILES =	ft_print_c.c	ft_printf.c ft_print_p.c ft_print_u.c ft_ptoa.c	\
		ft_xtoa.c ft_printchar.c ft_print_s.c ft_print_x.c ft_specif.c \
		ft_xxtoa.c ft_print_d.c ft_printstr.c ft_print_xx.c \
		ft_utoa.c
OBJ = $(FILES:.c=.o)
CCW = gcc -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make bonus --no-print-directory -C libft
	cp libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CCW) -c $<

clean:
	make clean -C libft
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

bonus: all

re: fclean all
