/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:53:58 by jgravalo          #+#    #+#             */
/*   Updated: 2022/12/01 17:21:06 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "push_swap.h"

typedef struct nodo
{
	int			num;
	int			pos;
	struct nodo	*next;
}	t_nodo;

typedef struct lista
{
	t_nodo	*cabeza;
}	t_list;

int		push_swap(int argc, char **argv);

int		check_errors(char **argv);

void	makestack(t_list *lista, int argc, char **argv);

int		stacklen(t_list *stack);

void	print_stack(t_list *stack);// BORRAR !!!!

void	print_2stack(t_list *stack, t_list *stack_2);// BORRAR !!!!

void    print_points(t_list *stack);// BORRAR !!!!

int		max_num(t_list *stack);

int		min_num(t_list *stack);

void	position(t_list *stack);

void	push(t_list *stack, t_list *stack_2);

void	swap(t_list *stack);

void	rotate(t_list *stack);

void	reverse_rotate(t_list *stack);

void    move(t_list *stack, int fin);

void    best_rotate(t_list *stack);

void	order_2(t_list *stack);

void	order_3(t_list *stack, t_list *stack_2);

void	order_5(t_list *stack, t_list *stack_2);

void	order_n(t_list *stack, t_list *stack_2);

#endif
