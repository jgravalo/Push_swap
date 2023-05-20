/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:24:39 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/20 19:24:48 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"
#include"../inc/checker.h"
#include<string.h>

void	conditions1(t_list *stack, t_list *stack_2, char *c)
{
	if (ft_strcmp(c, "pa\n") == 0)
		push(stack_2, stack);
	else if (ft_strcmp(c, "pb\n") == 0)
		push(stack, stack_2);
	else if (ft_strcmp(c, "sa\n") == 0)
		swap(stack);
	else if (ft_strcmp(c, "sb\n") == 0)
		swap(stack_2);
	else if (ft_strcmp(c, "ss\n") == 0)
	{
		swap(stack);
		swap(stack_2);
	}
}

void	conditions2(t_list *stack, t_list *stack_2, char *c)
{
	if (ft_strcmp(c, "ra\n") == 0)
		rotate(stack);
	else if (ft_strcmp(c, "rb\n") == 0)
		rotate(stack_2);
	else if (ft_strcmp(c, "rr\n") == 0)
	{
		rotate(stack);
		rotate(stack_2);
	}
	else if (ft_strcmp(c, "rra\n") == 0)
		reverse_rotate(stack);
	else if (ft_strcmp(c, "rrb\n") == 0)
		reverse_rotate(stack_2);
	else if (ft_strcmp(c, "rrr\n") == 0)
	{
		reverse_rotate(stack);
		reverse_rotate(stack_2);
	}
}

int	check(t_list *stack)
{
	t_nodo	*ptr;
	int		i;

	ptr = stack->cabeza;
	i = 1;
	while (ptr != NULL)
	{
		if (ptr->pos != i)
		{
			write(1, "KO\n", 3);
			exit(-1);
		}
		ptr = ptr->next;
		i++;
	}
	write(1, "OK\n", 3);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*stack_2;
	t_move	*ptr;

	stack = malloc(sizeof(t_list));
	stack_2 = malloc(sizeof(t_list));
	makestack(stack, argc, argv);
	stack->cadena = push_swap(argc, argv);
	ptr = stack->cadena;
	while (ptr != NULL)
	{
		conditions1(stack, stack_2, ptr->move);
		conditions2(stack, stack_2, ptr->move);
		ptr = ptr->next;
	}
	check(stack);
	return (0);
}
