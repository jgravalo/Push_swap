/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:41:51 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/11 14:45:56 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

t_move	*make_move(char *move, int len)
{
	t_move	*new;

	new = (t_move *)malloc(sizeof(t_move));
	new->move = move;
	new->len = len;
	new->next = NULL;
//	printf("move = %s(%d)\n", new->move, new->len);// BORRAR
	return (new);
}

void	put_move(t_list *lista, char *move, int len)
{
	t_move	*ptr;
	t_move	*nodo;
	
	ptr = lista->cadena;
	nodo = make_move(move, len);
	if (lista->cadena == NULL)
		lista->cadena = make_move(move, len);
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = nodo;
//		printf("move = %s(%d)\n", ptr->next->move, ptr->next->len);// BORRAR
	}
}

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
