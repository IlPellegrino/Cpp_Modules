NAME = converter

SRC = main.cpp src/ScalarConverter.cpp

COMPILE = c++ -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

$(NAME): $(SRC)
		$(COMPILE) $(SRC) -o $(NAME)
		@clear
		@echo "Compiled"

clean:
		rm -rf $(NAME)
		@echo "cleaned!"

fclean: clean

re: fclean all

.SILENT:

.PHONY: all clean fclean re
