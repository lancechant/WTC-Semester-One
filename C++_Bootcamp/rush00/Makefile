# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prussell <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/04 15:03:32 by prussell          #+#    #+#              #
#    Updated: 2018/06/10 15:31:26 by prussell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro 

SRCS = srcs/BaseElement.cpp \
 srcs/DrawElement.cpp \
 srcs/Enemy.cpp \
 srcs/Environment.cpp \
 srcs/Hero.cpp \
 srcs/main.cpp \
 srcs/Missile.cpp \
 srcs/Mountain.cpp \
 srcs/Render.cpp \
 srcs/Screen.cpp \
 srcs/Collision.cpp


INCLUDES = includes

COMPILER = clang++

FLAGS = -Wall -Werror -Wextra -lncurses -iquote$(INCLUDES)

NONE = \x1b[0m
OK = \x1b[32;01m
WARN = \x1b[33;01m

all: $(NAME)

$(NAME):
	@echo "$(OK)----------   Compile $(NAME)----------$(NONE)"
	@$(COMPILER) -o $(NAME) $(SRCS) $(FLAGS)
	@echo "$(OK)----------     Success     ----------$(NONE)\n"

clean:
	@echo "$(WARN)----------    Clean $(NAME)----------$(NONE)"
	@rm -f $(NAME)
	@echo "removed $(NAME)"
	@echo "$(WARN)----------     Success     ----------$(NONE)\n"

fclean:
	@echo "$(WARN)----------    FClean $(NAME)----------$(NONE)"
	@rm -f $(NAME)
	@echo "removed $(NAME)"
	@echo "$(WARN)----------     Success     ----------$(NONE)\n"

re: fclean all
