NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_INCLUDES = $(LIBFT_DIR)/includes
MLX_DIR = ./minilibx
SRC_DIR = ./srcs

# Sources
SRC_FILES = draw_map.c \
            map.c \
            parsing.c \
            player.c \
            utils.c \
			backtraking.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)
OBJ += main.o 

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I$(LIBFT_INCLUDES) -I$(MLX_DIR) -I$(SRC_DIR) -I.

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

main.o: main.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
