/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:07:53 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/24 16:08:09 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

void	free_list_nodo(t_nodo *lst)
{
	t_nodo	*ptr;

	while (lst)
	{
		ptr = lst;
		lst = ptr->next;
		free(ptr);
	}
	free(lst);
}

void	free_stack(t_list *lst)
{
	if (lst->head)
		free_list_nodo(lst->head);
	free(lst);
}
