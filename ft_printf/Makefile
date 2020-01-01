# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eelaazmi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/29 20:32:58 by eelaazmi          #+#    #+#              #
#    Updated: 2019/12/29 20:33:03 by eelaazmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

SRCS = *.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRCS)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	echo $(NAME) was Created

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
bonus:
	echo"null"
re: fclean all
