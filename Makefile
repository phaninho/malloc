ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so
LINK = libft_malloc.so

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./libft/
LIB_PATH = ./libft/

SRC_NAME = malloc.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft
DEP = ./include/ft_malloc.h
TEST_NAME = exe_test

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: lib
	@echo "\033[37;44m Make $(NAME) \033[0m"
	@make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) $^ -o $@ $(LIB) $(LIB_NAME) -shared
	ln -sf $(NAME) $(LINK)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(DEP)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: lib clean fclean re

lib:
	@echo "\033[37;44m Make libft \033[0m"
	@make -C $(LIB_PATH)

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	@make -C $(LIB_PATH) fclean
	rm -f $(NAME) $(LINK) $(TEST_NAME)


re: fclean all

test:
	$(CC) src/main.c $(INC) $(LINK) -o $(TEST_NAME)

norme :
	@echo "\033[37;44m norme libft \033[0m"
	@norminette ./libft/*[ch]
	@echo "\033[37;44m norme src directory \033[0m"
	@norminette ./src/*.c
	@echo "\033[37;44m norme include directory \033[0m"
	@norminette ./include/*.h
