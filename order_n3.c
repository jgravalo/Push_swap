#include"push_swap.h"

void    order_n(t_list *stack, t_list *stack_2)
{
	int i = 1;
	t_nodo *ptr = stack->cabeza;

	while (stacklen(stack) > 0)
	{
		best_rotate(stack);
		write(1, "ra\n", 3);
		if (ptr->pos)
		{
			push(stack, stack_2);
			write(1, "pb\n", 3);
			i++;
		}
	}
	while (stacklen(stack) > 0)
	{
		push(stack, stack_2);
		write(1, "pb\n", 3);
	}
}
/*
int main(int argc, char **argv)
{
	return (0);
}*/
