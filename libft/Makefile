SRC_FILE = ft_memset ft_memcpy ft_bzero ft_memccpy ft_memmove ft_memchr \
		   ft_memcmp ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strchr \
		   ft_strcat ft_strncat ft_strlcat ft_strrchr ft_strstr ft_strnstr \
		   ft_strcmp ft_strncmp ft_isalpha ft_islower ft_isupper \
		   ft_isdigit ft_atoi ft_isalnum ft_isascii ft_isprint \
		   ft_tolower ft_toupper ft_iswhitespace ft_memalloc ft_memdel \
		   ft_strnew ft_strdel ft_strclr ft_striter ft_striteri \
		   ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub \
		   ft_strjoin ft_strtrim ft_itoa_base ft_itoa ft_strrev ft_putchar \
		   ft_putstr ft_putendl ft_putchar_fd ft_putstr_fd ft_putendl_fd \
		   ft_strsplit ft_putnbr ft_putnbr_fd ft_utf8_encode ft_print_byte \
		   ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter ft_lstmap \
		   ft_utf8_decode memswap ft_reverse_list init_thread_pool job \
		   semaphore timeout thread
SRCS = $(addsuffix .c, $(SRC_FILE))
OBJ = $(SRCS:.c=.o)
OBJS = $(SRCS:%.c=%.o)
NAME = libft.a
FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creation de : $(NAME)"
	@ar rc $(NAME) $(OBJ)
	@echo "Indexage de : $(NAME)"
	@ranlib $(NAME)


.PHONY: clean fclean re

clean:
	@echo "Suppression de : $(OBJS)"
	@$(RM) $(OBJS)

fclean: clean
	@echo "Suppression de : $(NAME)"
	@$(RM) $(NAME)

re: fclean all
