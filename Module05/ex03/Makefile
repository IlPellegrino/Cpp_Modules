NAME = Burro

SRC =	main.cpp src/Bureaucrat.cpp src/Form.cpp src/ShrubberyCreationForm.cpp \
		src/RobotomyRequestForm.cpp src/PresidentialPardonForm.cpp src/Intern.cpp

OBJ = $(SRC:.cpp=.o)

COMPILE = c++ -Wall -Wextra -Werror -g -std=c++98

all: $(NAME)

%.o: %.cpp
		$(COMPILE) -c $< -o $@

$(NAME): $(OBJ)
		$(COMPILE) $(OBJ) -o $(NAME)
		@clear
		@echo "Compiled!"

clean:
		@echo "cleaned!"
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)
		@echo "Fcleaned!"

re: fclean all

.SILENT:

.PHONY: all clean fclean