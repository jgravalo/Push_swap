/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:41:51 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/24 16:01:05 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

t_nodo	*make_nodo(int num)
{
	t_nodo	*new;

	new = (t_nodo *)malloc(sizeof(t_nodo));
	new->num = num;
	new->next = NULL;
	return (new);
}

void	put_nodo(t_list *lista, int num)
{
	t_nodo	*ptr;
	t_nodo	*nodo;

	ptr = lista->cabeza;
	nodo = make_nodo(num);
	if (lista->cabeza == NULL)
		lista->cabeza = nodo;
	else
	{
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = nodo;
	}
}

void	makestack(t_list *lista, int argc, char **argv)
{
	int		i;
	t_nodo	*ptr;

	ptr = lista->cabeza;
	lista->cabeza = ptr;
	i = 1;
	while (i <= argc - 1)
	{
		put_nodo(lista, atoi(argv[i]));
		i++;
	}
	position(lista);
}
