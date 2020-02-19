# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbonnete <lbonnete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/18 15:34:09 by trabut            #+#    #+#              #
#    Updated: 2020/02/17 15:36:04 by lbonnete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = doom-nukem

FLAGS       = -Wall -Wextra -Werror -O3

SDL			= -lpthread -F ../frameworks/ -framework SDL2 -framework SDL2_image 
SDL_HEADER	= -I ../frameworks/SDL2.framework/Headers -I ../frameworks/SDL2_image.framework/Headers

LIBFT = ../libft/libft.a

CC = gcc

HEAD_DIR = ./
SRC_DIR	 = ./
OBJ_DIR	 = ./

SRC =	main.c\
		init.c\
		sdl_init.c\
		editer.c\
		dealers_edit.c

INC = doom-nukem_edit.h
OBJ	= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRC))

$(shell mkdir -p $(OBJ_DIR))

all: $(NAME)
	echo "doom-nukem ready"

$(NAME): $(OBJ) $(LIBFT) 
	$(CC) -I $(HEAD_DIR) -o $@ $(OBJ) $(SDL) $(LIBFT) $(FLAGS) 


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -I $(HEAD_DIR) -o $@ $(SDL_HEADER) -c $< $(FLAGS)

$(LIBFT):
	make -C ../libft/ libft.a

p: all clean

clean:
	make clean -C ../libft
	/bin/rm -f $(OBJ)
	echo "Objects Destroyed"

fclean:	clean
	make fclean -C ../libft
	/bin/rm -f $(NAME)
	echo "Project Destroyed"

re:	fclean all

.PHONY:	all clean fclean re norm p

.SILENT: