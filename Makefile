# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconchit <aconchit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 15:05:21 by aconchit          #+#    #+#              #
#    Updated: 2021/10/21 17:27:31 by aconchit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CLIB = ar rcs
C_FILES =  libft/ft_strncmp.c \
libft/ft_strlen.c libft/ft_strdup.c libft/ft_itoa.c \
libft/ft_putchar_fd.c libft/ft_itoa_ultra.c ft_util_print.c ft_printf.c 
CC = gcc -Wall -Wextra -Werror -c
O_FILES = $(C_FILES:.c=.o)
INCLUDES = includes/
HEADER = includes/libft.h includes/ft_printf.h

.c.o:
	$(CC) $< -o $@ -I $(INCLUDES)

all: $(NAME)

$(NAME): $(O_FILES) $(HEADER)
	$(CLIB) $@ $(O_FILES)

clean:
	rm -rf $(O_FILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re