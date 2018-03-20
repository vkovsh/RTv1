# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/29 13:00:36 by vkovsh            #+#    #+#              #
#    Updated: 2018/02/16 19:06:10 by vkovsh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	RTv1

CC 			=	gcc
CC_FLAGS 	=	-Wall -Werror -Wextra

SRC_PATH 	=	./srcs/
SCENE_PATH	=	$(SRC_PATH)scene/
SPHERE_PATH	=	$(SRC_PATH)sphere/
TRACER_PATH =	$(SRC_PATH)tracer/
KDTREE_PATH	=	$(SRC_PATH)kdtree/
COLOR_PATH	=	$(SRC_PATH)color/

INC_PATH	=	./includes/ $(LIBFT_PATH)/includes/ $(LIN_PATH)/includes/
OBJ_PATH	=	./obj/
LIBFT_PATH	=	./libft/
LIN_PATH	=	./linear/

LIBFT		=	$(LIBFT_PATH)libft.a
LINEAR		=	$(LIN_PATH)linear.a
LIBS		=	$(LIBFT) $(LINEAR)
MLX			=	-lmlx -framework OpenGL -framework Appkit
LIB_LNK		=	$(MLX) $(LIBS) -lpthread

OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ			+=	$(addprefix $(OBJ_PATH),$(OBJ_NAME2))
OBJ			+=	$(addprefix $(OBJ_PATH),$(OBJ_NAME3))
OBJ			+=	$(addprefix $(OBJ_PATH),$(OBJ_NAME4))
OBJ			+=	$(addprefix $(OBJ_PATH),$(OBJ_NAME5))
OBJ			+=	$(addprefix $(OBJ_PATH),$(OBJ_NAME6))
INC			=	$(addprefix -I, $(INC_PATH))

OBJ_NAME	=	$(SRC_NAME:.c=.o)
OBJ_NAME2	=	$(SCENE_NAME:.c=.o)
OBJ_NAME3	=	$(SPHERE_NAME:.c=.o)
OBJ_NAME4	=	$(TRACER_NAME:.c=.o)
OBJ_NAME5	=	$(KDTREE_NAME:.c=.o)
OBJ_NAME6	=	$(COLOR_NAME:.c=.o)

SRC_NAME	=	main.c				\
		   		color.c				\
		   		canvas.c			\
		   		render.c			\
		   		pixel.c				\
				grayscale_canvas.c	\
				mlx_layer.c

SCENE_NAME	=	new_scene.c			\
				release_object3d.c	\
				add_object.c		\
				prepare_scene.c		\
				new_light_source.c	\
				add_light_source.c	\
				material.c			\
				new_camera.c		\
				release_camera.c	\
				rotate_camera.c		\
				move_camera.c		\
				fog.c

SPHERE_NAME	=	get_sphere_bondary_point.c	\
				get_sphere_color.c			\
				get_sphere_material.c		\
				get_sphere_normal_vector.c	\
				intersect_sphere.c			\
				new_sphere.c				\
				release_sphere_data.c

TRACER_NAME	=	tracer.c			\
				calculate_color.c

KDTREE_NAME	=	kdtree.c			\
				release_kd_tree.c	\
				build_kd_tree.c		\
				voxel.c				\
				rec_build.c

COLOR_NAME	=	get_lighting_color.c	\
				get_specular_color.c	\
				is_viewable.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@make -C $(LIN_PATH)
	@$(CC) -o $(NAME) $(OBJ) $(LIB_LNK)
	@echo "Compiling" [ $(NAME) ]

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(SCENE_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(SPHERE_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(TRACER_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(KDTREE_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo "Linking" [ $< ]

$(OBJ_PATH)%.o: $(COLOR_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<
	@echo "Linking" [ $< ]

clean:
	@make -C $(LIBFT_PATH) clean
	@make -C $(LIN_PATH) clean
	@rm -rf $(OBJ_PATH)
	@echo "Cleaning obj [ $(NAME) ]..."

fclean: clean
	@make -C $(LIBFT_PATH) fclean
	@make -C $(LIN_PATH) fclean
	@rm -f $(NAME)
	@echo "Remove..." [ $(NAME) ]

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re 
