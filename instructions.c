/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:46:59 by jgravalo          #+#    #+#             */
/*   Updated: 2022/11/28 22:04:40 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	push(t_list *stack, t_list *stack_2)
{
	t_nodo	*ptr;

	if (!stack)
		return ;
	ptr = stack->cabeza;
	stack->cabeza = ptr->next;
	ptr->next = stack_2->cabeza;
	stack_2->cabeza = ptr;
}

void	swap(t_list *stack)
{
	t_nodo	*ptr;
	t_nodo	*ptr2;

	if (!stack)
		return ;
	ptr = stack->cabeza;
	ptr2 = ptr->next;
	ptr->next = ptr2->next;
	ptr2->next = ptr;
	stack->cabeza = ptr2;
}

void	rotate(t_list *stack)
{
	t_nodo	*ptr;

	if (!stack)
		return ;
	ptr = stack->cabeza;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = stack->cabeza;
	ptr = ptr->next;
	stack->cabeza = ptr->next;
	ptr->next = NULL;
}

void	reverse_rotate(t_list *stack)
{
	t_nodo	*ptr;

	if (!stack)
		return ;
	ptr = stack->cabeza;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = stack->cabeza;
	stack->cabeza = ptr;
	while (ptr->next != stack->cabeza)
		ptr = ptr->next;
	ptr->next = NULL;
}
