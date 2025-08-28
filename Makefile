# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thblack- <thblack-@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/24 14:57:58 by thblack-          #+#    #+#              #
#    Updated: 2025/07/25 14:29:18 by thblack-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_DIR = libft
LIB_HEADER = $(LIB_DIR)/libft.h

# ASCII
ASCII_DIR = ascii
ASCII_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			  ft_isprint.c ft_toupper.c ft_tolower.c ft_isspace.c ft_isnum.c
ASCII = $(addprefix $(ASCII_DIR)/, $(ASCII_FILES))

# GNL
GNL_DIR = gnl
GNL_FILES = get_next_line.c
GNL = $(addprefix $(GNL_DIR)/, $(GNL_FILES))

# LISTS
LISTS_DIR = lists
LISTS_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			  ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
			  ft_lstmap.c
LISTS = $(addprefix $(LISTS_DIR)/, $(LISTS_FILES))

# MEMORY
MEMORY_DIR = memory
MEMORY_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
			   ft_memcmp.c ft_calloc.c
MEMORY = $(addprefix $(MEMORY_DIR)/, $(MEMORY_FILES))

# NUMBERS
NUMBERS_DIR = numbers
NUMBERS_FILES = ft_atoi.c ft_itoa.c ft_digitcount.c
NUMBERS = $(addprefix $(NUMBERS_DIR)/, $(NUMBERS_FILES))

# PRINTING
PRINTING_DIR = printing
PRINTING_FILES = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putuint.c \
				 ft_puthex.c ft_putptr.c ft_putendl_fd.c ft_putnbr_fd.c \
				 ft_printf.c ft_putchar_fd.c ft_putstr_fd.c
PRINTING = $(addprefix $(PRINTING_DIR)/, $(PRINTING_FILES))

# STRINGS
STRINGS_DIR = strings
STRINGS_FILES = ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
				ft_strrchr.c ft_strncmp.c ft_strnstr.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
				ft_striteri.c ft_strcmp.c
STRINGS = $(addprefix $(STRINGS_DIR)/, $(STRINGS_FILES))

# COMBINE GROUPS
LIB_SOURCES = $(ASCII) $(GNL) $(LISTS) $(MEMORY) $(NUMBERS) $(PRINTING) $(STRINGS)
LIB_PATHS = $(addprefix $(LIB_DIR)/,$(LIB_SOURCES))

# PROJECT SOURCES
PROJECT_SOURCES = array_utils.c build_funcs.c small_stacks.c sort_operations.c \
					stack_utils.c uin_sort_operations.c radix_sort.c
MAIN = push_swap.c
PROJECT_PATHS = $(PROJECT_SOURCES) $(MAIN)
PROJECT_HEADER = push_swap.h

# COMBINE SOURCES AND HEADERS
SOURCES = $(LIB_PATHS) $(PROJECT_PATHS)
OBJECTS_DIR = .objects
OBJECTS = $(SOURCES:%.c=$(OBJECTS_DIR)/%.o)
HEADERS = $(LIB_HEADER) $(PROJECT_HEADER)

# TOOLS
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIB_DIR) -I. -MMD -MP
MKDIR = mkdir -p
RMFILE = rm -f
RMDIR = rm -rf

# PROGRAM
NAME = push_swap

all: launch start $(NAME) finish

launch: 
	@echo "===== PUSH_SWAP MAKEFILE =====\n"

start:
	@echo "Building push_swap"

finish:
	@echo "\n======= MAKE COMPLETE! ======="

$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
	@echo "Build completed."

$(OBJECTS_DIR)/%.o: %.c $(HEADERS)
	@$(MKDIR) $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJECTS:.o=.d)

do_clean:
	@echo "Removing objects"
	@$(RMFILE) $(OBJECTS)
	@$(RMDIR) $(OBJECTS_DIR)

do_fclean: do_clean
	@echo "Removing executable"
	@$(RMFILE) $(NAME)

clean: launch do_clean finish

fclean: launch do_fclean finish

re: launch do_fclean all

.PHONY: all launch start finish clean fclean do_clean do_fclean re
