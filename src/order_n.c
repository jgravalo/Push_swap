#include"../inc/push_swap.h"
#include<string.h>

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
						{put_move(stack, "rra\n", 4); printf("rra\n");}
//						printf("j = %d\n", j);// BORRAR !!!
			if (n > 0)
				while (j < n && ++j)
					if (rotate(stack) == 0)
						{put_move(stack, "ra\n", 3); printf("ra\n");}
			if (push(stack, stack_2) == 0)
					{put_move(stack, "pb\n", 3); printf("pb\n");}
//			if (stacklen(stack_2) > 1 && i % 2 != 0)
			if (stacklen(stack_2) > 1 && stack_2->cabeza->pos < len - 10)
				if (rotate(stack_2) == 0)
					{put_move(stack, "rb\n", 3); printf("rb\n");}
//			print_2stack(stack, stack_2);// BORRAR !!!
		}
		len += 20;
//		printf("len = %d\n", len);
	}
}

int		condition(t_list *stack, t_list *stack_2, int len, int n)
{
	int	i;

	i = 0;
	if (stack_2->cabeza->pos == len - 1)
	{
		if (push(stack_2, stack) == 0)
						{put_move(stack, "pa\n", 3); printf("pa\n");}
//		if (swap(stack) == 0)
//				{put_move(stack, "sa\n", 3); printf("sa\n");}
		i++;
	}
	if (n < 0)
		if (reverse_rotate(stack_2) == 0)
				{put_move(stack, "rrb\n", 4); printf("rrb\n");}
	if (n > 0)
		if (rotate(stack_2) == 0)
					{put_move(stack, "rb\n", 3); printf("rb\n");}
	return (i);
}

void	last_push(t_list *stack, t_list *stack_2, int len)
{
	int	n;
	int	j;
	int	tmp;

	while (stack_2->cabeza)
	{
		n = search_pos2(stack_2, len);
//		printf("n = %d\n", n);
		j = 0;
		tmp = 0;
		if (n < 0)
			while (j > n && --j)
			{
				//
				if (stack_2->cabeza->pos == len - 1 && tmp == 0 && ++tmp)// && --j)
					if (push(stack_2, stack) == 0)
						{put_move(stack, "pa\n", 3); printf("(%d-%d)pa\n", stack->cabeza->pos, len - 1);}
				//
				if (stack_2->cabeza->pos != len && reverse_rotate(stack_2) == 0)
					{put_move(stack, "rrb\n", 4); printf("rrb\n");}
//					len -= condition(stack, stack_2, len, -1);
			}
		if (n > 0)
			while (j < n && ++j)
			{
				//
				if (stack_2->cabeza->pos == len - 1 && tmp == 0 && ++tmp && ++j)
					if (push(stack_2, stack) == 0)
					{put_move(stack, "pa\n", 3); printf("(%d-%d)pa\n", stack->cabeza->pos, len - 1);}
				//
				if (stack_2->cabeza->pos != len && rotate(stack_2) == 0)
					{put_move(stack, "rb\n", 3); printf("rb\n");}
//					len -= condition(stack, stack_2, len, 1);
			}
		if (push(stack_2, stack) == 0)
			{put_move(stack, "pa\n", 3); printf("(%d-%d)pa\n", stack->cabeza->pos, len);}
		//
		if (tmp == 1)
			--len;
		if (stacklen(stack) > 1 && stack->cabeza->pos > stack->cabeza->next->pos)
			if (swap(stack) == 0)
				{put_move(stack, "sa\n", 3); printf("sa\n");}
		//
//		print_2stack(stack, stack_2);// BORRAR !!!
//		printf("len = %d\n", len);
		len--;
	}
}

void	order_n(t_list *stack, t_list *stack_2)
{
	int len;
	
	print_2stack(stack, stack_2);// BORRAR !!!
	len = 20;
	if (stacklen(stack) >= 500)
		len = 60;
	first_push(stack, stack_2, len);
	//
	print_2stack(stack, stack_2);// BORRAR !!!
	len = stacklen(stack_2);
	last_push(stack, stack_2, len);
	//
}
