CLIENT	= client

CC		= gcc
FLAGS	= -Wall -Werror -Wextra
# FLAGS    = -Wall -Werror -Wextra
SRC		= src/main.c \
	src/ops_base.c \
	src/ops.c \
	src/print.c \
	src/radix_sort.c \
	src/small_sort.c \
	src/sort.c \
	src/utils.c

OBJ		= $(SRC:.c=.o)
NAME	= push_swap
LIBFT	= libft/libft.a

GREEN	= \033[92;1m
NOCOLOR	= \033[0m # No Color

all :	$(NAME)

$(LIBFT):
	@echo "$(GREEN)\nMAKING LIBFT$(NOCOLOR)"
	@$(MAKE) -C ./libft

$(NAME) :	$(OBJ) $(LIBFT)
	@echo "$(GREEN)\nBUILDING push_swap$(NOCOLOR)"
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\n"

# $(CLIENT) :	$(CLIENT_OBJ)
# 	@echo "Building client"
# 	$(CC) $(CLIENT_SRC) -I minitalk.h -o client

clean :
	@rm -rf ./src/*.o
	@$(MAKE) clean -C ./libft

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C ./libft

re: fclean all

.PHONY : all clean fclean
