NAME	= cub3D
CC		= cc
MLX_DIR	= mlx_linux
CFLAGS	= -Wall -Wextra -Iincludes
# CFLAGS	+= -Werror
CFLAGS	+= -I$(INC_DIR) -I$(MLX_DIR)
RM          = rm -rf
# MAKE_NP	= make --no-print-directory # not in use

# verify in detail what all of these do ///////////////////////////////////////
MLXFLGS	= -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

SRC_DIR = srcs/
OBJ_DIR = build/

SRCS    = $(addprefix $(SRC_DIR), main.c)

PARSE 		= init asset trim flood fill copy
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

# Does this rule impact the way we are compiling in Makefile? /////////////////

# You must use the miniLibX. Either the version that is available on the
# operating system, or from its sources. If you choose to work with the 
# sources, you will need to apply the same rules for your libft as those 
# written above in Common Instructions part.

# check for best practices when downloading ///////////////////////////////////
$(MLX_DIR):
	@echo "Cloning minilibx-linux from GitHub..."
	@git clone https://github.com/42paris/minilibx-linux.git $(MLX_DIR)
	@$(MAKE) -C $(MLX_DIR)

# I thought this was a good idea but we need to discuss this before submitting
clean:
	rm -rf $(OBJ_DIR) $(NAME)

# This also needs discussion before submission
fclean: clean
	rm -f $(NAME)

mlx_clean:
	$(RM) $(MLX_DIR)

re: fclean all

# remoeve custom rules ////////////////////////////////////////////////////////

total_makeover: clean mlx_clean

TESTMAP = assets/maps/huge.cub

go: all
	./$(NAME) $(TESTMAP)

do_over: clean all
	./$(NAME) $(TESTMAP)

norme:
	norminette srcs | grep -vE "header"

CFLAGS += -g
CFLAGS += -O3
VFLAGS += -s
VFLAGS += --track-fds=all
VFLAGS += --trace-children=yes
VFLAGS += --track-origins=yes --leak-check=full --show-leak-kinds=all

err: re
	clear
	valgrind $(VFLAGS) ./$(NAME) ./$(TESTMAP)

.PHONY: all clean fclean re