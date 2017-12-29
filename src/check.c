/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 11:01:13 by ojerroud          #+#    #+#             */
/*   Updated: 2017/07/05 11:01:15 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verif(char *s, int i, int hash, int dot)
{
	int	count;
	int	nl;

	nl = 0;
	count = count_tetriminos(s);
	if ((int)ft_strlen(s) != (count * 20 + count - 1))
		return (0);
	while (s[i])
	{
		if (s[i] == '.')
			dot++;
		else if (s[i] == '#')
			hash++;
		else if (s[i] == '\n')
			nl++;
		else
			return (0);
		i++;
	}
	if (dot != (count * 12) || hash != (count * 4) ||
			nl != (count * 4 + count - 1))
		return (0);
	return (1);
}

int		ft_check_pieces(char *str)
{
	int		i;
	int		ok;

	i = 0;
	ok = 1;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] != '#' && str[i - 1] != '#' && str[i + 5] != '#'
					&& str[i - 5] != '#')
				return (0);
		}
		i++;
	}
	return (1);
}

int		valid_tetris(char **tetris, int i, int j)
{
	if ((j + 1) >= 0 && tetris[i][j + 1] == '#')
		if (((j + 1) % 4) == 0)
			return (0);
	return (((j - 1) >= 0 && tetris[i][j - 1] == '#')
			+ ((j - 4) >= 0 && tetris[i][j - 4] == '#')
			+ ((j + 1) <= 15 && tetris[i][j + 1] == '#')
			+ ((j + 4) <= 15 && tetris[i][j + 4] == '#'));
}

int		check_map(char **square, char *str, int i, int j)
{
	int	dots;
	int	size;
	int	k;

	size = count_nr(square);
	dots = dots_number(str);
	k = dots - 1;
	while (str[++k] != '\0')
	{
		if (str[k] != '.')
		{
			if ((j + (k / 4) - (dots / 4) >= size)
					|| (i + (k % 4) - (dots % 4) >= size)
					|| square[j + (k / 4) - (dots / 4)]
					[(i + (k % 4) - (dots % 4))] != '.')
				return (1);
		}
	}
	return (0);
}

void	valid(char **tetris, int i, int j, int hash)
{
	int	ok;
	int	center;

	while (tetris[++i] != '\0')
	{
		center = 0;
		while ((tetris[i][++j] != '\0') && (tetris[i][j] == '.' ||
					tetris[i][j] == '\n' || tetris[i][j] == '#'))
			if (tetris[i][j] == '#')
			{
				if ((ok = valid_tetris(tetris, i, j)) > 0)
				{
					hash++;
					if (ok > 1)
						center = ok;
				}
				else
					error();
			}
		if (center <= 1 || hash != 4 || tetris[i][j] != '\0')
			error();
		hash = 0;
		j = -1;
	}
}
