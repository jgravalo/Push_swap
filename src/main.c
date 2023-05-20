/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:06:59 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/20 18:17:34 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_move	*p;
	p = push_swap(argc, argv);
	free_list_move(p);
	return (0);
}
