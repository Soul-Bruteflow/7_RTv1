# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvlad <mvlad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 14:24:38 by mvlad             #+#    #+#              #
#    Updated: 2017/10/09 14:57:55 by mvlad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= RTv1
SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/
FRM_DIR	= ./frameworks/
SDL_INC	= $(FRM_DIR)SDL2.framework/Headers
SDL_TTF = $(FRM_DIR)SDL2_ttf.framework/Headers
SDL_IMG = $(FRM_DIR)SDL2_image.framework//Headers
SDL_MIX = $(FRM_DIR)SDL2_mixer.framework/Headers
LIB_DIR = ./libft/
LIB_INC = $(LIB_DIR)
LIB_LIB = $(LIB_DIR)libft.a

OD :=	./obj \
		./obj/events \
		./obj/functions \
		./obj/parser \
		./obj/raytrace \
		./obj/window \
		./obj/functions/vector \
		./obj/parser/objects \
		./obj/parser/scene \
		./obj/parser/support \
		./obj/raytrace/lights \
		./obj/raytrace/materials \
		./obj/raytrace/objects \
		./obj/raytrace/objects/cone \
		./obj/raytrace/objects/cylinder \
		./obj/raytrace/objects/plane \
		./obj/raytrace/objects/sphere \
		./obj/raytrace/scene \
		./obj/raytrace/scene/camera \
		./obj/window

OBJ	=	events/keyboard_core.o \
		functions/vector/vector_operations_1.o \
		functions/vector/vector_operations_2.o \
		functions/ft_atof.o \
		functions/ft_draw_pixel.o \
		functions/ft_noise.o \
		functions/ft_set_color.o \
		functions/ft_set_vector.o \
		parser/objects/parse_cone.o \
		parser/objects/parse_cylinder.o \
		parser/objects/parse_materials.o \
		parser/objects/parse_objects.o \
		parser/objects/parse_plane.o \
		parser/objects/parse_sphere.o \
		parser/scene/parse_camera.o \
		parser/scene/parse_lights.o \
		parser/scene/parse_scene.o \
		parser/support/parser_support_one.o \
		parser/support/parser_support_two.o \
		parser/parser_core.o \
		raytrace/lights/light.o \
		raytrace/materials/material.o \
		raytrace/objects/cone/cone_create.o \
		raytrace/objects/cone/cone_ray_intersect.o \
		raytrace/objects/cylinder/cylinder_create.o \
		raytrace/objects/cylinder/cylinder_ray_intersect.o \
		raytrace/objects/plane/plane_create.o \
		raytrace/objects/plane/plane_ray_intersect.o \
		raytrace/objects/sphere/sphere_create.o \
		raytrace/objects/sphere/sphere_ray_intersect.o \
		raytrace/objects/object.o \
		raytrace/calculate_light.o \
		raytrace/intersect.o \
		raytrace/raytrace.o \
		raytrace/scene/camera/camera.o \
		raytrace/scene/scene_create.o \
		window/create_window.o \
		window/update_window.o \
		get_next_line.o \
		main.o \
		rtv_error.o \
		rtv_init.o \
		rtv_loop.o \
		rtv_quit.o

LIB = $(LIB_DIR)libft.a

HEADERS	= $(INC_DIR)

# -lmlx -framework OpenGL -framework AppKit
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SDL		= -F $(FRM_DIR) -framework SDL2
INC_OPT = -I $(LIB_INC) -I $(INC_DIR) -I $(SDL_INC)
OUT_OPT = -o
OBJ_OPT = $< -o $@
LIB_OPT	= -c

RMF 	= rm -f

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OD)
	$(CC) $(CFLAGS) $(LIB_OPT) $(OBJ_OPT) $(INC_OPT)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	$(MAKE) -C ./libft/
	@mkdir -p ~/Library
	@mkdir -p ~/Library/Frameworks
	@rm -rf ~/Library/Frameworks/SDL2.framework ~/Library/Frameworks/SDL2_image.framework ~/Library/Frameworks/SDL2_mixer.framework ~/Library/Frameworks/SDL2_ttf.framework
	@cp -R -i ./frameworks/SDL2.framework ./frameworks/SDL2_image.framework ./frameworks/SDL2_mixer.framework ./frameworks/SDL2_ttf.framework ~/Library/Frameworks
	$(CC) $(CFLAGS) $(SDL) $(LIB_LIB) $^ $(OUT_OPT) $(NAME)

clean:
	$(RMF) $(addprefix $(OBJ_DIR), $(OBJ))
	cd $(LIB_DIR) && $(MAKE) clean

fclean: clean
	$(RMF) $(NAME)
	cd $(LIB_DIR) && $(MAKE) fclean

re: fclean all
	cd $(LIB_DIR) && $(MAKE) re
