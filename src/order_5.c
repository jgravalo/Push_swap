/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:27:20 by jgravalo          #+#    #+#             */
/*   Updated: 2023/04/26 17:44:12 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include"../inc/push_swap.h"

int	search_num(t_list *stack, int num)
{
	int		i;
	t_nodo	*ptr;

	ptr = stack->cabeza;
	i = 0;
	while (ptr && ptr->num != num)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}

void	move(t_list *stack, int fin)
{
	int	i;

	i = 0;
	if (fin >= 0)
	{
		while (i < fin && ++i)
		{
			if (rotate(stack) == 0)
				write(1, "ra\n", 3);
		}
	}
	else
	{
		fin *= -1;
		while (i < fin && ++i)
		{
			if (reverse_rotate(stack) == 0)
				write(1, "rra\n", 4);
		}
	}
}

void	best_rotate(t_list *stack)
{
	int	min;
	int	min2;

	min = search_num(stack, min_num(stack));
	min2 = stacklen(stack) - min;
	if (min2 <= min)
		move(stack, -min2);
	else
		move(stack, min);
}


void	order_5(t_list *stack, t_list *stack_2)
{
	while (stacklen(stack) > 3)
	{
		best_rotate(stack);
		if (push(stack, stack_2) == 0)
			write(1, "pb\n", 3);
	}
	order_3(stack, stack_2);
//	print_2stack(stack, stack_2);// BORRAR !!!
	if (stacklen(stack_2) == 2
		&& stack_2->cabeza->pos < stack_2->cabeza->next->pos)
		if (swap(stack_2) == 0)
			write(1, "sb\n", 3);
	while (stacklen(stack_2) >= 1)
		if (push(stack_2, stack) == 0)
			write(1, "pa\n", 3);
}
