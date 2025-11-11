# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zaalrafa <zaalrafa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/07 21:37:09 by zaalrafa          #+#    #+#              #
#    Updated: 2025/11/11 19:18:46 by zaalrafa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBNAME = libft.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

RM = rm -f

SRCS = ft_printf.c functions/hexconvert.c functions/pointer_conv.c

OBJS = $(SRCS:.c=.o)

# Path to your libft directory
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/$(LIBNAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
