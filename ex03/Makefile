NAME = bureaucrat

# sources
SRCS = main.cpp \
		Bureaucrat.cpp \
		BureaucratExceptions.cpp \
		BureaucratGrade.cpp \
		AForm.cpp \
		AFormExceptions.cpp \
		AFormGrade.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp \
		../toolbox/color.cpp \
		../toolbox/StepMark.cpp


OBJS = $(SRCS:.cpp=.o)

# compiler
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I..

# rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
