NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

COMPILE = c++ -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

%.o: %.cpp
		$(COMPILE) -c $< -o $@

$(NAME): $(OBJ)
		@echo "Compiled!"
		$(COMPILE) $(OBJ) -o $(NAME)

clean:
		@echo "cleaned!"
		rm -rf $(OBJ)

fclean: clean
		@echo "Fcleaned!"
		rm -rf $(NAME)

re: fclean all

.SILENT:

.PHONY: all clean fclean