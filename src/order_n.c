#include"../inc/push_swap.h"
#include<string.h>

int	search_pos(t_list *stack, int range)
{
	t_nodo	*ptr;
	int		i;
	int		first_e;

	ptr = stack->cabeza;
	i = 0;
	while (ptr != NULL && ptr->pos > range && i < stacklen(stack) && ++i)
		ptr = ptr->next;
	first_e = i;
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
	while (ptr != NULL && ptr->pos != range && i < stacklen(stack) && ++i)
		ptr = ptr->next;
	first_e = i;
	last_e = stacklen(stack) - first_e;
	if (first_e > last_e)
		return (-last_e);
	else
		return (first_e);
	return (first_e);
}

void	first_push(t_list *stack, t_list *stack_2, int len, int ind)
{
	int	n;
	int	i;
	int	j;

	while (stack->cabeza)
	{	
		i = 0;
		while (stack->cabeza && i < ind && ++i)
		{
			n = search_pos(stack, len);
			j = 0;
			if (n > 0)
				while (j < n && ++j)
					if (rotate(stack) == 0)
						put_move(stack, "ra\n", 3);
			if (push(stack, stack_2) == 0)
					put_move(stack, "pb\n", 3);
			if (stacklen(stack_2) > 1 && stack_2->cabeza->pos <= len - ind / 2)
				if (rotate(stack_2) == 0)
					put_move(stack, "rb\n", 3);
		}
		len += 20;
	}
}

int	do_rotate(t_list *stack, t_list *stack_2, int tmp, int len, int n)
{
	int	j;

	j = 0;
	if (n < 0)
		while (j > n && --j)
		{
			if (stack_2->cabeza->pos == len - 1 && tmp == 0 && ++tmp)
				if (push(stack_2, stack) == 0)
					put_move(stack, "pa\n", 3);
			if (stack_2->cabeza->pos != len && reverse_rotate(stack_2) == 0)
				put_move(stack, "rrb\n", 4);
		}
	if (n > 0)
		while (j < n && ++j)
		{
			if (stack_2->cabeza->pos == len - 1 && tmp == 0 && ++tmp && ++j)
				if (push(stack_2, stack) == 0)
					put_move(stack, "pa\n", 3);
			if (stack_2->cabeza->pos != len && rotate(stack_2) == 0)
				put_move(stack, "rb\n", 3);
		}
	return (tmp);
}

void	last_push(t_list *stack, t_list *stack_2, int len)
{
	int	n;
	int	tmp;

	while (stack_2->cabeza)
	{
		n = search_pos2(stack_2, len);
		tmp = 0;
		tmp = do_rotate(stack, stack_2, tmp, len, n);
		if (push(stack_2, stack) == 0)
			put_move(stack, "pa\n", 3);
		if (tmp == 1)
			--len;
		if (stacklen(stack) > 1 && stack->cabeza->pos > stack->cabeza->next->pos)
			if (swap(stack) == 0)
				put_move(stack, "sa\n", 3);
		len--;
	}
}

void	order_n(t_list *stack, t_list *stack_2)
{
	int	len;
	int	ind;
	
	len = 20;
//	if (stacklen(stack) >= 400)
//		len = 100;
	ind = len;
	first_push(stack, stack_2, len, ind);
//	print_2stack(stack, stack_2);// BORRAR !!!
	len = stacklen(stack_2);
	last_push(stack, stack_2, len);
}
