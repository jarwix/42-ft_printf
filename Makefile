# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpadisha <oazisrus@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 17:12:03 by lpadisha          #+#    #+#              #
#    Updated: 2020/07/27 18:20:17 by lpadisha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = ./libft/libft.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		sources/ft_print_main.c		sources/ft_print_width.c \
		sources/ft_itoa_and_base.c	sources/ft_putprint.c \
		sources/ft_tolower_s.c		sources/ft_print_string.c \
		sources/ft_print_char.c		sources/ft_print_pointer.c \
		sources/ft_print_int.c		sources/ft_print_uint.c \
		sources/ft_print_percent.c	sources/ft_print_hex.c \
		sources/ft_print_flags.c
		
SRCS_0 = ft_printf.o \
			ft_print_main.o		ft_print_width.o \
			ft_itoa_and_base.o	ft_putprint.o \
			ft_tolower_s.o      	ft_print_string.o \
			ft_print_char.o   	ft_print_pointer.o \
			ft_print_int.o       	ft_print_uint.o \
			ft_print_percent.o    	ft_print_hex.o \
			ft_print_flags.o  

CC = clang

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) -c -Wall -Wextra -Werror $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SRCS_0) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re
