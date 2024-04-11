# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 19:32:04 by hpatsi            #+#    #+#              #
#    Updated: 2024/04/11 09:01:49 by hpatsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = diamondtrap

CLASSES = ClapTrap ScavTrap FragTrap DiamondTrap

SOURCES = $(addsuffix .cpp, $(CLASSES)) main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

INCLUDES = $(addsuffix .hpp, $(CLASSES))

FLAGS = -Wall -Wextra -Werror -Wshadow -std=c++11

COMP = g++

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
	$(COMP) $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp $(INCLUDES)
	$(COMP) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all