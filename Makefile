# Makefile de so_long

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoires
FT_PRINTF_DIR = ./libft/ft_printffinal
GNL_DIR = ./libft/gnl2
LIBFT_DIR = ./libft
LIBFT_INCLUDES = $(LIBFT_DIR)/libftincludes
MLX_DIR = ./minilibx

# Sources
SRC = main.c
OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I$(FT_PRINTF_DIR) -I$(GNL_DIR) -I$(LIBFT_INCLUDES) -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
