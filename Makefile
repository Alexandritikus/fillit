# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oshudria <oshudria@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/22 15:23:21 by oshudria          #+#    #+#              #
#    Updated: 2017/06/06 13:38:29 by oshudria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = fillit
CFLAGS = -Wall -Wextra -Werror

INCLUDES = -I./includes/

SRC_PATH = ./srcs/

SRC_NAME = fillit.c \
		ft_build_matrix.c \
		ft_check_free_space.c \
		ft_input.c \
		ft_output.c \
		ft_puterror.c \
		ft_solve.c \
		ft_t_check.c

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_NAME:.c=.o))

LIBFT = ./libft/libft.a
LIBFT_INC = -I./libft/includes/

COLOR_NONE = \033[0m
COLOR_YELLOW = \033[33m
COLOR_MAGENTA = \033[35m

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJ) $(LIBFT)
	@echo "$(COLOR_YELLOW)Fillit succesfully compiled.$(COLOR_NONE)"

$(OBJ_DIR)/%.o: ./srcs/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(LIBFT_INC) $(INCLUDES) -c -o $@ $<

clean:
	make clean -C ./libft
	@rm -rf $(OBJ_DIR)
	@echo "$(COLOR_MAGENTA)Fillit clean done.$(COLOR_NONE)"

fclean: clean
	@$(RM) $(NAME)
	make fclean -C ./libft
	@echo "$(COLOR_MAGENTA)Fillit fclean done.$(COLOR_NONE)"

re: fclean all
