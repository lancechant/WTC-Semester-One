NAME = lem_in

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -g3

SRC_DIR = ./src/

LIB = -I includes/

SRCS = add_room_link.c ant_travels.c check_error.c fill_start.c \
		find_path_end.c free_functions.c get_map.c links.c main.c \
		print.c save_ants_rooms.c save_input.c save_room.c

SRC = $(addprefix $(SRC_DIR), $(SRCS))

OBJ = $(SRCS:.c=.o)

$(NAME):
	@echo "\033[0;31mCompiling libft"
	@make re -C libft/
	@echo "Compiling completed GG"
	@echo "Compiling lem_in"
	@$(CC) $(CFLAGS) $(LIB) -c $(SRC)
	@$(CC) -o $(NAME) $(OBJ) -L libft/ -lft
	@echo "Compilation successful\n"

all : $(NAME)

clean:
	@echo "\033[30;01mCleaning"
	@rm -f $(OBJ)
	@make -C libft/ clean
	@echo "Cleaned!\n"

fclean: clean
	@echo "\033[32;01mfull Cleaning"
	@rm -f $(OBJ)
	@rm -f $(NAME)
	@make -C libft/ fclean
	@echo "Cleaned!\n"

re: fclean all