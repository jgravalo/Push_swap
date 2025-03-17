/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:46:59 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/19 20:27:05 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	push(t_list *stack, t_list *stack_2)
{
	t_nodo	*ptr;

	if (!stack)
		return (-1);
	ptr = stack->head;
	stack->head = ptr->next;
	ptr->next = stack_2->head;
	stack_2->head = ptr;
	return (0);
}

int	swap(t_list *stack)
{
	t_nodo	*ptr;
	t_nodo	*ptr2;

	if (!stack)
		return (-1);
	ptr = stack->head;
	ptr2 = ptr->next;
	ptr->next = ptr2->next;
	ptr2->next = ptr;
	stack->head = ptr2;
	return (0);
}

int	rotate(t_list *stack)
{
	t_nodo	*ptr;

	if (!stack)
		return (-1);
	ptr = stack->head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = stack->head;
	ptr = ptr->next;
	stack->head = ptr->next;
	ptr->next = NULL;
	return (0);
}

int	reverse_rotate(t_list *stack)
{
	t_nodo	*ptr;

	if (!stack)
		return (-1);
	ptr = stack->head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = stack->head;
	stack->head = ptr;
	while (ptr->next != stack->head)
		ptr = ptr->next;
	ptr->next = NULL;
	return (0);
}
