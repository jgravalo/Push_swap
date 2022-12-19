#include"push_swap.h"

// BUSCA LA MEJOR ROTACION EN A
int	find_rotate_to_b(t_list *stack, int index)
{
	int i;
	int first;
	int last;
	t_nodo	*ptr;

	i = 0;
	ptr = stack->cabeza;
	while (ptr->pos <= index || ptr->pos > index + 10)
	{
		ptr = ptr->next;
		i++;
	}
	first = i - 1;
	while (ptr)
	{	
		if (ptr->pos > index && ptr->pos <= index + 10)
		{
			last = stacklen(stack) - i + 1;
		}
		ptr = ptr->next;
		i++;
	}
	if (last < first)
		return (-last);
	return (first);
}

// HACE LA ROTACION EN A
void	best_rotate_to_b(t_list *stack, int index)
{
	int	count;

	count = find_rotate_to_b(stack, index);
	if (count < 0)
	{
		while (count < 0)
		{
			reverse_rotate(stack);
			write(1, "ra\n", 3);
			count++;
		}
		return ;
	}
	else
	{
		while (count < 0)
		{
			rotate(stack);
			write(1, "ra\n", 3);
		}
		return ;
	}
}

// HACE LA ROTACION EN B
void	best_rotate_to_a(t_list *stack)
{
	int	count;

	count = find_rotate_to_a(stack);
	if (count < 0)
	{
		while (count < 0)
		{
			reverse_rotate(stack);
			write(1, "ra\n", 3);
			count++;
		}
		return ;
	}
	else
	{
		while (count < 0)
		{
			rotate(stack);
			write(1, "ra\n", 3);
		}
		return ;
	}
}

// ORDER_N
void	order_n(t_list *stack, t_list *stack_2)
{
	int index;
	int i;

	index = 0;
	i = 1;
	while (stacklen(stack) > 0)
	{
		best_rotate_to_a(stack, index);
		push(stack, stack_2);
		write(1, "pb\n", 3);
		if (stack_2->cabeza->pos > index + 5)
		{
			rotate(stack_2);
			write(1, "rb\n", 3);
		}
		i++;
		if (i == index)
			index += 10;
	}
	/*
	while (stacklen(stack_2) > 0)
	{
//		best_rotate_to_b(stack_2);
		push(stack_2, stack);
		write(1, "pa\n", 3);
	}
	*/
}
