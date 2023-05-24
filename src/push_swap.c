/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:50:46 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/24 15:59:52 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

int	push_swap(int argc, char **argv)
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
	free_stack(lista_2);
	free_stack(lista);
	return (0);
}
