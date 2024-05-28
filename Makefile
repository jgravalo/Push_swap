SRCS		= src/push_swap.c src/check_errors.c src/min_to_max.c src/makestack.c src/instructions.c src/utils.c src/search_pos.c src/free_stack.c src/order_3.c src/order_5.c src/order_n.c

MAIN		= src/main.c

BONUS		= src/checker.c src/check_errors.c src/min_to_max.c src/makestack.c src/instructions.c src/utils.c

GNL			= gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

MAIN_OBJS	= $(MAIN:.c=.o)

BONUS_OBJS	= $(BONUS:.c=.o)

GNL_OBJS	= $(GNL:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra 

RM			= rm -rf

NAME		= push_swap

BONUS_NAME	= checker

all:	$(NAME) 
	
$(NAME) : $(OBJS) $(MAIN_OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJS) -o $(NAME)

bonus:		$(BONUS_OBJS) $(GNL_OBJS)
		$(CC) $(CFLAGS) $(BONUS_OBJS) $(GNL_OBJS) -o checker

clean:
		$(RM) $(OBJS) $(MAIN_OBJS) $(BONUS_OBJS) $(GNL_OBJS)

fclean:	clean
		$(RM) $(NAME) checker

re:		fclean $(NAME)

.PHONY:	all clean fclean re
