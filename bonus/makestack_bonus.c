/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:41:51 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/28 18:30:10 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker_bonus.h"

t_nodo	*make_nodo(int num)
{
	t_nodo	*new;

	new = (t_nodo *)malloc(sizeof(t_nodo));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

void	put_nodo(t_list *list, int num)
{
	t_nodo	*ptr;
	t_nodo	*nodo;

	if (!list)
		return ;
	ptr = list->head;
	nodo = make_nodo(num);
	if (!nodo)
		return ;
	if (list->head == NULL)
		list->head = nodo;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		if (ptr)
			ptr->next = nodo;
	}
}

void	makestack(t_list *list, int argc, char **argv)
{
	int		i;

	i = 1;
	(void)argc;
	while (argv[i])
	{
		put_nodo(list, ft_atoi(argv[i]));
		i++;
	}
	position(list);
}
