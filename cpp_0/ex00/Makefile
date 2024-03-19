# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hpatsi <hpatsi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 19:32:04 by hpatsi            #+#    #+#              #
#    Updated: 2024/03/19 14:55:18 by hpatsi           ###   ########.fr        #
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

fclean:
	rm -f megaphone

re: fclean all