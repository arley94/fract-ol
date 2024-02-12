# NAMES
NAME = fract-ol
NAME_BONUS = 

# LIBS
LIBS_DIR = libs/
FT_DIR = libft/libft.a
FTPRINTF_DIR = libftprintf/libftprintf.a
LIBFT = $(addprefix $(LIBS_DIR), $(FT_DIR))
LIBFTPRINTF = $(addprefix $(LIBS_DIR), $(FTPRINTF_DIR))

# SOURCE FILES
SRC_DIR = src/
BONUS_DIR = bonus/
SRC_FILES = main.c 	\
			complex_set.c \
			fractals.c \
			draw.c \
			events_handlers.c \
			zoom.c \
			parse_args.c \
			clean_exit.c

SRC 		= $(addprefix $(SRC_DIR), $(SRC_FILES))


# OBJECT FILES
OBJ_FILES = $(SRC:.c=.o)

# COMPILER OPTIONS
CC		= gcc
FLAGS	= -Wall -Werror -Wextra -g3
LMX_FLAGS = -lmlx -lXext -lX11
INCLUDE = -I /usr/include
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

$(NAME):	$(OBJ_FILES)
	@make -C libs/libft
	@make -C libs/libftprintf
	@echo "$(PINK)Compiling $(NAME).$(CLEAR)"
	$(CC) $(FLAGS) $(OBJ_FILES) $(INCLUDE) $(LIBFT) $(LIBFTPRINTF) -o $(NAME) $(LMX_FLAGS)
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

bonus:	$(NAME_BONUS)

$(NAME_BONUS):	$(OBJ_BONUS_FILES)
	@make -C libs/libft
	@make -C libs/libftprintf
	@echo "$(PINK)Compiling the CHECKER program.$(CLEAR)"
	$(CC) $(FLAGS) $(OBJ_BONUS_FILES) $(INCLUDE) $(LIBFT) $(LIBFTPRINTF) -o $(NAME_BONUS)
	@echo "$(GREEN)[OK]\n$(CLEAR)$(GREEN)Success!$(CLEAR)\n"

%.o: %.c
	$(CC) $(FLAGS) -c -o $@ $<

clean:
	@echo "$(PINK)Removing compiled files.$(CLEAR)"
	@make clean -C libs/libft
	@make clean -C libs/libftprintf
	$(RM) $(OBJ_FILES)
	@echo "$(GREEN)Object files removed correctly\n$(CLEAR)"

fclean: clean
	@make fclean -C libs/libft
	@make fclean -C libs/libftprintf
	$(RM) $(NAME) $(NAME_BONUS)
	@echo "$(GREEN)Exec. files removed correctly\nSuccess!$(CLEAR)"

re: fclean all

.PHONY:		all bonus clean fclean re