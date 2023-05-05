#include"../inc/push_swap.h"

int	search_pos(t_list *stack, int range)
{
	t_nodo	*ptr;
	int		i;
	int		first_e;
	int		last_e;

	ptr = stack->cabeza;
	i = 0;
//	printf("len = %d\n", range);// BORRAR !!!
	while (ptr != NULL && ptr->pos > range && i < stacklen(stack) && ++i)
	{
//		printf("pos = %d\n", ptr->pos);// BORRAR !!!
		ptr = ptr->next;
	}
	first_e = i;
	last_e = stacklen(stack) - first_e;
//	printf("first = %d\n", first_e);// BORRAR !!!
//	printf("last = %d\n", last_e);// BORRAR !!!
	while (ptr != NULL && i < stacklen(stack) && ++i)
	{
//		printf("pos = %d\n", ptr->pos);// BORRAR !!!
		if (ptr->pos <= range)
		{
			last_e = stacklen(stack) - i + 1;
//			printf("last[%d] = %d\n", ptr->pos , last_e);// BORRAR !!!
		}
		ptr = ptr->next;
	}
//		printf("esta aqui\n");
	if (first_e > last_e)
		return (-last_e);
	else
		return (first_e);
	return (first_e);
}

int	search_pos2(t_list *stack, int range)
{
	t_nodo	*ptr;
	int		i;
	int		first_e;
	int		last_e;

	ptr = stack->cabeza;
	i = 0;
//	printf("len = %d\n", range);// BORRAR !!!
	while (ptr != NULL && ptr->pos != range && i < stacklen(stack) && ++i)
	{
//		printf("pos = %d\n", ptr->pos);// BORRAR !!!
		ptr = ptr->next;
	}
	first_e = i;
	last_e = stacklen(stack) - first_e;
//	printf("first = %d\n", first_e);// BORRAR !!!
//	printf("last = %d\n", last_e);// BORRAR !!!
	if (first_e > last_e)
		return (-last_e);
	else
		return (first_e);
	return (first_e);
}

void	first_push(t_list *stack, t_list *stack_2, int len)
{
	int	n;
	int	i;
	int	j;

	while (stack->cabeza)
	{	
		i = 0;
		while (stack->cabeza && i < 20 && ++i)
		{
			n = search_pos(stack, len);
//			printf("n = %d\n", n);// BORRAR !!!
			j = 0;
			if (n < 0)
				while (j > n && --j)
					if (reverse_rotate(stack) == 0)
						write(1, "rra\n", 4);
//						put_move(stack, "rra\n", 4);
//						printf("j = %d\n", j);// BORRAR !!!
			if (n > 0)
				while (j < n && ++j)
					if (rotate(stack) == 0)
						write(1, "ra\n", 3);
//						put_move(stack, "ra\n", 3);
			if (push(stack, stack_2) == 0)
//			{
				write(1, "pb\n", 3);
//				put_move(stack, "pb\n", 3);
//				printf("esta aqui\n");
//			}
			if (stacklen(stack_2) > 1 && i % 2 != 0)
				if (rotate(stack_2) == 0)
					write(1, "sb\n", 3);
//					put_move(stack, "sb\n", 3);
//			print_2stack(stack, stack_2);// BORRAR !!!
		}
		len += 20;
	}
}
/*
void	condition(t_list *stack, t_list *stack_2, int len)
{
	if (stack_2->cabeza->pos == len - 1)
	{
		if (push(stack_2, stack) == 0)
			write(1, "pa\n", 3);
//			put_move(stack, "pa\n", 3);
		if (swap(stack) == 0)
			write(1, "sa\n", 3);
//			put_move(stack, "sa\n", 3);
	}
}
*/
void	last_push(t_list *stack, t_list *stack_2, int len)
{
	
	int	n;
	int	j;

	while (stack_2->cabeza)
	{
		n = search_pos2(stack_2, len);
//		printf("n = %d\n", n);// BORRAR !!!
		j = 0;
		if (n < 0)
			while (j - 1 >= n && --j)
			{
				if (reverse_rotate(stack_2) == 0)
					write(1, "rrb\n", 4);
//					put_move(stack, "rrb\n", 4);
//				condition(stack, stack_2, len);
			}
		if (n > 0)
			while (j + 1 <= n && ++j)
			{
				if (rotate(stack_2) == 0)
					write(1, "rb\n", 3);
//					put_move(stack, "rb\n", 3);
//				condition(stack, stack_2, len);
			}
		if (push(stack_2, stack) == 0)
			write(1, "pa\n", 3);
//			put_move(stack, "pa\n", 3);
//		print_2stack(stack, stack_2);// BORRAR !!!
		len--;
	}
}

void	order_n(t_list *stack, t_list *stack_2)
{
	int len;
	
//	print_2stack(stack, stack_2);// BORRAR !!!
	len = 20;
	first_push(stack, stack_2, len);
//	print_2stack(stack, stack_2);// BORRAR !!!
	len = stacklen(stack_2);
	last_push(stack, stack_2, len);
}
