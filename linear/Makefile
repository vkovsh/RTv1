# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/08 14:36:57 by vkovsh            #+#    #+#              #
#    Updated: 2018/02/08 16:41:19 by vkovsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	linear.a

FLAGS	=	-Wall -Werror -Wextra

CC		=	gcc $(FLAGS)

INC		=	./includes

SRC		= 	point2d.c		\
			point3d.c		\
			vector.c		\
			cosine.c		\
			module.c		\
			product.c		\
			reflect_ray.c	\
			rotate.c
	
OBJ		=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling" [ $(NAME) ]

%.o: %.c $(INC)/linear.h
	@$(CC) -c -o $@ $< -I $(INC)

clean:
	@rm -f $(OBJ)
	@echo "Cleaning" [ $(NAME) ]

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
