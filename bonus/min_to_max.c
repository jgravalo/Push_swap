/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_to_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:32:45 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/03 17:49:47 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	max_num(t_list *stack)
{
	int		max;
	t_nodo	*ptr;

	ptr = stack->head;
	max = ptr->num;
	while (ptr)
	{
		if (ptr->num > max)
			max = ptr->num;
		ptr = ptr->next;
	}
	return (max);
}

int	min_num(t_list *stack)
{
	int		min;
	t_nodo	*ptr;

	ptr = stack->head;
	min = ptr->num;
	while (ptr)
	{
		if (ptr->num < min)
			min = ptr->num;
		ptr = ptr->next;
	}
	return (min);
}

void	position(t_list *stack)
{
	int		max;
	int		min;
	int		pos;
	t_nodo	*ptr;

	min = min_num(stack);
	max = max_num(stack);
	pos = 1;
	while (min <= max)
	{
		ptr = stack->head;
		while (ptr)
		{
			if (ptr->num == min)
			{
				ptr->pos = pos;
				pos++;
				break ;
			}
			ptr = ptr->next;
		}
		min++;
	}
}

int	stacklen(t_list *stack)
{
	int		i;
	t_nodo	*ptr;

	i = 0;
	ptr = stack->head;
	while (ptr)
	{
		ptr = ptr->next;
		i++;
	}
	return (i);
}
