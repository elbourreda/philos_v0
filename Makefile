# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-bour <rel-bour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 20:13:43 by rel-bour          #+#    #+#              #
#    Updated: 2021/07/17 19:29:20 by rel-bour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philosopher

CC = gcc  -fsanitize=address

CFLAGS = -Wall -Wextra -Werror   

SRC = srcs/philosophers.c srcs/state_of_philo.c srcs/utils_philo.c
	
all : $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) -o $(NAME)
clean:
	@rm -rf *.o

fclean: clean
	@rm -rf $(NAME)
re:	fclean all