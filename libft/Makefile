# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvarea-k <bvarea-k@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/25 08:59:04 by bvarea-k          #+#    #+#              #
#    Updated: 2025/08/06 13:02:17 by bvarea-k         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c ft_strlen.c ft_bzero.c \
	ft_memset.c ft_memcpy.c ft_memcmp.c ft_strlcpy.c \
	ft_memmove.c ft_atoi.c ft_strchr.c ft_strrchr.c \
	ft_memchr.c ft_strncmp.c ft_strnstr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_strlcat.c ft_calloc.c \
	ft_substr.c ft_strdup.c ft_strjoin.c ft_strtrim.c \
	ft_strmapi.c ft_striteri.c ft_itoa.c ft_putnbr_fd.c ft_split.c \
	ft_print_char.c ft_print_str.c ft_print_percentage.c \
	ft_print_nbr.c ft_print_nbr_u.c ft_printf.c ft_print_hex.c \
	ft_print_ptr.c get_next_line.c get_next_line_utils.c ft_strcmp.c

SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
			ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstclear_bonus.c \
			ft_lstiter_bonus.c ft_lstdelone_bonus.c ft_lstmap_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

HEADER = libft.h
AR = ar rcs
RM = rm -f

.PHONY: all clean fclean re bonus

all: $(NAME)

bonus: $(OBJ_BONUS)
	@$(AR) $(NAME) $(OBJ_BONUS)

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)

$(OBJ_BONUS): $(SRC_BONUS)
	@$(CC) $(CFLAGS) -c $(SRC_BONUS) $(SRC)

clean:
	@$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
