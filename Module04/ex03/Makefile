NAME = animals

SRC = main.cpp src/Character.cpp src/Materia.cpp src/Cure.cpp src/Ice.cpp

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

.PHONY: all clean fclean

.SILENT: