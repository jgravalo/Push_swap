# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 16:53:48 by jgravalo          #+#    #+#              #
#    Updated: 2022/10/19 17:53:54 by jgravalo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS            = main.c push_swap.c check_errors.c makestack.c \
				  min_to_max.c instructions.c order_3.c order_5.c order_n.c \
OBJS            = $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_FILES:.c=.o)
CC              = gcc
RM              = rm -f
CFLAGS          = -Wall -Wextra -Werror
NAME			= push_swap.a
all:            $(NAME)
$(NAME):        $(OBJS)
				ar rcs $(NAME) $(OBJS)
				ranlib ${NAME}
bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
				ranlib ${NAME}
clean:			
				$(RM) $(OBJS) $(BONUS_OBJS)
fclean:			clean
				$(RM) $(NAME)
re:             fclean $(NAME)
.PHONY:			all bonus clean fclean re
