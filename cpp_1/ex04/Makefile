# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 19:32:04 by hpatsi            #+#    #+#              #
#    Updated: 2024/04/04 09:48:00 by hpatsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mysed

SOURCES = main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

FLAGS = -Wall -Wextra -Werror

COMP = g++

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