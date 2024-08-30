NAME = zombie

SRC = main.cpp zombieHorde.cpp Zombie.cpp

OBJ = $(SRC:.cpp=.o)

COMPILE = c++ -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

%.o: %.cpp
		$(COMPILE) -c $< -o $@

$(NAME): $(OBJ)
		$(COMPILE) $(OBJ) -o $(NAME)
		@echo "Compiled!"

clean:
		@echo "cleaned!"
		rm -rf $(OBJ)

fclean: clean
		@echo "Fcleaned!"
		rm -rf $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean