NAME = RPN

SRC = main.cpp src/RPN.cpp

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

fclean: clean

re: clean all

.SILENT:

.PHONY: all clean fclean re