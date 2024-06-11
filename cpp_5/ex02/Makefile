# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 11:20:16 by hpatsi            #+#    #+#              #
#    Updated: 2024/06/11 10:54:20 by hpatsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CLASSES = Bureaucrat AForm ShrubberyCreationForm RobotomyRequestForm PresidentialPardonForm

SOURCES = $(addsuffix .cpp, $(CLASSES)) main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

INCLUDES = $(addsuffix .hpp, $(CLASSES))

FLAGS = -Wall -Wextra -Werror -std=c++11

COMP = c++

all: $(NAME)

$(NAME): $(OBJECTS)
	$(COMP) $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
