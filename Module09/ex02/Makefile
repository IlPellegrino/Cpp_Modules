NAME = PmergeMe

SRC = main.cpp src/PmergeMe.cpp

COMPILE = c++ -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

$(NAME): $(SRC)
		$(COMPILE) $(SRC) -o $(NAME)
		@clear
		@echo "Done!"

clean:
		rm -rf $(NAME)
		@clear
		@echo "All cleaned up!"

re: clean all

.SILENT:

.PHONY: all clean re