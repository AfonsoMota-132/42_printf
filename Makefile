# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 17:10:37 by afogonca          #+#    #+#              #
#    Updated: 2024/10/27 17:14:47 by afogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -f

SRCS = ft_printf.c ft_printf_utils.c

OBJS = ${SRCS:.c=.o}
NAME = libftprintf.a

# Rules

all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
