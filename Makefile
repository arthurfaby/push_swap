# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afaby <afaby@student.42angouleme.fr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/24 15:12:12 by afaby             #+#    #+#              #
#    Updated: 2022/06/06 13:28:10 by afaby            ###   ########.fr        #
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
		sort_little.c \
		utils.c \
		ops.c \
		free.c \
		error.c

OBJS =	$(SRCS:.c=.o)

CC = gcc

INCS = .

LIBFT = libft

CFLAGS = -Wall -Wextra -Werror -I$(INCS) -I$(LIBFT) -L$(LIBFT) -lft

RM = rm -f

all: $(NAME)

.c.o:
	$(CC) -g $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

.PHONY: all clean fclean re
