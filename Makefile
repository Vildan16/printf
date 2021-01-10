
NAME = libftprintf.a

OBJ =	ft_get_flags.o \
		ft_get_precision.o \
		ft_get_type.o \
		ft_get_width.o \
		ft_handle.o \
		ft_handle_c.o \
		ft_handle_i.o \
		ft_handle_p.o \
		ft_handle_percent.o \
		ft_handle_s.o \
		ft_handle_x.o \
		ft_handle_u.o \
		ft_itoa_u.o \
		ft_itoa_hex.o \
		ft_printf.o \
		ft_putchar.o \
		ft_putnbr.o \
		ft_print_zero.o \
		ft_putstr.o \
		ft_strtoupper.o \

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@ar rc $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)

$(OBJ):
	@gcc -Wall -Wextra -Werror -I includes -c $(addprefix srcs/,$(patsubst %.o, %.c, $@))

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all
