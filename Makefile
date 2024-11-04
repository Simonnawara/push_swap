# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/02 12:06:45 by sinawara          #+#    #+#              #
#    Updated: 2024/11/04 13:03:48 by sinawara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = main.c push.c swap.c rotate.c reverse.c #to change

CC = gcc
CCFLAG = -Wall -Werror -Wextra
LIB = -C ./libft/

SUCCESS_COLOR = \033[32m

OBJ_DIR = obj
OBJECT = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
D_SRCS = ./src/

all : $(NAME)

$(OBJ_DIR)/%.o: $(D_SRCS)%.c | $(OBJ_DIR)
	@$(CC) $(CCFLAG) -I./libft -I/includes -o $@ -c $<

# Create obj directory if it doesn't exist
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME) : $(OBJECT)
	@make $(LIB)
	@$(CC) $(CCFLAG) -o $(NAME) $(OBJECT) -L./libft -lft
	@echo "$(SUCCESS_COLOR)$(NAME) - Compiled with Success"

clean :
	@make clean $(LIB)
	@echo "$(SUCCESS_COLOR)$(NAME) - Cleaned with Success"
	@/bin/rm -rf $(OBJ_DIR)

fclean : clean
	@make fclean $(LIB)
	@rm -rf ./$(NAME)
	@echo "$(SUCCESS_COLOR)$(NAME) - FCleaned with Success"

re : fclean all

.PHONY: all clean fclean re