# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelarif <abelarif@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/22 09:38:27 by abelarif          #+#    #+#              #
#    Updated: 2021/07/23 07:43:49 by abelarif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=philosophers

PHILOSOPHERS_SRCS=	main.c\
					philosophers.c\

PARSING_SRCS=		./parsing/parsing.c\
					./parsing/args_checker.c\

# EXECUTION_SRCS=		./execution/to_sorting.c\
					# ./execution/to_execution.c\
					# ./execution/small_sorting.c\
					# ./execution/big_sorting.c\

UTILS_SRCS=			./utils/ft_atoi.c\
					./utils/ft_error.c\
					./utils/ft_strlen.c\
					./utils/ft_isdigit.c\
					./utils/free_philos.c\

SRCS=				$(UTILS_SRCS)\
					$(PHILOSOPHERS_SRCS)\
					$(PARSING_SRCS)\
					# $(EXECUTION_SRCS)\

OBJS=			$(SRCS:.c=.o)

FLAGS=			-Wall -Werror -Wextra

$(NAME): $(OBJS)
		clang-9 -g3 $(FLAGS) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

fsanitize: fclean $(OBJS)
		clang-9 $(FLAGS) -g3 -fsanitize=address $(SRCS) -o $(NAME)
