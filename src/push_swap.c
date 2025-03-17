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

#include "../inc/push_swap.h"

void	error(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

int	push_swap(int argc, char **argv)
{
	t_list	*list;
	t_list	*list_2;

	if (argc < 2)
		return (0);
	if (check_errors(argv) == -1)
		error();
	if (check_errors(argv) == 1)
		return (0);
	list = (t_list *)malloc(sizeof(t_list));
	list->head = NULL;
	list_2 = (t_list *)malloc(sizeof(t_list));
	list_2->head = NULL;
	makestack(list, argc, argv);
	if (stacklen(list) <= 2)
		order_2(list);
	else if (stacklen(list) <= 5)
		order_5(list, list_2);
	else
		order_n(list, list_2);
	free_stack(list_2);
	free_stack(list);
	return (0);
}

int	main(int argc, char **argv)
{
	push_swap(argc, argv);
	return (0);
}
