NAME	= cub3d
CC		= cc
MLX_DIR	= mlx_linux
CFLAGS	= -Wall -Werror -Wextra -Iincludes
CFLAGS	+= -I$(INC_DIR) -I$(MLX_DIR)
RM          = rm -rf
# MAKE_NP	= make --no-print-directory
MLXFLGS	= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

SRC_DIR = srcs/
OBJ_DIR = build/

SRCS    = $(addprefix srcs/, main.c parsing0.c parsing1.c)
OBJS    = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(MLX_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(MLX_DIR):
	@echo "Cloning minilibx-linux from GitHub..."
	@git clone https://github.com/42paris/minilibx-linux.git $(MLX_DIR)
	@$(MAKE) -C $(MLX_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

mlx_clean:
	$(RM) $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re