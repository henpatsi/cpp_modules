# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/12 13:17:41 by hpatsi            #+#    #+#              #
#    Updated: 2024/08/30 14:50:43 by hpatsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

SOURCES = main.cpp
OBJECTS = $(SOURCES:.cpp=.o)

INCLUDES = MutantStack.hpp

FLAGS = -Wall -Wextra -Werror -std=c++11 -g -fsanitize=address

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
