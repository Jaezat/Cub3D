NAME        = cub3D
MLX_DIR     = mlx_linux
SRC_FILES   = main
SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = include
CC          = cc
CFLAGS      = -g -Wall -Wextra -Werror -I$(INC_DIR) -I$(MLX_DIR)
RM          = rm -rf
MAKE        = make --no-print-directory

INCLUDE     = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

SRC         = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ         = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

all: $(MLX_DIR) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDE) -o $(NAME)
	@echo "$(NAME) compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(MLX_DIR):
	@echo "Downloading minilibx-linux..."
	@curl -s https://cdn.intra.42.fr/document/document/46338/minilibx-linux.tgz -o /tmp/mlx.tgz && \
		tar -xf /tmp/mlx.tgz -C /tmp && \
		cp -r /tmp/minilibx-linux $(MLX_DIR) && \
		rm -rf /tmp/mlx.tgz /tmp/minilibx-linux
	@$(MAKE) -C $(MLX_DIR)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "Objects removed"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(NAME) removed"

mlx_clean:
	@$(RM) $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re mlx_clean