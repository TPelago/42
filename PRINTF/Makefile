#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpelago <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/22 19:29:45 by tpelago           #+#    #+#              #
#    Updated: 2016/04/22 19:31:16 by tpelago          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC = 
OBJ = $(SRC:.c=.o)
EXT = libftprintf.h

all: $(NAME)

$(NAME): $(OBJ)
	@echo "-> Creating $(NAME)..."
	@ar rc $(NAME) $(OBJ)
	@echo "-> Optimising $(NAME)..."
	@ranlib $(NAME)
	@echo "-> Done !"

%.o : %.c
	@echo "-> Compiling $<..."
	@$(CC) $(FLAGS) -I. -c $< -o $@

$(O): | ./objects

clean:
	@echo "-> Cleaning object files..."
	@/bin/rm -rf $(OBJ)

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
