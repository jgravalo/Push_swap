/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makestack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:41:51 by jgravalo          #+#    #+#             */
/*   Updated: 2023/04/27 15:20:22 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

t_move	*join_move(char *move)
{
	t_move	new;

	new = (t_move *)malloc(sizeof(char) * ft_strlen(move));
	new.move = move;
	new.next == NULL;
	return (new);
}

void	*makemove(t_move *instructions, char *move)
{
	t_move	*ptr;
	
	ptr = instructions;
	if (instructions == NULL)
		ptr->next = join_move(move);
	else
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = join_move(move);
	}
}

t_nodo	*makenodo(int num)
{
	t_nodo	*new;

	new = (t_nodo *)malloc(sizeof(t_nodo));
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
