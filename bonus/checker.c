/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:50:46 by jgravalo          #+#    #+#             */
/*   Updated: 2024/05/28 23:36:34 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	do_move(t_list *stack, t_list *stack_2, char *move)
{
	if (ft_strcmp(move, "pa\n") == 0)
		push(stack_2, stack);
	if (ft_strcmp(move, "pb\n") == 0)
		push(stack, stack_2);
	if (ft_strcmp(move, "sa\n") == 0 || ft_strcmp(move, "ss\n") == 0)
		swap(stack);
	if (ft_strcmp(move, "sb\n") == 0 || ft_strcmp(move, "ss\n") == 0)
		swap(stack_2);
	if (ft_strcmp(move, "ra\n") == 0 || ft_strcmp(move, "rr\n") == 0)
		rotate(stack);
	if (ft_strcmp(move, "rb\n") == 0 || ft_strcmp(move, "rr\n") == 0)
		rotate(stack_2);
	if (ft_strcmp(move, "rra\n") == 0 || ft_strcmp(move, "rrr\n") == 0)
		reverse_rotate(stack);
	if (ft_strcmp(move, "rrb\n") == 0 || ft_strcmp(move, "rrr\n") == 0)
		reverse_rotate(stack);
}

int	compare(t_list *stack, t_list *stack_2)
{
	char	*c;
	int		i;
	t_nodo	*ptr;

	i = 0;
	c = get_next_line(0);
	while (c != NULL && c[0] != '\0' && c[0] != '\n')
	{
		do_move(stack, stack_2, c);
		free(c);
		c = get_next_line(0);
	}
	free(c);
	ptr = stack->head;
	while (ptr)
	{
		if (i + 1 != ptr->pos)
			return (-1);
		ptr = ptr->next;
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*stack_2;

	if (argc < 2)
		return (0);
	if (check_errors(argv) == -1)
	{
		write(2, "Error\n", 6);
		exit(-1);
	}
	stack = (t_list *)malloc(sizeof(t_list));
	stack->head = NULL;
	stack_2 = (t_list *)malloc(sizeof(t_list));
	stack_2->head = NULL;
	makestack(stack, argc, argv);
	if (compare(stack, stack_2))
	{
		free_stack(stack_2);
		free_stack(stack);
		write(1, "KO\n", 3);
		return (-1);
	}
	write(1, "OK\n", 3);
	free_stack(stack_2);
	free_stack(stack);
	return (0);
}
