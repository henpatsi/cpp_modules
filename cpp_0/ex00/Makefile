# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 19:32:04 by hpatsi            #+#    #+#              #
#    Updated: 2024/03/18 19:48:07 by hpatsi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SOURCES = megaphone.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

COMP = g++

all: $(NAME)

$(NAME):
	$(COMP) $(FLAGS) $(SOURCES) -o $(NAME)

clean:
	rm -f megaphone

re: clean all

test: re
	./$(NAME) "shhhhh... I think the students are asleep..."
	./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
	./$(NAME)