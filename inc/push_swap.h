/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:53:58 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/20 19:13:42 by jgravalo         ###   ########.fr       */
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

typedef struct s_move
{
	char			*move;
	int				len;
	struct s_move	*next;
}	t_move;

typedef struct s_list
{
	t_nodo	*cabeza;
	t_move	*cadena;
}	t_list;

void	free_list_nodo(t_nodo *lst);

void	free_list_move(t_move *lst);

void	free_stack(t_list *lst);

int		check_errors(char **argv);

int		words(char *s, char c);

char	**ft_split(char *s, char c);

int		ft_strcmp(char *s1, char *s2);

void	makestack(t_list *lista, int argc, char **argv);

void	put_move(t_list *lista, char *move, int len);

void	print_moves(t_move *move);

int		ft_strlen(char *s);

int		stacklen(t_list *stack);

void	print_stack(t_list *stack);// BORRAR !!!!

void	print_2stack(t_list *stack, t_list *stack_2);// BORRAR !!!!

void	print_points(t_list *stack);// BORRAR !!!!

int		max_num(t_list *stack);

int		min_num(t_list *stack);

void	position(t_list *stack);

int		push(t_list *stack, t_list *stack_2);

int		swap(t_list *stack);

int		rotate(t_list *stack);

int		reverse_rotate(t_list *stack);

void	move(t_list *stack, int fin);

void	best_rotate(t_list *stack);

int		search_pos(t_list *stack, int range);

int		search_pos2(t_list *stack, int range);

void	first_push(t_list *stack, t_list *stack_2, int len, int ind);

void	last_push(t_list *stack, t_list *stack_2, int len);

void	order_2(t_list *stack);

void	order_3(t_list *stack, t_list *stack_2);

void	order_5(t_list *stack, t_list *stack_2);

void	order_n(t_list *stack, t_list *stack_2);

t_move	*push_swap(int argc, char **argv);

int		main(int argc, char **argv);

#endif
