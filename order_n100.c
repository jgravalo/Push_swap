#include"push_swap.h"

int		n_groups(int n)
{
	while (n % 20 != 0)
	{
		n--;
	}
	return (n);
}

void loop_rotate(t_list *stack, int count, int sign, int dest)
{
	if (sign == 1)
		while (count > 0)
		{
			rotate(stack);
			if (dest == 1)
				write(1, "ra\n", 3);
			else if (dest == 2)
				write(1, "rb\n", 3);
			count--;
		}
	else if (sign == -1)
		while (count > 0)
		{
			reverse_rotate(stack);
			if (dest == 1)
				write(1, "rra\n", 4);
			else if (dest == 2)
				write(1, "rrb\n", 4);
			count--;
		}
}

void best_rotate_to_b(t_list *stack, int index)
{
	int		i;
	int		j;
	int		first;
	int		last;
	t_nodo	*ptr;
		
	i = 1;
	ptr = stack->cabeza;
	while (ptr && ptr->pos > index - 20 && ptr->pos < index)
	{
		first = i;
		ptr = ptr->next;
		i++;
	}
	j = i;
	while (ptr)
	{
		if (ptr->pos > index - 20 && ptr->pos < index)
			last = stacklen(stack) - j;
		ptr = ptr->next;
		j++;
	}
	if (last > first)
		loop_rotate(stack, first - 1, -1, 1);
	else
		loop_rotate(stack, last, 1, 1);
}

void best_push(t_list *stack, t_list *stack_2, int j, int sign)
{
	while (j > 0)
	{
		if (stack_2->cabeza->pos > stacklen(stack) - 1)
		{
			push(stack_2, stack);
			write(1, "pa\n", 3);
		}
		if (sign == 1)
			rotate(stack);
		else
			reverse_rotate(stack);
		write(1, "rb\n", 3);
		j--;
	}
}

void best_rotate_to_a(t_list *stack, t_list *stack_2)
{
	int		i;
	int		j;
	t_nodo	*ptr;

	while (stacklen(stack_2) > 0)
	{
		i = 0;
		ptr = stack_2->cabeza;
		while (ptr && ptr->pos != stacklen(stack))
		{
			ptr = ptr->next;
			i++;
		}
		j = stacklen(stack_2) - i;
		if (j < i + 1)
			best_push(stack, stack_2, j, 1);
/*
			while (j > 0)
			{
				if (stack_2->cabeza->pos > stacklen(stack) - 1)
				{
					push(stack_2, stack);
					write(1, "pa\n", 3);
				}
				rotate(stack);
				write(1, "rb\n", 3);
				j--;
			}
*/
		else
			best_push(stack, stack_2, j, 0);
/*
			while (i + 1 > 0)
			{
				if (stack_2->cabeza->pos > stacklen(stack) - 1)
				{
					push(stack_2, stack);
					write(1, "pa\n", 3);
				}
				reverse_rotate(stack_2);
				write(1, "rb\n", 3);
				i--;
			}
*/
		push(stack_2, stack);
		write(1, "pa\n", 3);
		if (stack->cabeza->pos > stack->cabeza->next->pos)
		{
			swap(stack);
			write(1, "sa\n", 3);
		}
	}
}

void    order_n(t_list *stack, t_list *stack_2)
{
	int		i;
	int		index;
	t_nodo	*ptr;
		
	ptr = stack->cabeza;
//	index = n_groups(stacklen(stack));
	i = 0;
	index = 20;
	while (stacklen(stack) > 0)
	{
		while (stacklen(stack) > 0 && i < index)
		{
			best_rotate_to_b(stack, index);
			push(stack, stack_2);
			write(1, "pb\n", 3);
			if (ptr->pos < index - 20 / 2)
			{
				reverse_rotate(stack_2);
				write(1, "rb\n", 3);
			}
			i++;
		}
		index += 20;	
	}
//	best_rotate_to_a(stack, stack_2);
}

/*
int main()
{
	printf("%d\n", n_groups(129));
	return (0);
}*/
