NAME = btc

SRC = main.cpp src/BitcoinExchange.cpp

COMPILE = c++ -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

$(NAME): $(SRC)
		$(COMPILE) $(SRC) -o $(NAME)
		@clear
		@echo "Done!"

clean:
		rm -rf $(NAME)
		@echo "All cleaned up!"

fclean: clean

re: clean all

.SILENT:

.PHONY: all clean fclean re