# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npimenof <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/29 09:42:31 by npimenof          #+#    #+#              #
#    Updated: 2019/07/31 23:48:12 by rjaakonm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = srcs/bsq_solver.c srcs/exceptions.c srcs/ft_numbers.c srcs/ft_string2.c srcs/ft_list.c srcs/ft_string.c srcs/main.c

OUTS = bsq_solver.o exceptions.o ft_numbers.o ft_string2.o ft_list.o ft_string.o main.o

INCL = incl/

all: $(NAME)

$(NAME): $(SRCS) $(INCL)
	gcc -Wall -Werror -Wextra -c $(SRCS) -I $(INCL) -O3
	gcc -Wall -Werror -Wextra -o $(NAME) $(OUTS) -O3

clean:
	/bin/rm -f $(OUTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

debug: fclean
	gcc -c $(SRCS) -I $(INCL)
	gcc -o $(NAME) -g $(OUTS)
	lldb $(NAME)

target: dependencies
	action
