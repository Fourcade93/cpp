SRC := main.cpp
OBJ := $(SRC:.cpp=.o)
NAME = temp
CC = clang++
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $@ $^
	@echo "\033[0;32m$@ is create"

%.o: %.cpp
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all