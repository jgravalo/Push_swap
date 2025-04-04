/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:02:57 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/24 16:08:33 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <string.h>

void	first_push(t_list *stack, t_list *stack_2, int len, int ind)
{
	int	n;
	int	i;
	int	j;

	while (stack->head)
	{
		i = 0;
		while (stack->head && i < ind && ++i)
		{
			n = search_pos(stack, len);
			j = 0;
			if (n > 0)
				while (j < n && ++j)
					if (rotate(stack) == 0)
						write(1, "ra\n", 3);
			if (push(stack, stack_2) == 0)
				write(1, "pb\n", 3);
			if (stacklen(stack_2) > 1 && stack_2->head->pos <= len - ind / 2)
				if (rotate(stack_2) == 0)
					write(1, "rb\n", 3);
		}
		len += ind;
	}
}

int	do_reverse(t_list *stack, t_list *stack_2, int len, int n)
{
	int	j;
	int	tmp;

	tmp = 0;
	j = 0;
	if (n < 0)
	{
		while (j > n && --j)
		{
			if (stack_2->head->pos == len - 1 && tmp == 0 && ++tmp)
				if (push(stack_2, stack) == 0)
					write(1, "pa\n", 3);
			if (stack_2->head->pos != len && reverse_rotate(stack_2) == 0)
				write(1, "rrb\n", 4);
		}
	}
	return (tmp);
}

int	do_rotate(t_list *stack, t_list *stack_2, int len, int n)
{
	int	j;
	int	tmp;

	tmp = 0;
	j = 0;
	if (n > 0)
	{
		while (j < n && ++j)
		{
			if (stack_2->head->pos == len - 1 && tmp == 0 && ++tmp && ++j)
				if (push(stack_2, stack) == 0)
					write(1, "pa\n", 3);
			if (stack_2->head->pos != len && rotate(stack_2) == 0)
				write(1, "rb\n", 3);
		}
	}
	return (tmp);
}

void	last_push(t_list *stack, t_list *stack_2, int len)
{
	int	n;
	int	tmp;

	while (stack_2->head)
	{
		tmp = 0;
		n = search_pos2(stack_2, len);
		if (n < 0)
			tmp = do_reverse(stack, stack_2, len, n);
		if (n > 0)
			tmp = do_rotate(stack, stack_2, len, n);
		if (push(stack_2, stack) == 0)
			write(1, "pa\n", 3);
		if (tmp == 1)
			--len;
		if (stacklen(stack) > 1
			&& stack->head->pos > stack->head->next->pos)
			if (swap(stack) == 0)
				write(1, "sa\n", 3);
		len--;
	}
}

void	order_n(t_list *stack, t_list *stack_2)
{
	int	len;
	int	ind;

	len = 50;
	if (stacklen(stack) < 200)
		len = 20;
	ind = len;
	first_push(stack, stack_2, len, ind);
	len = stacklen(stack_2);
	last_push(stack, stack_2, len);
}
