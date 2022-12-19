/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:27:20 by jgravalo          #+#    #+#             */
/*   Updated: 2022/11/28 20:58:46 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include"push_swap.h"

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
		while (i < fin)
		{
			rotate(stack);
			write(1, "ra\n", 3);
			i++;
		}
	}
	else
	{
		fin *= -1;
		while (i < fin)
		{
			reverse_rotate(stack);
			write(1, "rra\n", 4);
			i++;
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
		push(stack, stack_2);
		write(1, "pb\n", 3);
	}
	order_3(stack, stack_2);
	if (stacklen(stack_2) == 2
		&& stack_2->cabeza->pos < stack_2->cabeza->next->pos)
	{
		swap(stack_2);
		write(1, "sb\n", 3);
	}
	while (stacklen(stack_2) >= 1)
	{
		push(stack_2, stack);
		write(1, "pa\n", 3);
	}
/*	while (stack->cabeza->pos != 1)
	{
		rotate(stack);
		write(1, "ra\n", 3);
	}*/
}
