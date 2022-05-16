# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 15:12:12 by afaby             #+#    #+#              #
#    Updated: 2022/05/13 17:50:43 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = main.c

CC = gcc

INCS = .

LIBFT = libft

CFLAGS = -Wall -Wextra -Werror -I$(INCS) -I$(LIBFT) -L$(LIBFT) -lft

RM = rm -f

all: $(NAME)

clean:
	$(RM)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME):
	$(CC) -g $(SRCS) -o $(NAME) $(CFLAGS)

.PHONY: all clean fclean re
