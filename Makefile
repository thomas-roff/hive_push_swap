# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:57:58 by thblack-          #+#    #+#              #
#    Updated: 2025/09/18 13:53:36 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PROJECT NAME
PROJECT		= push_swap
NAME		= push_swap

# PROJECT DIRECTORIES
SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= inc

# PROJECT SOURCES: Explicitly states
SRC_FILES	= push_swap.c array_utils.c build_funcs.c small_stacks.c \
			  sort_operations.c stack_utils.c index_sort_operations.c \
			  radix_sort.c check_utils.c
SRC			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

# PROJECT HEADER
HEADER		= $(INC_DIR)/push_swap.h

# PROJECT OBJECTS
OBJ		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# TOOLS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# REMOVE
RM			= rm -rf

# MAKE DIRECTORY
MKDIR		= mkdir -p

# LIBFT LINKING
LIBFT_DIR	= ./libft
LIBFT_H		= $(LIBFT_DIR)/libft.h
LIBFT_A		= $(LIBFT_DIR)/libft.a

# INCLUDE PATHS AND LIBRARIES
INC			= -I. -I$(LIBFT_DIR) -I$(INC_DIR)
LIBFT		= -L$(LIBFT_DIR) -lft

# <<<<<<< MAIN TARGETS >>>>>>>

all: start $(NAME) finish

$(NAME): $(OBJ) $(LIBFT_A)
	@echo "==== BUILDING $(PROJECT) ====="
	@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "$(PROJECT) compiled"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(OBJ_DIR):
	@$(MKDIR) $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER) $(LIBFT_H) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

# <<<<<<< PHONY TARGETS >>>>>>>

start:
	@echo "==== THOMASROFF MAKEFILE ===="

finish:
	@echo "==== BUILD COMPLETE ========="

re_spacer:
	@echo ""

clean:
	@echo "==== THOMASROFF MAKEFILE ===="
	@echo "Removing $(PROJECT) object files"
	@rm -f $(OBJ)
	@make -C libft clean --no-print-directory
	@echo "==== CLEAN COMPLETE ========="

fclean:
	@echo "==== THOMASROFF MAKEFILE ===="
	@echo "Removing $(PROJECT) object files"
	@rm -f $(OBJ)
	@echo "Removing $(PROJECT) static library files"
	@rm -f $(NAME)
	@make -C libft fclean --no-print-directory
	@echo "==== FCLEAN COMPLETE ========"

re: fclean re_spacer all

.PHONY: all start finish clean fclean re re_spacer
