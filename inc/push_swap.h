/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:53:58 by jgravalo          #+#    #+#             */
/*   Updated: 2023/04/27 15:23:17 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "push_swap.h"

typedef struct s_nodo
{
	int				num;
	int				pos;
	struct s_nodo	*next;
}	t_nodo;

typedef struct s_list
{
	t_nodo	*cabeza;
	t_move	*cadena;
}	t_list;

typedef struct s_move
{
	char			*move;
	struct s_move	*next;
}	t_move;

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

int		push(t_list *stack, t_list *stack_2);

int		swap(t_list *stack);

int		rotate(t_list *stack);

int		reverse_rotate(t_list *stack);

void    move(t_list *stack, int fin);

void    best_rotate(t_list *stack);

void    first_push(t_list *stack, t_list *stack_2, int len);
//void    first_push(t_list *stack, t_list *stack_2);

void    last_push(t_list *stack, t_list *stack_2, int len);
//void    last_push(t_list *stack, t_list *stack_2);

void	order_2(t_list *stack);

void	order_3(t_list *stack, t_list *stack_2);

void	order_5(t_list *stack, t_list *stack_2);

void	order_n(t_list *stack, t_list *stack_2);

int		push_swap(int argc, char **argv);

int		main(int argc, char **argv);

#endif
