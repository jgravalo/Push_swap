#include"push_swap.h"

void order_n(t_list *stack, t_list *stack_2)
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

		while (!(ptr->pos > index && ptr->pos <= index + 10))
//		while (ptr->pos != len)
		{
			ptr = ptr->next;
			i++;
		}
		first = i;
		while (ptr)
		{
			if (ptr->pos > index && ptr->pos <= index + 10)
//			if (ptr->pos == len)
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
//		if ()
		ind++;
		if (ind % 10 == 0)
			index += 10;
	}
//
//	
	/*
	while (stacklen(stack_2) > 0)
	{
		t_nodo *ptr = stack_2->cabeza;
		int len = stacklen(stack_2);
		printf("len = %d\n", len);
		int i = 0;
		while (ptr->pos != len)
		{
			ptr = ptr->next;
			i++;
		}
		int j = 0;
		if (i > len - i)
			while (j < len - i)
			{
//				*
				if (stack->cabeza->pos == len - 1)
				{
					push(stack_2, stack);
					write(1, "pa\n", 3);
				}
//				*
				reverse_rotate(stack_2);
				write(1, "rrb\n", 4);
				j++;
			}
		else
			while (j < i)
			{
//				*
				if (stack->cabeza->pos == len - 1)
				{
					push(stack_2, stack);
					write(1, "pa\n", 3);
				}
//				*
				rotate(stack_2);
				write(1, "rb\n", 3);
				j++;
			}
		push(stack_2, stack);
		write(1, "pa\n", 3);
	}

	*/
}
