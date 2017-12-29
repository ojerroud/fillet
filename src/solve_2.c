/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:04:20 by ojerroud          #+#    #+#             */
/*   Updated: 2017/07/05 14:04:22 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**get_in_calc(char *array, int count, int i, int j)
{
	char	**calc;

	if (!(calc = (char**)malloc(sizeof(char*) * count + 1)))
		return (NULL);
	calc[count] = NULL;
	while (i < count)
	{
		if (!(calc[i++] = (char*)malloc(sizeof(char) * 16 + 1)))
			return (NULL);
		calc[i - 1][16] = '\0';
	}
	count = 0;
	i = 0;
	while (array[i] != '\0')
	{
		if (array[i] != '\n')
			calc[j][count++] = array[i];
		if (((i + 1) % 21) == 0)
		{
			count = 0;
			j++;
		}
		i++;
	}
	return (calc);
}

char	**fix_tetris(char **square, char *str, int i, int j)
{
	int	k;
	int	dots;

	dots = dots_number(str);
	k = dots - 1;
	while (str[++k])
	{
		if (str[k] != '.')
			square[j + (k / 4) - (dots / 4)][i + (k % 4) - (dots % 4)] = str[k];
	}
	return (square);
}

char	**ft_exit(char **square, char *str, int i, int j)
{
	char	chr;

	chr = str[dots_number(str)];
	while (square[j])
	{
		while (square[j][i])
		{
			if (square[j][i] == chr)
				square[j][i] = '.';
			i++;
		}
		i = 0;
		j++;
	}
	return (square);
}

char	**new_square(int size)
{
	char	**square;
	int		i;
	int		j;

	i = 0;
	if (!(square = malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	square[size] = NULL;
	while (i < size)
	{
		if (!(square[i] = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		square[i][size] = '\0';
		i++;
	}
	i = 0;
	while (square[i])
	{
		j = 0;
		while (j < size)
			square[i][j++] = '.';
		i++;
	}
	return (square);
}

void	fillit(char **calc, int nb)
{
	char	**map;
	int		size;

	size = ft_sqrt(nb * 4);
	map = new_square(size);
	while (resolve(calc, map, 0) == 0)
	{
		size++;
		free_square(map);
		map = new_square(size);
	}
	aff_calc(map);
}
