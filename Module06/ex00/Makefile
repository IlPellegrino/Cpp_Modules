NAME = converter

SRC = main.cpp src/ScalarConverter.cpp

COMPILE = c++ -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

$(NAME):
		$(COMPILE) $(SRC) -o $(NAME)
		@clear
		@echo "Compiled"

clean:
		rm -rf $(NAME)
		@echo "cleaned!"

re: clean all

.SILENT:

.PHONY: all clean re
