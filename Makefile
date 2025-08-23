# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzetoun <zzetoun@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/17 12:00:00 by zzetoun           #+#    #+#              #
#    Updated: 2025/08/17 12:00:00 by zzetoun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D

# -------------------------
# Directories
# -------------------------
SRC_DIR     = srcs
UTIL_DIR    = $(SRC_DIR)/utils
LIBFT_DIR   = $(UTIL_DIR)/libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

OS_NAME     = $(shell uname)
ifeq ($(OS_NAME), Linux)
MLXOS       = $(UTIL_DIR)/mlx/minilibx-linux
MLX_LIB     = $(MLXOS)/libmlx.a
MLXFLAGS    = -L$(MLXOS) -lmlx -L/usr/lib -I$(MLXOS) -lXext -lX11 -lm
else
MLXOS       = $(UTIL_DIR)/mlx/minilibx-macos
MLX_LIB     = $(MLXOS)/libmlx.a
MLXFLAGS    = -L$(MLXOS) -lmlx -framework OpenGL -framework AppKit
endif

INCDIR      = include
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -I$(INCDIR)

# -------------------------
# Colors
# -------------------------
GREEN   = \033[0;32m
RED     = \033[0;31m
BLUE    = \033[0;34m
CYAN    = \033[0;36m
MAGENTA = \033[0;35m
YELLOW  = \033[0;33m
NC      = \033[0m

# -------------------------
# Explicit source files
# -------------------------
SRCS = cub3d.c \
       error/control.c \
       parser/file_parsing.c \
	   parser/parsing_utils.c \

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS = $(SRCS:.c=.o)

# -------------------------
# Rules
# -------------------------

all: $(NAME)

# libft
.PHONY: libft
libft:
	@echo "$(CYAN)Building libft...$(NC)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

# mlx
.PHONY: mlx
mlx:
	@echo "$(CYAN)Preparing MLX...$(NC)"
	@if [ ! -d "$(MLXOS)" ]; then \
		echo "$(YELLOW)MLX not found, cloning...$(NC)"; \
		if [ "$(OS_NAME)" = "Linux" ]; then \
			git clone https://github.com/42Paris/minilibx-linux $(MLXOS); \
		else \
			git clone https://github.com/42Paris/minilibx-macos $(MLXOS); \
		fi \
	fi
	@if [ -f "$(MLXOS)/Makefile" ]; then \
		$(MAKE) --no-print-directory -C $(MLXOS); \
	else \
		echo "$(RED)Error: No Makefile in $(MLXOS)$(NC)"; \
		exit 1; \
	fi

# main program
$(NAME): $(OBJS) libft mlx
	@echo "$(GREEN)Linking $(NAME)...$(NC)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLXFLAGS) -o $(NAME)

# compile objects
%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

# clean
clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -f $(OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean || true
	@if [ -f "$(MLXOS)/Makefile" ]; then \
		$(MAKE) --no-print-directory -C $(MLXOS) clean || true; \
	fi

# fclean
fclean: clean
	@echo "$(RED)Removing executables...$(NC)"
	@rm -f $(NAME)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean || true

# re
re: fclean all
	@echo "$(YELLOW)Rebuilding project...$(NC)"

# sanitize build
sanitize: CFLAGS += -fsanitize=address,undefined -O0 -fno-omit-frame-pointer -fno-optimize-sibling-calls
sanitize: re

# phony
.PHONY: all clean fclean re sanitize
