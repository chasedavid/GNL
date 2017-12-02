# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 09:43:45 by cfarnswo          #+#    #+#              #
#    Updated: 2017/11/27 09:44:26 by cfarnswo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ME	= test_gnl
LIBFT	= ./libft/
FILES 	= main.c get_next_line.c
OBJ		= $(FILES:.c=.o)
	CC		= gcc
	CFLAGS	= -Wall -Wextra -Werror 


.PHONY = all clean fclean re

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
	clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
	clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
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
