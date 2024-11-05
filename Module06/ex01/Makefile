NAME = serializer

SRC = main.cpp src/Serializer.cpp

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

fclean: clean

re: fclean all

.SILENT:

.PHONY: all clean  fclean re