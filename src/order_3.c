/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:19:10 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/19 18:04:53 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	order_2(t_list *stack)
{
	t_nodo	*ptr;

	ptr = stack->cabeza;
	if (ptr->pos > ptr->next->pos)
	{
		swap(stack);
		put_move(stack, "sa\n", 3);
	}
}

void	instructions1(t_list *stack, t_list *stack_2, int i)
{
	if (i == 1)
	{
		reverse_rotate(stack);
		put_move(stack, "rra\n", 4);
	}
	if (i == 2)
	{
		rotate(stack);
		put_move(stack, "ra\n", 3);
		swap(stack);
		if (stacklen(stack_2) == 2
			&& stack_2->cabeza->pos < stack_2->cabeza->next->pos)
		{
			swap(stack_2);
			put_move(stack, "ss\n", 3);
		}
		else
			put_move(stack, "sa\n", 3);
		reverse_rotate(stack);
		put_move(stack, "rra\n", 4);
	}
}

void	instructions2(t_list *stack, t_list *stack_2, int i)
{
	if (i == 3)
	{
		rotate(stack);
		put_move(stack, "ra\n", 3);
	}
	if (i == 4)
	{
		swap(stack);
		if (stacklen(stack_2) == 2
			&& stack_2->cabeza->pos < stack_2->cabeza->next->pos)
		{
			swap(stack_2);
			put_move(stack, "ss\n", 3);
		}
		else
			put_move(stack, "sa\n", 3);
	}
}

void	instructions3(t_list *stack, t_list *stack_2, int i)
{
	if (i == 5)
	{
		rotate(stack);
		put_move(stack, "ra\n", 3);
		swap(stack);
		if (stacklen(stack_2) == 2
			&& stack_2->cabeza->pos < stack_2->cabeza->next->pos)
		{
			swap(stack_2);
			put_move(stack, "ss\n", 3);
		}
		else
			put_move(stack, "sa\n", 3);
	}
}

void	order_3(t_list *stack, t_list *stack_2)
{
	t_nodo	*ptr;

	ptr = stack->cabeza;
	if (ptr->next->pos > ptr->pos && ptr->next->pos > ptr->next->next->pos)
	{
		if (ptr->pos > ptr->next->next->pos)
			instructions1(stack, stack_2, 1);
		else
			instructions1(stack, stack_2, 2);
	}
	else if (ptr->next->pos < ptr->pos && ptr->next->pos < ptr->next->next->pos)
	{
		if (ptr->pos > ptr->next->next->pos)
			instructions2(stack, stack_2, 3);
		else
			instructions2(stack, stack_2, 4);
	}
	else if (ptr->next->pos < ptr->pos && ptr->next->pos > ptr->next->next->pos)
		instructions3(stack, stack_2, 5);
}
