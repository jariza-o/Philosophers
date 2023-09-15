# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jariza-o <jariza-o@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/17 15:44:12 by jariza-o          #+#    #+#              #
#    Updated: 2023/09/15 11:22:24 by jariza-o         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Flags
# ‐fsanitize=thread -g #-g: debuguear no entregar al final
CFLAGS =	-Wall -Werror -Wextra -pthread -fsanitize=thread -g

# Philosophers
NAME =		philo
SRC =		src/main.c \
			src/errors/errors.c \
			src/philoc/init.c src/philoc/single_routine.c src/philoc/rutine.c src/philoc/threads.c \
			src/utils/utils.c src/utils/time.c src/utils/prints.c src/utils/help.c src/utils/free.c \

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