# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/25 18:52:51 by thblack-          #+#    #+#              #
#    Updated: 2025/08/25 20:31:09 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = array_utils.c build_funcs.c small_stacks.c sort_operations.c \
		  stack_utils.c uin_utils.c uin_sort_operations.c
MAIN = push_swap.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJECTS = $(SOURCES:.c=.o)
MAIN_OBJECT = $(MAIN:.c=.o)
UTILS = libpush_swap.a
HEADER = push_swap.h
NAME = push_swap

all: start libft utils $(NAME) finish

ex: start utils $(NAME) finish exclean

start:
	@echo "==== BUILDING PUSH_SWAP ===="

finish:
	@echo "==== BUILD FINISHED! ======="

libft:
	@make -C libft --no-print-directory

utils: $(OBJECTS)
	@ar rcs $(UTILS) $(OBJECTS)

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(MAIN_OBJECT) libft utils
	@$(CC) $(MAIN_OBJECT) -L. -lpush_swap -Llibft -lft -o $(NAME)

clean:
	@echo "Removing push_swap object files."
	@rm -f $(OBJECTS) $(MAIN_OBJECT)
	@make -C libft clean --no-print-directory

exclean:
	@echo "Removing push_swap object files."
	@rm -f $(OBJECTS) $(MAIN_OBJECT)

fclean: clean
	@echo "Removing push_swap static library files."
	@rm -f $(NAME) $(UTILS)
	@make -C libft fclean --no-print-directory

re: fclean all

.PHONY: all libft utils clean fclean re
