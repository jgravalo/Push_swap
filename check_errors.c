/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 15:19:25 by jgravalo          #+#    #+#             */
/*   Updated: 2022/12/02 18:09:02 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include"push_swap.h"

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

void	check_num(char **argv, int i)
{
	int		j;

	j = 0;
	if (argv[i][j] == '-')
		j++;
	while (argv[i][j])
	{
		if (argv[i][j] < '0' || argv[i][j] > '9')
		{
			printf("argumento no numerico");// BORRAR !!!!
			exit(-1);
		}
		j++;
	}
}

void	check_rep(char **argv, int i)
{
	int		j;

	j = i + 1;
	while (argv[j])
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
		{
			printf("argumento repetido\n");// BORRAR !!!!
			printf("%s\n", argv[j]);// BORRAR !!!!
			exit(-1);
		}
		j++;
	}
}

int	check_errors(char **argv)
{
	int		i;

	i = 1;
	while (argv[i])
	{
		check_num(argv, i);
		if (ft_atoill(argv[i]) > 2147483647 || ft_atoill(argv[i]) < -2147483648)
		{
			printf("argumento no int");// BORRAR !!!!
			exit(-1);
		}
		check_rep(argv, i);
		i++;
	}
	i = 1;
	while (argv[i + 1])
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

/*
int main(int argc, char **argv)
{

    if (argc <= 1)
        return (0);
    if (check_errors(argv) == 0)
	{
		printf("OK!");
        return (0);
	}
    printf("a ordenar");
    return (0);
}*/
