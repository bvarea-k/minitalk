# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 09:39:40 by bvarea-k          #+#    #+#              #
#    Updated: 2025/08/12 11:35:04 by bvarea-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

INCLUDES = -I ./ -I $(LIBFT_DIR)

FILES_CLIENT = client
FILES_SERVER = server

SRC_DIR = ./
OBJ_DIR = ./

SRC_CLIENT = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES_CLIENT)))
SRC_SERVER = $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES_SERVER)))

OBJ_CLIENT = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_CLIENT)))
OBJ_SERVER = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES_SERVER)))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(CYAN)Compiling $(GRAY)$< $(CYAN)to $(BLUE)$@$(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_CLIENT) $(LIBFT) -o $(NAME_CLIENT)
	@echo "$(MAGENTA)Client compiled$(DEF_COLOR)"

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJ_SERVER) $(LIBFT) -o $(NAME_SERVER)
	@echo "$(MAGENTA)Server compiled$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(CYAN)Compiling $(GRAY)$< $(CYAN)to $(BLUE)$@$(DEF_COLOR)"
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_CLIENT) $(OBJ_SERVER)
	@$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)
	@echo "$(RED)Cleaned all files and executables$(DEF_COLOR)"

re: fclean all

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "$(GREEN)Libft compiled successfully$(DEF_COLOR)"

.PHONY: all clean fclean re

