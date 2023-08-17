# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 15:44:12 by jariza-o          #+#    #+#              #
#    Updated: 2023/08/17 15:56:54 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags
CFLAGS =	-Wall -Werror -Wextra -g

# Philosophers
NAME =		philo
SRC =		src/main.c \

OBJT =		$(SRC:.c=.o)

.c.o:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all:		$(NAME)

$(NAME): ${OBJT}
			@gcc ${CFLAGS} ${OBJT} -o ${NAME}

clean:
			@rm -f ${OBJT}

fclean: 	clean
			@rm -f ${NAME}

re: 		fclean all

.PHONY: all clean fclean re