/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:46:17 by jgravalo          #+#    #+#             */
/*   Updated: 2022/02/25 13:26:54 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

size_t	intlen(int n);

char	*ft_strcpy(char *dest, char *src);

char	*ft_negative(int n, char *c, int l);

char	*ft_positive(int n, char *c, int l);

char	*ft_itoa(int n)
{
	char	*c;
	int		l;

	l = intlen(n);
	c = malloc(l + 1);
	if (!c)
		return (0);
	if (n == -2147483647 - 1)
		ft_strcpy(c, "-2147483648\0");
	if (n == 0)
		ft_strcpy(c, "0\0");
	if (n < 0)
		c = ft_negative(n, c, l);
	else
		c = ft_positive(n, c, l);
	c[intlen(n)] = '\0';
	return (c);
}

size_t	intlen(int n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n == -2147483647 - 1)
		count = 11;
	if (n < 0)
	{
		n = n * -1;
		count++;
	}	
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_positive(int n, char *c, int l)
{
	while (n > 0)
	{
		c[l - 1] = n % 10 + 48;
		n = n / 10;
		l--;
	}
	return (c);
}

char	*ft_negative(int n, char *c, int l)
{
	n = n * -1;
	while (n > 0)
	{
		c[l - 1] = n % 10 + 48;
		n = n / 10;
		l--;
	}
	c[0] = '-';
	return (c);
}
