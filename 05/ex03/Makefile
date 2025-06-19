# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sishizaw <sishizaw@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/12 21:01:04 by sishizaw          #+#    #+#              #
#    Updated: 2025/06/14 06:02:50 by sishizaw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
       AForm.cpp \
       Bureaucrat.cpp \
       PresidentialPardonForm.cpp \
       RobotomyRequestForm.cpp \
       ShrubberyCreationForm.cpp \
       Intern.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = bureaucrat_forms

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all


