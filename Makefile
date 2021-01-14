# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ameta <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 13:10:52 by ameta             #+#    #+#              #
#    Updated: 2021/01/14 13:10:56 by ameta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCES = 	ft_get_flags.c \
			ft_get_precision.c \
			ft_get_type.c \
			ft_get_width.c \
			ft_handle.c \
			ft_handle_c.c \
			ft_handle_i.c \
			ft_handle_p.c \
			ft_handle_percent.c \
			ft_handle_s.c \
			ft_handle_x.c \
			ft_handle_u.c \
			ft_itoa_u.c \
			ft_itoa_hex.c \
			ft_printf.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_print_zero.c \
			ft_putstr.c \
			ft_strtoupper.c

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = srcs

HEADER = includes

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	
%.o: $(DIR_S)/%.c
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
