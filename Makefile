SRCS		= src/push_swap.c src/check_errors.c src/min_to_max.c src/makestack.c src/instructions.c src/utils.c src/search_pos.c src/free_stack.c src/order_3.c src/order_5.c src/order_n.c

BONUS		= bonus/checker.c bonus/check_errors.c bonus/min_to_max.c bonus/makestack.c bonus/free_stack.c bonus/instructions.c bonus/utils.c

GNL			= gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS		= $(SRCS:.c=.o)

BONUS_OBJS	= $(BONUS:.c=.o)

GNL_OBJS	= $(GNL:.c=.o)

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra -fsanitize=address

RM			= rm -rf

NAME		= push_swap

BONUS_NAME	= checker

all:	$(NAME)

$(NAME): $(OBJS) Makefile inc/push_swap.h
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS) $(GNL_OBJS) Makefile inc/checker.h gnl/get_next_line.h
		$(CC) $(CFLAGS) $(BONUS_OBJS) $(GNL_OBJS) -o $(NAME)

$(OBJS): src/%.o : src/%.c Makefile inc/push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

$(GNL_OBJS): gnl/%.o : gnl/%.c Makefile inc/push_swap.h
		$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJS): bonus/%.o : bonus/%.c Makefile inc/checker.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
		$(RM) $(NAME) checker

re:		fclean $(NAME)

.PHONY:	all clean fclean re
