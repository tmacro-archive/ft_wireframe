# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmckinno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/23 11:38:53 by tmckinno          #+#    #+#              #
#    Updated: 2017/08/15 10:11:01 by tmckinno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

ECHO	= @echo
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra 
INCLUDE	= -I minilibx -I libft/includes -I includes
SRCDIR	= srcs
OBJDIR	= build
LIBS	= -L libft/ -lft -L minilibx/ -lmlx

SRC		= draw.c \
		  window.c \
		  main.c \
		  util.c \
		  map.c \
		  iso.c \
		  wire.c \
		  color.c \
		  math.c \
		  event.c \
		  keys.c \
		  errors.c

SRCS	= $(addprefix $(SRCDIR)/, $(SRC))
OBJ		= $(SRC:%.c=$(OBJDIR)/%.o)

.PHONY	= all clean fclean re deps


all: $(NAME)

$(NAME):deps $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(OBJ) -framework OpenGL -framework AppKit -o $(NAME)

$(OBJ):  | build

build:
	@mkdir -p $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


deps:
	make -C libft
	make -C minilibx

clean:
	make -C libft/ clean
	make -C minilibx clean
	@rm -rf $(OBJDIR)

fclean: clean
	make -C libft fclean
	@rm -f $(NAME)

re: fclean all
