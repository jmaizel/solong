NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Dossiers
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx
SRC_DIR = ./src

# Fichiers sources
SRC = $(SRC_DIR)/main.c $(SRC_DIR)/game_loop.c $(SRC_DIR)/map_parser.c \
      $(SRC_DIR)/player_controls.c $(SRC_DIR)/render.c

OBJ = $(SRC:.c=.o)

# Fichiers de librairie
LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

# Flags pour lier MLX, X11, OpenGL, AppKit
MLX_FLAGS = -L$(MLX_DIR) -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
INCLUDES = -I$(LIBFT_DIR) -I$(MLX_DIR) -I/opt/X11/include

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

.c.o:
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
