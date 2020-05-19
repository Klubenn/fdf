NAME = fdf

LIBFT_DIR = ./libft/
LIBFT = lft
LIBFTLIB = ./libft/libft.a

MLX_DIR = ./miniLibX/
MLX = lmlx
LIBMLX = ./miniLibX/libmlx.a
FLAGS_MLX = -framework OpenGL -framework AppKit

INCL_DIR = ./includes/
INCL_H = fdf.h fdf_defines.h fdf_structures.h
INCL = $(addprefix $(INCL_DIR),$(INCL_H))

SRC_DIR = src/
SRC_C = main.c gradient.c vizualization.c color.c fdf_draw.c fdf_read.c error.c
SRC = $(addprefix $(SRC_DIR),$(SRC_C))

FLAGS =	-Wall -Werror -Wextra

all: $(LIBFT_DIR)$(LIBFT) $(MLX_DIR)$(MLX) $(NAME)

$(LIBFT_DIR)$(LIBFT):
	make -C $(LIBFT_DIR)

$(MLX_DIR)$(MLX):
	make -C $(MLX_DIR)

$(NAME): $(SRC) $(INCL) $(LIBFTLIB) $(LIBMLX)
	gcc $(FLAGS) $(SRC) -I$(INCL_DIR) -I $(MLX_DIR) -I$(LIBFT_DIR) -L$(LIBFT_DIR) -$(LIBFT) \
	-L$(MLX_DIR) -$(MLX) $(FLAGS_MLX) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)

fclean:
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re
