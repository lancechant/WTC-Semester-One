NAME =				avm

CC =				clang++ -std=c++11

FLAGS =				-Wall -Werror -Wextra -g

COMPILED_DIR_NAME =	compiled
COMPILED_DIR =		./$(COMPILED_DIR_NAME)/

FILENAMES =			main

COMPILED_PATHS :=	$(addsuffix .o,$(FILENAMES))
COMPILED_PATHS :=	$(addprefix $(COMPILED_DIR),$(COMPILED_PATHS))

all: $(NAME)
	@echo "\033[1;30mReady type ./avm to begin :)\033[0m"

$(NAME): $(COMPILED_PATHS)
	@$(CC) -o $(NAME) $(FLAGS) $(HEADERS) $(COMPILED_PATHS)
	@echo "\033[92mAll .o Files complied and put into /compiled\033[0m"

$(COMPILED_PATHS): $(COMPILED_DIR)%.o: $(SRC_DIR)%.cpp
	@/bin/mkdir -p $(COMPILED_DIR)
	@echo "\033[1;35mMaking Compiled Folder\033[0m"
	@$(CC) -c $(FLAGS) $(HEADERS) $< -o $@

clean:
	@-/bin/rm -f $(COMPILED_PATHS)
	@echo "\033[1;31mRemoving .o files\033[0m"
	@/usr/bin/find . -name "$(COMPILED_DIR_NAME)" -maxdepth 1 -type d -empty -delete
	@echo "\033[1;31mRemoving compiled folder\033[0m"

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "\033[1;31mRemoving ./avm\033[0m"

re: fclean all
