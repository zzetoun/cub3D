# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zzetoun <zzetoun@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/15 13:30:00 by zzetoun           #+#    #+#              #
#    Updated: 2025/08/15 14:00:00 by zzetoun          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cub3D

SRC_DIR     = srcs
UTIL_DIR	= $(SRC_DIR)/utils
LIBFT_DIR   = $(UTIL_DIR)/libft
LIBFT_LIB   = $(LIBFT_DIR)/libft.a

OS_NAME     = $(shell uname)
ifeq ($(OS_NAME), Linux)
MLXOS       = $(UTIL_DIR)/mlx/minilibx-linux
MLX_LIB     = $(MLXOS)/libmlx.a
MLXFLAGS    = -L$(MLXOS) -lmlx -L/usr/lib -I$(MLXOS) -lXext -lX11 -lm
else
MLXOS       = $(UTIL_DIR)/mlx/mlx-mac
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

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJS = $(SRCS:.c=.o)

# -------------------------
# Rules
# -------------------------

all: $(NAME)

# Build libft
$(LIBFT_LIB):
	@echo "$(CYAN)Building libft...$(NC)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)

# Build mlx
$(MLX_LIB):
	@echo "$(CYAN)Building mlx...$(NC)"
	@$(MAKE) --no-print-directory -C $(MLXOS)

# Build main executable
$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@echo "$(GREEN)Linking $(NAME)...$(NC)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLXFLAGS) -o $(NAME)

# Build bonus executable
$(NAME_BONUS): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@echo "$(GREEN)Linking $(NAME_BONUS)...$(NC)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLXFLAGS) -o $(NAME_BONUS)

# Compile object files
%.o: %.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(NC)"
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -f $(OBJS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean
	@$(MAKE) --no-print-directory -C $(MLXOS) clean

# Full clean including executables
fclean: clean
	@echo "$(RED)Removing executables...$(NC)"
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

# Rebuild everything
re: fclean all
	@echo "$(YELLOW)Rebuilding project...$(NC)"

# Optional: sanitize build
sanitize: CFLAGS += -fsanitize=address,undefined -O0 -fno-omit-frame-pointer -fno-optimize-sibling-calls
sanitize: re

# -------------------------
# Phony targets
# -------------------------
.PHONY: all clean fclean re sanitize
