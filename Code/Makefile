# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 15:44:12 by jariza-o          #+#    #+#              #
#    Updated: 2023/09/04 20:12:52 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags
# ‐fsanitize=thread -g #-g: debuguear no entregar al final
CFLAGS =	-Wall -Werror -Wextra

# Philosophers
NAME =		philo
SRC =		src/main.c \
			src/errors/errors.c \
			src/philo/init.c src/philo/single_routine.c \
			src/utils/utils.c src/utils/time.c src/utils/prints.c src/utils/help.c \

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