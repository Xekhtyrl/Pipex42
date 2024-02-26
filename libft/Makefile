NAME = libft.a

#__________ PATHWAY __________#

ASCII_DIR =	./Sources/ft_is_ascii

LIST_DIR = ./Sources/ft_list

MEM_DIR = ./Sources/ft_mem_manip

STR_DIR = ./Sources/ft_string_manip

PUT_DIR = ./Sources/ft_write

GNL_DIR = ./Sources/Get_Next_Line

PRINTF_DIR = ./Sources/libftprintf

OTH_DIR = ./Sources/others

HEADERS = ./headers

#__________ REGROUP __________#

MY_SOURCES =	$(ASCII_DIR)/ft_isalpha.c	$(STR_DIR)/ft_strlcpy.c		$(LIST_DIR)/ft_lstnew.c 			\
				$(ASCII_DIR)/ft_isdigit.c	$(STR_DIR)/ft_strlcat.c		$(LIST_DIR)/ft_lstadd_front.c 		\
				$(ASCII_DIR)/ft_isalnum.c	$(STR_DIR)/ft_toupper.c		$(LIST_DIR)/ft_lstsize.c 			\
				$(ASCII_DIR)/ft_isascii.c	$(STR_DIR)/ft_tolower.c		$(LIST_DIR)/ft_lstlast.c 			\
				$(ASCII_DIR)/ft_isprint.c	$(STR_DIR)/ft_strchr.c		$(LIST_DIR)/ft_lstadd_back.c 		\
				$(MEM_DIR)/ft_memset.c		$(STR_DIR)/ft_strrchr.c		$(LIST_DIR)/ft_lstdelone.c			\
				$(MEM_DIR)/ft_bzero.c		$(STR_DIR)/ft_strncmp.c		$(LIST_DIR)/ft_lstclear.c			\
				$(MEM_DIR)/ft_memcpy.c		$(STR_DIR)/ft_strnstr.c		$(LIST_DIR)/ft_lstiter.c			\
				$(MEM_DIR)/ft_memmove.c		$(STR_DIR)/ft_strdup.c		$(LIST_DIR)/ft_lstmap.c				\
				$(MEM_DIR)/ft_memcmp.c		$(STR_DIR)/ft_substr.c		$(PRINTF_DIR)/ft_printf_utils.c		\
				$(MEM_DIR)/ft_memchr.c		$(STR_DIR)/ft_strjoin.c		$(PRINTF_DIR)/ft_printf_utils2.c	\
				$(STR_DIR)/ft_strlen.c		$(STR_DIR)/ft_strtrim.c		$(PRINTF_DIR)/ft_printf.c			\
				$(PUT_DIR)/ft_putchar_fd.c	$(STR_DIR)/ft_split.c				\
				$(PUT_DIR)/ft_putstr_fd.c	$(STR_DIR)/ft_strmapi.c				\
				$(PUT_DIR)/ft_putendl_fd.c	$(STR_DIR)/ft_striteri.c			\
				$(PUT_DIR)/ft_putnbr_fd.c	$(GNL_DIR)/get_next_line.c			\
				$(OTH_DIR)/ft_atoi.c		$(GNL_DIR)/get_next_line_utils.c	\
				$(OTH_DIR)/ft_calloc.c		\
				$(OTH_DIR)/ft_itoa.c
				
MY_OBJECTS = $(MY_SOURCES:.c=.o)

CFLAGS = -Wall -Werror -Wextra

#___________ RULES ___________#

all: $(NAME)

$(NAME): $(MY_OBJECTS) $(HEADERS)
	@ar rc $(NAME) $(MY_OBJECTS)
	@echo "all files have been compiled"
	@echo "libft.a created"

%.o:	%.c
	@gcc ${CFLAGS} -I $(HEADERS) -c $< -o $@

clean:
	@rm -rf $(MY_OBJECTS)
	@echo "browser hystory cleared, you are safe now"

fclean: clean
	@rm -rf $(NAME)
	@echo "there is nothing to see here"

re: fclean all

.PHONY: all clean fclean re