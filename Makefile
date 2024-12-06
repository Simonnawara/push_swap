# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sinawara <sinawara@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 19:34:08 by sinawara          #+#    #+#              #
#    Updated: 2024/11/12 19:34:08 by sinawara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap

# Directories
LIBFT				= ./libft/libft.a
INC					= inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f


# Source Files
OPERATIONS_DIR		=	$(SRC_DIR)operations/push.c \
						$(SRC_DIR)operations/swap.c \
						$(SRC_DIR)operations/rotate.c \
						$(SRC_DIR)operations/rev_rotate.c \
						$(SRC_DIR)operations/sort_three.c \
						$(SRC_DIR)operations/sort_stacks.c \

PVALUE_DIR		=		$(SRC_DIR)pvalue/main.c \
						$(SRC_DIR)pvalue/split.c \
						$(SRC_DIR)pvalue/pvalue_a_to_b.c \
						$(SRC_DIR)pvalue/pvalue_b_to_a.c \
						$(SRC_DIR)pvalue/define_stack.c \
						$(SRC_DIR)pvalue/stack_utils.c \
						$(SRC_DIR)pvalue/errors.c \

SRCS 				=	$(OPERATIONS_DIR) $(PVALUE_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build
start:
					@make all

$(LIBFT):
					@make -C ./libft

all: 				logo $(NAME)

logo:
	@printf "\033[1;35m      :::::::::  :::    :::  ::::::::  :::    :::            ::::::::  :::       :::     :::     ::::::::: \n"
	@printf "\033[1;35m     :+:    :+: :+:    :+: :+:    :+: :+:    :+:           :+:    :+: :+:       :+:   :+: :+:   :+:    :+: \n"
	@printf "\033[1;35m    +:+    +:+ +:+    +:+ +:+        +:+    +:+           +:+        +:+       +:+  +:+   +:+  +:+    +:+  \n"
	@printf "\033[1;35m   +#++:++#+  +#+    +:+ +#++:++#++ +#++:++#++           +#++:++#++ +#+  +:+  +#+ +#++:++#++: +#++:++#+    \n"
	@printf "\033[1;35m  +#+        +#+    +#+        +#+ +#+    +#+                  +#+ +#+ +#+#+ +#+ +#+     +#+ +#+           \n"
	@printf "\033[1;35m #+#        #+#    #+# #+#    #+# #+#    #+#           #+#    #+#  #+#+# #+#+#  #+#     #+# #+#            \n"
	@printf "\033[1;35m###         ########   ########  ###    ### ##########  ########   ###   ###   ###     ### ###             \n"
	@printf "\033[1;35m\t\t\t\t\t\t\t\t\t\t\t\tmade by me\n\n"


$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re logo