# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/27 17:10:37 by afogonca          #+#    #+#              #
#    Updated: 2024/10/30 12:28:49 by afogonca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -f

SRCS = ft_printf.c ft_printfstr.c ft_printfunbr.c ft_printf_utils.c ft_printfhex.c \
	ft_printpoint.c libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putnbr_fd.c

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
