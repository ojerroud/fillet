/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 11:00:15 by ojerroud          #+#    #+#             */
/*   Updated: 2017/07/05 11:00:18 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

int		count_tetriminos(char *str)
{
	int		i;
	int		nl;

	nl = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nl++;
		i++;
	}
	return ((nl + 1) / 5);
}

int		count_nr(char **str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	convert_hash(char **tetris, int i, int j)
{
	char	c;

	c = 'A';
	while (tetris[j] != '\0')
	{
		while (tetris[j][i] != '\0')
		{
			if (tetris[j][i] == '#')
				tetris[j][i] = c;
			i++;
		}
		i = 0;
		c++;
		j++;
	}
	if (c > 'Z' + 1)
		error();
}

int		dots_number(char *str)
{
	int i;

	i = 0;
	while (str[i] == '.')
		i++;
	return (i);
}
