SRCS		= src/push_swap.c src/check_errors.c src/print_stack.c src/min_to_max.c src/makestack.c src/instructions.c src/utils.c src/search_pos.c src/free_stack.c src/order*

MAIN		= src/main.c

BONUS_SRCS	= bonus/checker.c #gnl/*c

OBJS		= $(SRCS:.c=.o)

GNL_OBJS	= $(GNL:.c=.o)

MAIN_OBJS	= $(MAIN:.c=.o)

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -MMD 

#LIB			= -Ignl

RM			= rm -rf

NAME		= push_swap

BONUS_NAME	= checker

all:	$(NAME) $(BONUS_NAME)
	
bonus:	$(BONUS_NAME)

$(NAME) : $(OBJS) $(MAIN_OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(MAIN_OBJS) -o $(NAME)

$(BONUS_NAME) : $(OBJS) $(BONUS_OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
		$(RM) $(OBJS) $(BONUS_OBJS) $(MAIN_OBJS)

fclean:	clean
		$(RM) $(NAME) $(BONUS_NAME)

re:		fclean $(NAME) $(BONUS_NAME)

.PHONY:	all bonus clean fclean re
