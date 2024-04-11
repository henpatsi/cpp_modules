# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 19:32:04 by hpatsi            #+#    #+#              #
#    Updated: 2024/04/11 12:39:49 by hpatsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CLASSES = AMateria

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