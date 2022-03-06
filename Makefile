# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sscot <sscot@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 22:00:05 by sscot             #+#    #+#              #
#    Updated: 2022/03/06 15:19:53 by sscot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.c \
					check.c \
					radix.c \
					rotateswap.c \
	   				algorithmsmall.c \
					basicswap.c \
					listswap.c \
					functions.c \
					continueswap.c \
					initialize.c 

OBJS			= $(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= push_swap

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)
all:		${NAME}
${NAME}:	${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean:
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean:		clean
				$(RM) $(NAME)

re:			fclean $(NAME)


.PHONY:		all clean fclean re bonus