# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlecuyer <mlecuyer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/28 14:25:27 by mlecuyer          #+#    #+#              #
#    Updated: 2021/07/01 13:14:20 by mlecuyer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS 	= -Wall -Wextra -Werror
NAME_1	=	server
NAME_O_SERVER = server.o 
NAME_SERVER	= server.c

NAME_2	=	client
NAME_O_CLIENT = client.o
NAME_CLIENT	=	client.c

LIBDIR 	=	./libft/
LIBFT	=	libft.a

RM		= rm -f

all:		${NAME_1} ${NAME_2}

${NAME_1}:		${NAME_O_SERVER}
				make all -C $(LIBDIR)
				${CC} ${CFLAGS} -o ${NAME_1} ${NAME_O_SERVER}  ${OBJS} $(LIBDIR)/$(LIBFT)

${NAME_2}:		${NAME_O_CLIENT}
				make all -C $(LIBDIR)
				${CC} ${CFLAGS} -o ${NAME_2} ${NAME_O_CLIENT} ${OBJS} $(LIBDIR)/$(LIBFT)
clean:		
			${RM} ${NAME_O_SERVER} ${NAME_O_CLIENT}
			make clean -C $(LIBDIR)

fclean:		clean
			${RM} ${NAME_1} ${NAME_2} ${NAME_O_SERVER} ${NAME_O_CLIENT}
			make fclean -C $(LIBDIR)

re:			fclean all

.PHONY:		all clean fclean re