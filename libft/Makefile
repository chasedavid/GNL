# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfarnswo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 16:43:33 by cfarnswo          #+#    #+#              #
#    Updated: 2017/12/04 11:27:40 by cfarnswo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc
MAIN=maintest.c
CFLAGS=-Wall -Werror -Wextra -I ./ -c
FILES=	ft_memset					ft_bzero			\
		ft_memcpy					ft_memccpy			\
		ft_memmove					ft_memchr			\
		ft_memcmp					ft_strlen			\
		ft_strcpy					ft_strdup			\
		ft_strncpy					ft_strcat			\
		ft_strncat					ft_strlcat			\
		ft_strchr					ft_strrchr			\
		ft_strstr					ft_strnstr			\
		ft_strcmp					ft_strncmp			\
		ft_atoi						ft_isalpha			\
		ft_isdigit					ft_isalnum			\
		ft_isascii					ft_isprint			\
		ft_toupper					ft_tolower			\
		ft_itoa						ft_memalloc			\
		ft_memdel					ft_strclr			\
		ft_strnew					ft_strdel			\
		ft_striter					ft_striteri			\
		ft_strmap					ft_strmapi			\
		ft_strequ					ft_strnequ			\
		ft_strsub					ft_strjoin			\
		ft_strxjoin					ft_strtrim			\
		ft_strsplit					ft_num_placevalues	\
		ft_putchar					ft_putstr			\
		ft_putendl					ft_putnbr			\
		ft_putchar_fd				ft_putstr_fd		\
		ft_putendl_fd				ft_putnbr_fd		\
		ft_lstnew					ft_lstdelone		\
		ft_lstdel					ft_lstadd			\
		ft_lstiter					ft_lstmap			\
		ft_strrev					ft_power			\
		ft_gcf						ft_lcm				

SRC=$(addsuffix .c, $(FILES))
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ) 

$(OBJ):$(SRC)
	$(CC) $(CFLAGS) $(SRC)

test:
	$(CC) -o out $(MAIN) $(NAME) 

clean:
	/bin/rm -rf $(OBJ)
	/bin/rm -rf out

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all 
