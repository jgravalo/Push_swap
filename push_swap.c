/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:50:46 by jgravalo          #+#    #+#             */
/*   Updated: 2022/12/19 12:53:12 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"push_swap.h"

// MAIN

int	push_swap(int argc, char **argv)
{
	t_list	*lista;
	t_list	*lista_2;

	if (argc < 2 || check_errors(argv) == 0)
		return (0);
	lista = (t_list *)malloc(sizeof(t_list));
	lista_2 = (t_list *)malloc(sizeof(t_list));
	makestack(lista, argc, argv);
	position(lista);
	print_2stack(lista, lista_2);
	if (stacklen(lista) <= 2)
		order_2(lista);
	else if (stacklen(lista) <= 5)
		order_5(lista, lista_2);
	else
		order_n(lista, lista_2);
	print_2stack(lista, lista_2);
	print_points(lista);
	print_points(lista_2);
	return (0);
}
