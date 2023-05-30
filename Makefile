# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: araqioui <araqioui@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 14:59:15 by araqioui          #+#    #+#              #
#    Updated: 2023/02/03 19:46:57 by araqioui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra 
MLX =  -lmlx -framework OpenGL -framework AppKit
RM = rm -f
HEADER = header.h

SRC = main ft_strlen_map ft_free mapCheck \
		findMazePath findMazePathUtile affWindow \
		gnl/get_next_line gnl/get_next_line_utils \
		interaction directionMoves libft/ft_putnbr \
		libft/ft_lstadd_back libft/ft_lstclear \
		libft/ft_lstnew libft/ft_lstsize libft/ft_lstlast \
		libft/ft_itoa mapName fillingMap \

B_SRC = bonus/main ft_strlen_map ft_free bonus/mapCheck_b \
		bonus/findMazePath findMazePathUtile bonus/affWindow \
		gnl/get_next_line gnl/get_next_line_utils \
		bonus/interaction bonus/directionMoves libft/ft_putnbr \
		libft/ft_lstadd_back libft/ft_lstclear \
		libft/ft_lstnew libft/ft_lstsize libft/ft_lstlast \
		libft/ft_itoa mapName mapCheck bonus/fillingMap \
		bonus/enemyPath bonus/stringAff bonus/moveEnemy \

OBJ = $(SRC:=.o)
B_OBJ = $(B_SRC:=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(MLX) $(OBJ) -o $@

bonus: $(B_OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(MLX) $(B_OBJ) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(B_OBJ)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclen all

.PHONY: all clean fclen re
