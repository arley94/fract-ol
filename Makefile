# NAMES
NAME = fractol

# COMPILER OPTIONS
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g3

# DEFINE OS MAC OR LINUX
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
    FLAGS += -D LINUX
	OS = linux
else
	FLAGS += -D MAC
	OS = mac
endif

# MINILIBX
ifeq ($(OS), linux)
	MLX_PATH	= minilibx-linux/
	MLX_NAME	= libmlx.a
	MLX			= $(MLX_PATH)$(MLX_NAME)
	MLX_FLAGS 	= -lmlx -lXext -lX11
else
	MLX_PATH	= minilibx-mac/
	MLX_NAME	= libmlx.a
	MLX			= $(MLX_PATH)$(MLX_NAME)
	MLX_FLAGS	= -lmlx -framework OpenGL -framework AppKit
endif

# LIBS
LIBS_PATH = libs/

# LIBFT
LIBFT_PATH 	= $(LIBS_PATH)libft/
LIBFT_NAME 	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

# LIBFTPRINTF
LIBFTPRINTF_PATH 	= $(LIBS_PATH)libftprintf/
LIBFTPRINTF_NAME 	= libftprintf.a
LIBFTPRINTF			= $(LIBFTPRINTF_PATH)$(LIBFTPRINTF_NAME)

#INCLUDES
INCLUDE = -I ./includes/

# SOURCE FILES
SRC_PATH	= src/
SRC_FILES	= main.c 	\
			  fractals.c \
			  draw.c \
			  events_handlers_1.c \
			  events_handlers_2.c \
			  render.c \
			  parse_args.c \
			  init.c \
			  clean_exit.c
SRC 		= $(addprefix $(SRC_DIR), $(SRC_FILES))


# OBJECT FILES
OBJ_PATH	= obj/
OBJ_FILES	:= $(SRC:.c=.o)
OBJ 		:= $(addprefix $(OBJ_PATH), $(OBJ_FILES))

# COMMANDS
RM		= rm -f

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
YELLOW	=	\033[93;1m
BLUE	=	\033[94;1m
PINK	=	\033[95;1m
CLEAR	=	\033[0m

# MAKEFILE RULES
all:	$(NAME)

$(NAME): $(MLX) $(LIBFT) $(LIBFTPRINTF) $(OBJ_PATH) $(OBJ)
	@echo "$(PINK)Compiling $(NAME).$(CLEAR)"
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(INCLUDE) $(LIBFT) $(LIBFTPRINTF) $(MLX) $(MLX_FLAGS)
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)

$(LIBFTPRINTF):
	@echo "Making libftprintf..."
	@make -sC $(LIBFTPRINTF_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(FLAGS) -c -o $@ $< $(INCLUDE)

#$(OBJ): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

clean:
	@echo "$(PINK)Removing .o object files.$(CLEAR)"
	@rm -rf $(OBJ_PATH)
	@make clean -sC $(LIBFT_PATH)
	@make clean -sC $(LIBFTPRINTF_PATH)
	@make clean -sC $(MLX_PATH)
	@echo "$(GREEN)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@make fclean -sC $(LIBFT_PATH)
	@make fclean -sC $(LIBFTPRINTF_PATH)
	@$(RM) $(NAME)
	@echo "$(GREEN)Exec. files removed correctly\nSuccess!$(CLEAR)"

re: fclean all

.PHONY:		all clean fclean re