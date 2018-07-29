# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmaputla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 13:45:26 by kmaputla          #+#    #+#              #
#    Updated: 2018/07/29 17:51:04 by kmaputla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

LIBFT = ./libft/libft.a

SRC =	p_set.c\
		token.c\
		filler.c\
		map.c\
		play3.c\
		valid.c\
		play_3.c

 OBJ =	.o\

all:$(NAME)

$(NAME):$(COM)
	gcc -Wall -Werror -Wextra -o $(NAME) $(SRC) $(LIBFT)
 
COM:
	make f -C libft/
fclean:
	rm -f $(NAME)

f:all fclean

re:fclean all

norm:
	norminette p_set.c
	norminette token.c
	norminette filler.c
	norminette map.c
	norminette play3.c
	norminette play_3.c
	norminette valid.c
	norminette ft_to*.c
	norminette filler.h
