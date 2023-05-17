/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:50:46 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/17 18:11:07 by jgravalo         ###   ########.fr       */
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

char	**get_arg(int *argc, char **argv)
{
	char **arg;

//	printf("argc = %d\n", *argc);
	*argc = words(argv[1], ' ') + 1;
//	printf("argc = %d\n", *argc);
//	printf("\"%s\"\n", argv[1]);
	arg = ft_split(argv[1], ' ');
	arg[0] = argv[0];
	return (arg);
}

t_move	*push_swap(int argc, char **argv)
{
	t_list	*lista;
	t_list	*lista_2;
//	int i;

	if (argc < 2)
		return (0);
//	for (i = 0; argv[i]; i++)
//		printf("\"%s\"\n", argv[i]);
	if (check_errors(argv) == 2)
		argv = get_arg(&argc, argv);
//	for (i = 0; argv[i]; i++)
//		printf("\"%s\"\n", argv[i]);
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
//	print_moves(lista->cadena);
	print_2stack(lista, lista_2);// BORRAR
//	print_points(lista);// BORRAR
//	print_points(lista_2);// BORRAR
	return (lista->cadena);
}
