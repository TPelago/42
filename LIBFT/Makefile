#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpelago <tpelago@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/10 19:05:24 by tpelago           #+#    #+#              #
#    Updated: 2015/12/16 11:58:04 by tpelago          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
SRC = ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isprint.c ft_isascii.c ft_toupper.c \
      ft_tolower.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_putchar.c ft_putstr.c \
      ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
      ft_putnbr_fd.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
      ft_memchr.c ft_memcmp.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strchr.c \
      ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_memalloc.c ft_memdel.c ft_strnew.c \
      ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
      ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strstr.c \
	  ft_strnstr.c ft_atoi.c ft_itoa.c ft_strsplit.c ft_strlcat.c ft_lstnew.c \
	  ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_strrev.c \
	  ft_color.c ft_print_memory.c
OBJ = $(SRC:.c=.o)
EXT = libft.h

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
