#include"../inc/push_swap.h"

#define N 10

void order_n(t_list *stack, t_list *stack_2)
{
	first_push(stack, stack_2);
	print_2stack(stack, stack_2);
	last_push(stack, stack_2);
}

void	first_push(t_list *stack, t_list *stack_2)
{
	t_nodo *ptr;
	int len;
	int first;
	int last;
	int i;
	int j;
	int index = 0;
	int ind = 0;
	
	while (stacklen(stack) > 0)
	{
		ptr = stack->cabeza;
		len = stacklen(stack);
		first = 0;
		last = 0;
		i = 0;

		while (!(ptr->pos > index && ptr->pos <= index + N))
//		while (!(ptr->pos > index && (ptr->pos <= index + 10 || ptr->pos <= len)))
		{
			ptr = ptr->next;
			i++;
		}
		first = i;
		while (ptr)
		{
			if (ptr->pos > index && ptr->pos <= index + N)
				last = i;
			ptr = ptr->next;
			i++;
		}
		j = 0;
		if (first > len - last)
			while (j < len - last)
			{
				reverse_rotate(stack);
				write(1, "rra\n", 4);
				j++;
			}
		else
			while (j < first)
			{
				rotate(stack);
				write(1, "ra\n", 3);
				j++;
			}
		push(stack, stack_2);
		write(1, "pb\n", 3);
//*		
		if (stack_2->cabeza->pos > index + (N / 2) && stack->cabeza->pos <= index + N)
		{
			rotate(stack_2);
			write(1, "rb\n", 3);
		}
//
		ind++;
		if (ind % N == 0)
			index += N;
	}
//
}
void	last_push(t_list *stack, t_list *stack_2)
{
//	/*
	while (stacklen(stack_2) > 0)
	{
		int count;
		int sign;
		int len;
		int i;
		int j;
		t_nodo *ptr;

		ptr = stack_2->cabeza;
		len = stacklen(stack_2);
//		printf("len = %d\n", len);
		i = 0;
		j = 0;
		while (ptr->pos != len)
		{
			ptr = ptr->next;
			i++;
		}

		if (i > len - i)
		{
			sign = 0;
			count = len - i;
		}
		else
		{
			sign = 1;
			count = i;
		}
		while (j < count)
		{
/*			if (stack->cabeza->pos == len - 1)
			{
				push(stack_2, stack);
				write(1, "pa\n", 3);
//				j++;
			}
*/
			if (sign == 0)
			{
				reverse_rotate(stack_2);
				write(1, "r", 1);
			}
			else 
				rotate(stack_2);
			write(1, "rb\n", 3);
			j++;
		}
		push(stack_2, stack);
		write(1, "pa\n", 3);
	}
//	*
}
