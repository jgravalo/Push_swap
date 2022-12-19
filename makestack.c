/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:41:51 by jgravalo          #+#    #+#             */
/*   Updated: 2022/10/25 14:59:16 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_nodo	*makenodo(int num)
{
	t_nodo	*new;

	new = malloc(sizeof(t_nodo));
	new->num = num;
	new->next = NULL;
	return (new);
}

void	putnodo(t_list *lista, int num)
{
	t_nodo	*ptr;
	t_nodo	*nodo;

	ptr = lista->cabeza;
	nodo = makenodo(num);
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
		putnodo(lista, atoi(argv[i]));
		i++;
	}
}
