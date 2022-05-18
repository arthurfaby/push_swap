# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 15:12:12 by afaby             #+#    #+#              #
#    Updated: 2022/05/18 13:25:42 by afaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	main.c \
		parse.c \
		lst.c \
		push.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		sort.c \
		utils.c

CC = gcc

INCS = .

LIBFT = libft

CFLAGS = -Wall -Wextra -Werror -I$(INCS) -I$(LIBFT) -L$(LIBFT) -lft

RM = rm -f

all: $(NAME)

clean:
#	make clean -C $(LIBFT)
	$(RM)

fclean: clean
#	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

$(NAME):
#	make -C $(LIBFT)
	$(CC) -g $(SRCS) -o $(NAME) $(CFLAGS)

.PHONY: all clean fclean re
