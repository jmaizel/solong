NAME = so_long
NAME_BONUS = so_long_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = ./libft
LIBFT_INCLUDES = $(LIBFT_DIR)/includes
MLX_DIR = ./minilibx

SRC_DIR = ./srcs
SRC_BONUS_DIR = ./srcs_bonus

# Fichiers sources pour la version normale
SRC_FILES = backtraking.c \
            draw_map.c \
            map.c \
            map_borders.c \
            parsing.c \
            player.c \
            utils.c \
            main.c

# Fichiers sources pour la version bonus
BONUS_FILES = draw_map_bonus.c \
              main_bonus.c \
              map_bonus.c \
              player_bonus.c \
              map_borders_bonus.c \
              utils_bonus.c \
			  parsing_bonus.c \
			  backtraking_bonus.c

# Création des listes d'objets
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:.c=.o)

BONUS_SRC = $(addprefix $(SRC_BONUS_DIR)/, $(BONUS_FILES))
BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.a

MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
INCLUDES = -I$(LIBFT_INCLUDES) -I$(MLX_DIR) -I$(SRC_DIR) -I.

# Règles principales
all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(BONUS_OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)

# Compilation des objets
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SRC_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Compilation des dépendances
$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@$(MAKE) -C $(MLX_DIR)

# Nettoyage
clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
