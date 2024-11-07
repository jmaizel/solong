# Makefile de la libft

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Répertoires
FT_PRINTF_DIR = ./ft_printffinal
GNL_DIR = ./gnl2
LIBFT_DIR = ./libftincludes

# Sources
FT_PRINTF_SRC = $(FT_PRINTF_DIR)/ft_printf.c \
                $(FT_PRINTF_DIR)/ft_check.c \
                $(FT_PRINTF_DIR)/ft_print_char.c \
                $(FT_PRINTF_DIR)/ft_print_str.c \
                $(FT_PRINTF_DIR)/ft_print_int.c \
                $(FT_PRINTF_DIR)/ft_print_unsigned.c \
                $(FT_PRINTF_DIR)/ft_print_pointeur.c \
                $(FT_PRINTF_DIR)/ft_print_lowercase.c \
                $(FT_PRINTF_DIR)/ft_print_highercase.c

GNL_SRC = $(GNL_DIR)/get_next_line.c

LIBFT_SRC = $(LIBFT_DIR)/ft_atoi.c \
            $(LIBFT_DIR)/ft_bzero.c \
            $(LIBFT_DIR)/ft_calloc.c \
            $(LIBFT_DIR)/ft_isalnum.c \
            $(LIBFT_DIR)/ft_isalpha.c \
            $(LIBFT_DIR)/ft_isascii.c \
            $(LIBFT_DIR)/ft_isdigit.c \
            $(LIBFT_DIR)/ft_isprint.c \
            $(LIBFT_DIR)/ft_itoa.c \
            $(LIBFT_DIR)/ft_memchr.c \
            $(LIBFT_DIR)/ft_memcmp.c \
            $(LIBFT_DIR)/ft_memcpy.c \
            $(LIBFT_DIR)/ft_memmove.c \
            $(LIBFT_DIR)/ft_memset.c \
            $(LIBFT_DIR)/ft_putchar_fd.c \
            $(LIBFT_DIR)/ft_putendl_fd.c \
            $(LIBFT_DIR)/ft_putnbr_fd.c \
            $(LIBFT_DIR)/ft_putstr_fd.c \
            $(LIBFT_DIR)/ft_split.c \
            $(LIBFT_DIR)/ft_strchr.c \
            $(LIBFT_DIR)/ft_strdup.c \
            $(LIBFT_DIR)/ft_striteri.c \
            $(LIBFT_DIR)/ft_strjoin.c \
            $(LIBFT_DIR)/ft_strlcat.c \
            $(LIBFT_DIR)/ft_strlcpy.c \
            $(LIBFT_DIR)/ft_strlen.c \
            $(LIBFT_DIR)/ft_strmapi.c \
            $(LIBFT_DIR)/ft_strncmp.c \
            $(LIBFT_DIR)/ft_strnstr.c \
            $(LIBFT_DIR)/ft_strrchr.c \
            $(LIBFT_DIR)/ft_strtrim.c \
            $(LIBFT_DIR)/ft_substr.c \
            $(LIBFT_DIR)/ft_tolower.c \
            $(LIBFT_DIR)/ft_toupper.c \
            $(LIBFT_DIR)/ft_lstadd_back_bonus.c \
            $(LIBFT_DIR)/ft_lstadd_front_bonus.c \
            $(LIBFT_DIR)/ft_lstclear_bonus.c \
            $(LIBFT_DIR)/ft_lstdelone_bonus.c \
            $(LIBFT_DIR)/ft_lstiter_bonus.c \
            $(LIBFT_DIR)/ft_lstlast_bonus.c \
            $(LIBFT_DIR)/ft_lstmap_bonus.c \
            $(LIBFT_DIR)/ft_lstnew_bonus.c \
            $(LIBFT_DIR)/ft_lstsize_bonus.c

SRC = $(FT_PRINTF_SRC) $(GNL_SRC) $(LIBFT_SRC)
OBJ = $(SRC:.c=.o)

INCLUDES = -I$(FT_PRINTF_DIR) -I$(GNL_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
