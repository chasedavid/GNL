# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 09:43:45 by cfarnswo          #+#    #+#              #
#    Updated: 2017/12/07 22:08:28 by envy-15          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= test_gnl
LIBFT	= ./libft/
FILES 	= main.c get_next_line.c
OBJ	= $(FILES:.c=.o)
CC	= gcc
CFLAGS	= -Wall -Wextra -Werror -g


.PHONY = all clean fclean re

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAGS) -I libft/ -o get_next_line.o -c get_next_line.c
	$(CC) $(CFLAGS) -I libft/ -o main.o -c main.c
	$(CC) $(CFLAGS) -o test_gnl main.o get_next_line.o -I libft/ -L libft/ -lft
clean:
	@$(MAKE) clean -C $(LIBFT)
	@/bin/rm -rf $(OBJ)

fclean:
	@$(MAKE) clean
	@$(MAKE) fclean -C $(LIBFT)
	@/bin/rm -rf $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all
