/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:19:25 by jgravalo          #+#    #+#             */
/*   Updated: 2024/05/28 23:42:11 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/push_swap.h"

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

long	ft_atoill(char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

int	check_num(char **argv, int i)
{
	int		j;

	j = 0;
	if (argv[i][j] == '-')
	{
		j++;
		if (argv[i][j] < '0' || argv[i][j] > '9')
			return (-1);
	}
	while (argv[i][j])
	{
		if (argv[i][j] < '0' || argv[i][j] > '9')
		{
			if (argv[i][j] == ' ')
				return (-1);
			return (-1);
		}
		j++;
	}
	return (0);
}

int	check_rep(char **argv, int i)
{
	int		j;

	j = i + 1;
	while (argv[j])
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			return (-1);
		j++;
	}
	return (0);
}

int	check_errors(char **argv)
{
	int		i;

	i = 1;
	if (ft_strcmp(argv[1], "") == 0)
		return (-1);
	while (argv[i])
	{
		if (check_num(argv, i) != 0)
			return (-1);
		if (ft_atoill(argv[i]) > 2147483647 || ft_atoill(argv[i]) < -2147483648)
			return (-1);
		if (check_rep(argv, i) != 0)
			return (-1);
		i++;
	}
	i = 1;
	while (argv[i + 1])
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (0);
		i++;
	}
	return (1);
}
