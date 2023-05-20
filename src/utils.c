/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgravalo <jgravalo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:29:05 by jgravalo          #+#    #+#             */
/*   Updated: 2023/05/20 19:25:47 by jgravalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	while (s1[i])
	{	
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{	
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*s2;
	int		j;

	if (!s)
		return (0);
	j = 0;
	if (start > ft_strlen(s))
	{
		s2 = malloc(sizeof(char));
		s2[0] = '\0';
		return (s2);
	}
	if (ft_strlen(s) - start < len)
		s2 = malloc(sizeof(char) * ft_strlen(s) - start + 1);
	else
		s2 = malloc(len + 1);
	if (!s2)
		return (0);
	while (j < len && s[start + j] != '\0')
	{
		s2[j] = s[start + j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

int	words(char *s, char c)
{
	int	j;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s && *s != c)
			{
				s++;
			}
			j++;
		}
		else
			++s;
	}
	return (j);
}

char	**ft_split(char *s, char c)
{
	int		i;
	int		j;
	char	**res;

	i = 0;
	j = 1;
	res = (char **) malloc((words(s, c) * (sizeof(char *))) + 16);
	if (!res || !s)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (*s && *s != c && ++i)
				s++;
			res[j++] = ft_substr(s - i, 0, i);
		}
		else
			++s;
	}
	res[j] = NULL;
	return (res);
}
