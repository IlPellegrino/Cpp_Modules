NAME = fixed

SRCS = main.cpp Fixed.cpp

OBJS = $(SRCS:.cpp=.o)

COMPILE = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp
	$(COMPILE) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Compiling.."
	$(COMPILE) $(OBJS) -o $(NAME)
	@echo "Done!"

clean:
	rm -rf $(OBJS)
	@echo "Cleaned!"

fclean: clean
	rm -rf $(NAME)
	@echo "Cleaned all!"

re: fclean all

.PHONY:

.SILENT:
