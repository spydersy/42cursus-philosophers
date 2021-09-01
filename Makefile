# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 09:38:27 by abelarif          #+#    #+#              #
#    Updated: 2021/09/01 18:49:55 by abelarif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philo

SRCS=	main.c\
		time.c\
		init.c\
		utils.c\
		philosophers.c\
		print_status.c\
		free_philosophers.c\

OBJS=	$(SRCS:.c=.o)

FLAGS=	-Wall -Werror -Wextra -pthread

$(NAME): $(OBJS)
		gcc -g3 $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

fsanitize: fclean $(OBJS)
		gcc $(FLAGS) -g3 -fsanitize=thread $(SRCS) -o $(NAME)
