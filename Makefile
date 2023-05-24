SRCS		= src/push_swap.c src/check_errors.c src/min_to_max.c src/makestack.c src/instructions.c src/utils.c src/search_pos.c src/free_stack.c src/order_3.c src/order_5.c src/order_n.c

MAIN		= src/main.c

OBJS		= $(SRCS:.c=.o)

MAIN_OBJS	= $(MAIN:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra 

RM			= rm -rf

NAME		= push_swap

BONUS_NAME	= checker

all:	$(NAME) 
	
$(NAME) : $(OBJS) $(MAIN_OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJS) -o $(NAME)

clean:
		$(RM) $(OBJS) $(MAIN_OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:	all clean fclean re
