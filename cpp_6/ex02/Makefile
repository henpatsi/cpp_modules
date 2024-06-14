# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 17:07:00 by hpatsi            #+#    #+#              #
#    Updated: 2024/06/13 19:02:48 by hpatsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = a.out

CLASSES = Base A B C

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
