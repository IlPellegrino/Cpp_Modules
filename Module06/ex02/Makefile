NAME = base

SRC = main.cpp src/Base.cpp

COMPILE = c++ -g -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRC)
		@echo "Compiling..."
		$(COMPILE) $(SRC) -o $(NAME)
		@clear
		@echo "Done!"

clean:
		rm -rf $(NAME)
		@echo "Cleaned!"

re: clean all

.SILENT:

.PHONY: all clean re