NAME	= cub3D
CC		= cc
MLX_DIR	= mlx_linux
CFLAGS	= -Wall -Wextra -Iincludes
CFLAGS	+= -Werror
CFLAGS	+= -I$(INC_DIR) -I$(MLX_DIR)
RM          = rm -rf

MLXFLGS	= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lX11 -lXext -lm -lz

SRC_DIR = srcs/
OBJ_DIR = build/

SRCS    = $(addprefix $(SRC_DIR), main.c)

PARSE 		= init asset trim flood fill fill_h copy
RAYCAST		= raycast puts dda power col_draw
UTILS		= gnl utl0 utl1 exit exit_helper
W_FILES 	= game loop keys movement utils
SRCS	+= $(addprefix srcs/parser/, $(addsuffix .c, $(PARSE)))
SRCS	+= $(addprefix srcs/raycast/, $(addsuffix .c, $(RAYCAST)))
SRCS	+= $(addprefix srcs/utils/, $(addsuffix .c, $(UTILS)))
SRCS	+= $(addprefix srcs/windows/, $(addsuffix .c, $(W_FILES)))


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
	$(RM) $(OBJ_DIR) $(NAME)

fclean: clean
	$(RM) $(NAME)

mlx_clean:
	$(RM) $(MLX_DIR)

re: fclean all

# testing /////////////////////////////////////////////////////////////////////
TESTMAP = assets/maps/big.cub

go: all
	./$(NAME) $(TESTMAP)

CFLAGS += -g
CFLAGS += -O3
VFLAGS += -s
VFLAGS += --track-fds=yes
VFLAGS += --track-origins=yes --leak-check=full --show-leak-kinds=all

err:
	valgrind $(VFLAGS) ./$(NAME) ./$(TESTMAP)

.PHONY: all clean fclean re