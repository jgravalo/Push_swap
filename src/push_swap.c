/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:50:46 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/05 13:06:38 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

void	print_moves(t_move *move)
{
	t_move	*ptr;

	ptr = move;
	while (ptr != NULL)
	{
		//printf("esta aqui\n");// BORRAR
		write(1, ptr->move, ptr->len);
		ptr = ptr->next;
	}
}

t_move	*push_swap(int argc, char **argv)
{
	t_list	*lista;
	t_list	*lista_2;

	if (argc < 2)
		return (0);
	if (check_errors(argv) == -1)
	{
		write(1, "Error\n", 6);
		exit(-1);
	}
	if (check_errors(argv) == 1)
		return (0);
	lista = (t_list *)malloc(sizeof(t_list));
	lista_2 = (t_list *)malloc(sizeof(t_list));
	makestack(lista, argc, argv);
//	print_2stack(lista, lista_2);// BORRAR
	if (stacklen(lista) <= 2)
		order_2(lista);
	else if (stacklen(lista) <= 5)
		order_5(lista, lista_2);
	else
		order_n(lista, lista_2);
//	printf("move head = %s(%d)\n", move->move, move->len);// BORRAR
	print_moves(lista->cadena);
	print_2stack(lista, lista_2);// BORRAR
//	print_points(lista);// BORRAR
//	print_points(lista_2);// BORRAR
	return (lista->cadena);
}
