NAME	= cub3d
CC		= cc
MLX_DIR	= mlx_linux
CFLAGS	= -Wall -Werror -Wextra -Iincludes
CFLAGS	+= -I$(INC_DIR) -I$(MLX_DIR)
RM          = rm -rf
# MAKE_NP	= make --no-print-directory # not in use

# /////////////////////////////////////////////////////////////////////////////
# verify in detail what all of these do ///////////////////////////////////////
MLXFLGS	= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

SRC_DIR = srcs/
OBJ_DIR = build/

SRCS    = $(addprefix $(SRC_DIR), main.c)
SRCS	+= $(addprefix $(SRC_DIR)parser/, init.c assets.c gnl.c utils.c utils2.c)
# REMOVE TESTER REMOVE TESTER REMOVE TESTER REMOVE TESTER REMOVE TESTER /////////
SRCS	+= $(addprefix srcs/parser/, tester.c)
# SRCS	+= $(addprefix $(SRC_DIR)execdirname/, ex1.c ex2.c ex3.c)
OBJS    = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(MLX_DIR) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# /////////////////////////////////////////////////////////////////////////////
# Does this rule impact the way we are compiling in Makefile? /////////////////

# You must use the miniLibX. Either the version that is available on the
# operating system, or from its sources. If you choose to work with the 
# sources, you will need to apply the same rules for your libft as those 
# written above in Common Instructions part.

# /////////////////////////////////////////////////////////////////////////////
# check for best practices when downloading ///////////////////////////////////
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

parse: re
	sleep 0.3
	clear
	./cub3d assets/maps/valid.cub

VFLAGS += --track-fds=all
VFLAGS += --track-origins=yes --leak-check=full --show-leak-kinds=all -s

parsev: re
	sleep 0.3
	clear
	valgrind $(VFLAGS) ./cub3d assets/maps/valid.cub

.PHONY: all clean fclean re
