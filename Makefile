# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoel-idr <yoel-idr@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/20 10:07:45 by yoel-idr          #+#    #+#              #
#    Updated: 2022/10/24 08:49:26 by yoel-idr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./srcs/ft_building.c ./srcs/ft_format_print.c ./srcs/ft_itoa.c ./srcs/ft_utils.c ./srcs/ft_printf.c \

SRCB = ./srcs/ft_building.c ./srcs/ft_format_print.c ./srcs/ft_itoa.c ./srcs/ft_utils.c ./srcs/ft_printf_bonus.c 

OBJS = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror
AR = ar -rc

all : $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "simple printf"
bonus : fclean $(OBJB)
		@$(AR) $(NAME) $(OBJB)
		@echo "printf with flags (+ ' ' #)"
.c.o:
		@echo compiling $< ...
		@$(CC) -c $< -o $@	
clean :
		@$(RM) $(OBJS) $(OBJB)
		@echo remove all obj file
fclean : clean
		@$(RM) $(NAME)
		@echo remove all
re 	   : fclean all
		@echo update ft_printf
