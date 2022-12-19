#include"push_swap.h"
#define N 10

int		best_rotate_to_b(t_list *stack, int index)
{
	int	i;
	int	first;
	int	last;
	t_nodo *ptr;

	i = 0;
	ptr = stack->cabeza;
	while (stack->cabeza->pos <= index - N || stack->cabeza->pos > index)
	{
		ptr = ptr->next;
		i++;
	}
	first = i - 1;
	while (ptr)
	{
		if (stack->cabeza->pos <= index - N || stack->cabeza->pos > index)
			last = i;
		ptr = ptr->next;
		i++;
	}
	last = stacklen(stack) - last;
	printf("first = %d", first);// BORRAR !!!
	printf("last = %d", last);// BORRAR !!!
	if (first > last)
		return (-1);
	return (1);
}

int		best_rotate_to_a(t_list *stack)
{
	int	i;
	int	j;
	t_nodo *ptr;

	i = 0;
	ptr = stack->cabeza;
	while (ptr && ptr->pos != stacklen(stack))
	{
		ptr = ptr->next;
		i++;
	}
	i--;
	j = stacklen(stack) - i;
	if (i > j)
		return (-1);
	return (1);
}

void	order_n(t_list *stack, t_list *stack_2)
{
	t_nodo *ptr;
	int index;
	int i;
	int len;

	if (!stack_2)
		printf("error");
	ptr = stack->cabeza;
	index = N;
	i = 0;
	printf("index = %d\n", index);
	
	while (stacklen(stack) > 0)
	{
		/*
		printf("pos = %d ", stack->cabeza->pos);
		printf("index - 20 = %d ", index - 20);
		printf("index = %d ", index);
		printf("i = %d\n", i);
		*/
		while (stack->cabeza->pos <= index - N || stack->cabeza->pos > index)
		{
			if (best_rotate_to_b(stack, index) == 1)
				rotate(stack);
			else// if (best_rotate_to_a(stack_2, index) == -1)
			{
				reverse_rotate(stack_2);
				write(1, "r", 1);
			}
			write(1, "ra\n", 3);
		}
		push(stack, stack_2);
		write(1, "pb\n", 3);
		i++;
		if (stack_2->cabeza->pos > index - N / 2 && stack_2->cabeza->pos <= index)
		{
			rotate(stack_2);
			write(1, "rb\n", 3);
		}
		if (i == index)
			index += N;
	}
	while (stacklen(stack_2) > 0)
	{
		len = stacklen(stack_2);
		while (stack_2->cabeza->pos != len)
		{
			if (stack_2->cabeza->pos == len - 1)
			{
				push(stack_2, stack);
				write(1, "pa\n", 3);
			}
			if (best_rotate_to_a(stack_2) == 1)
				rotate(stack_2);
			else// if (best_rotate_to_a(stack_2) == -1)
			{
				reverse_rotate(stack_2);
				write(1, "r", 1);
			}
			write(1, "rb\n", 3);
		}
		push(stack_2, stack);
		write(1, "pa\n", 3);
		if (stack->cabeza->pos > stack->cabeza->next->pos)
		{
			swap(stack);
			write(1, "sa\n", 3);
		}
	}
}
