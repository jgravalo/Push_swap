/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_pos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:02:57 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/19 18:24:21 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <string.h>

int	search_pos(t_list *stack, int range)
{
	t_nodo	*ptr;
	int		i;
	int		first_e;

	ptr = stack->head;
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

	ptr = stack->head;
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
