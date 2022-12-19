#include"push_swap.h"
#include"checker.h"
#include<string.h>

void conditions1(t_list *stack, t_list *stack_2, char *c)
{
	if (strcmp(c, "pa\n") == 0)
		push(stack_2, stack);
	else if (strcmp(c, "pb\n") == 0)
		push(stack, stack_2);
	else if (strcmp(c, "sa\n") == 0)
		swap(stack);
	else if (strcmp(c, "sb\n") == 0)
		swap(stack_2);
	if (strcmp(c, "ss\n") == 0)
	{
		swap(stack);
		swap(stack_2);
	}
}

void conditions2(t_list *stack, t_list *stack_2, char *c)
{
	if (strcmp(c, "ra\n") == 0)
		rotate(stack);
	if (strcmp(c, "rb\n") == 0)
		rotate(stack_2);
	if (strcmp(c, "rr\n") == 0)
	{
		rotate(stack);
		rotate(stack_2);
	}
	if (strcmp(c, "rra\n") == 0)
		reverse_rotate(stack);
	if (strcmp(c, "rrb\n") == 0)
		reverse_rotate(stack_2);
	if (strcmp(c, "rrr\n") == 0)
	{
		reverse_rotate(stack);
		reverse_rotate(stack_2);
	}
}

int	check(t_list *stack)
{
	t_nodo	*ptr;
	int		i;

	ptr = stack->cabeza;
	i = 1;
	while (ptr)
	{
		if (ptr->pos != i)
			return (0);
		ptr = ptr->next;
		i++;
	}
	return (1);
}

void checker(int argc, char **argv)
{
	t_list *stack;
	t_list *stack_2;
	char *c;

	push_swap(argc, argv);
	stack = malloc(sizeof(t_list));
	stack_2 = malloc(sizeof(t_list));
	makestack(stack, argc, argv);
	c = malloc(sizeof(char) * 5);
	c = get_next_line(1);
	while (c)
	{
		printf("%s", c);
		conditions1(stack, stack_2, c);
		conditions2(stack, stack_2, c);
		c = get_next_line(1);
	}
	check(stack);
}

/*
int main(int argc, char **argv)
{
	push_swap(argc, argv);
	checker(argc, argv);
	return (0)
}
*/
