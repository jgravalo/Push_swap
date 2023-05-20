/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:50:46 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/20 19:42:19 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

/*
char	**get_arg(int *argc, char **argv)
{
	char	**arg;

	*argc = words(argv[1], ' ') + 1;
	arg = ft_split(argv[1], ' ');
	arg[0] = argv[0];
	return (arg);
}
*/
void	print_moves(t_move *move)
{
	t_move	*ptr;

	ptr = move;
	while (ptr != NULL)
	{
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
		write(2, "Error\n", 6);
		exit(-1);
	}
	if (check_errors(argv) == 1)
		return (0);
	lista = (t_list *)malloc(sizeof(t_list));
	lista_2 = (t_list *)malloc(sizeof(t_list));
	makestack(lista, argc, argv);
	if (stacklen(lista) <= 2)
		order_2(lista);
	else if (stacklen(lista) <= 5)
		order_5(lista, lista_2);
	else
		order_n(lista, lista_2);
	print_moves(lista->cadena);//	print_2stack(lista, lista_2);// BORRAR
	//print_2stack(lista, lista_2);
	free_stack(lista_2);
	free_list_nodo(lista->cabeza);
	free(lista);
	return (lista->cadena);
}
