NAME = pipex

LIBFT = ./libft

MY_SOURCES =	pipex.c 		\
				pipex_utils.c	\
				free_pipes.c

MY_SRC_BONUS =	pipex_bonus.c		\
				pipex_utils_bonus.c	\
				free_pipes_bonus.c

MY_OBJECTS = $(MY_SOURCES:.c=.o)

C_GREEN = \033[0;32m

C_RED = \033[0;31m

C_BLUE = \033[0;34m

C_END=\033[0m

MY_OBJ_BONUS = $(MY_SRC_BONUS:.c=.o)

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g3

all: $(NAME)

$(NAME): $(MY_OBJECTS) makelibft
	@gcc $(CFLAGS) -o $(NAME) $(MY_OBJECTS) $(LIBFT)/libft.a
	@echo "$(C_GREEN)$(NAME) compiled$(C_END)"

bonus: $(MY_OBJ_BONUS) makelibft
	@gcc $(CFLAGS) -o $(NAME) $(MY_OBJ_BONUS) $(LIBFT)/libft.a
	@echo "$(C_GREEN)$(NAME)'s bonus compiled$(C_END)"

makelibft:
	@make -C $(LIBFT)

%.o:	%.c
	@gcc ${CFLAGS} -I . -c $< -o $@

clean:
	@rm -rf $(MY_OBJECTS) $(MY_OBJ_BONUS)
	@make clean -C $(LIBFT)
	@echo "$(C_RED)$(NAME) cleanse$(C_END)"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)/libft.a
	@echo "$(C_RED)Update: Herobrine has been removed.$(C_END)"

re: fclean all

.PHONY: all clean fclean re