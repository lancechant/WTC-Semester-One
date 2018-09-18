# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lchant <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/30 18:53:28 by lchant            #+#    #+#              #
#    Updated: 2017/09/30 19:20:40 by lchant           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = launch_program.c minishell.c remove_quotes.c builtins/unsetenv.c builtins/setenv.c ft_load_list.c\
	command_list.c get_env.c builtins/echo.c builtins/cd.c builtins/exit.c builtins/env.c memory_check.c\
	process_input.c formatting.c debug.c arg_list.c ft_split_semi.c builtins/args_check.c signals.c

NAME = minishell

LIB = -Llibft -lft

FLAGS = -Wall -Wextra -Werror

VALGRIND = -g -O0

TERMCAPS = -lncurses

define blink
tput blink
tput setaf 6
@echo $1
tput sgr0
endef

all: clean
	@echo "\033[92m\nDONE\033[0m"
	@echo "\033[1;97m\ncompliling libft\033[0m"
	@(cd libft && make re --no-print-directory) 
	@echo "\033[94m\nDONE\033[0m"
	@echo "\033[95m\nCOMPLILING MINISHELL\033[m"
	@gcc $(SRC) -o $(NAME) $(LIB) $(VALGRIND) $(TERMCAPS)
	@$(call blink, ".")
	@sleep 0.5
	@$(call blink, "..")
	@sleep 0.5
	@$(call blink, "【")
	@sleep 0.5
	@$(call blink, "【ツ")
	@sleep 0.5
	@$(call blink, "【ツ】")
	@sleep 0.5
	@$(call blink, "【ツ】>")
	@sleep 0.5
	@$(call blink, "【ツ】>:")
	@echo "\033[96mDONE\033[0m"

clean:
	@echo "\033[1;91mCLEANING REPO\033[m"
	@(cd libft  && make fclean --no-print-directory)
	@/bin/rm -rf minishell.DSYM
fclean: clean
	@echo "\033[1;91mREMOVING EXECUTABLE\033[m"
	@/bin/rm -rf $(NAME)
re: fclean all

.PHONY: clean fclean re
