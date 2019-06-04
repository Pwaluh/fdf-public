# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: judrion <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/20 16:15:36 by judrion           #+#    #+#              #
#    Updated: 2019/06/04 18:20:07 by judrion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = brezenham color error free_data key_hook load_file main mouse_hook \
	  render get_next_line
SRCS = $(addprefix src/, $(addsuffix .c, $(SRC)))
OBJ = $(SRCS:.c=.o)
INCLUDE = -Llibft/ -Lminilibx/
LIB = -lft -lmlx -Ilibft/ -Iminilibx -Iincludes/
CFLAG = -Wall -Werror -Wextra -Iincludes/
DCFLAG = -Wall -Werror -Wextra -Iincludes/ -fsanitize=address
FRAMEWORK = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	$(MAKE) -C libft/
	$(MAKE) -C minilibx/
	gcc $(DCFLAG) -o $(NAME) $(INCLUDE) $(LIB) $(SRCS) $(FRAMEWORK)

.PHONY: clean fclean re lclean

lclean:
	@echo "Clean des librairies"
	@$(MAKE) -C libft/ fclean
	@$(MAKE) -C minilibx/ clean
clean:
	@echo "Clean des fichiers .o"
	@$(RM) $(OBJ)

fclean: clean
	@echo "Clean $(NAME)"
	@$(RM) $(NAME)

re: fclean all
