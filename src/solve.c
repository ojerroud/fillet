/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 11:01:25 by ojerroud          #+#    #+#             */
/*   Updated: 2017/07/05 11:01:26 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_square(char **square)
{
	int	i;
	int	j;

	j = 0;
	i = count_nr(square);
	while (j < i)
	{
		free(square[j]);
		j++;
	}
	free(square);
}

int		resolve(char **tetris, char **map, int i)
{
	int		x;
	int		y;
	char	*str;

	if (!tetris[i])
		return (1);
	y = -1;
	str = tetris[i];
	while (++y < count_nr(map))
	{
		x = 0;
		while (x < count_nr(map))
		{
			if (check_map(map, str, x, y) == 0)
			{
				map = fix_tetris(map, str, x, y);
				if (resolve(tetris, map, i + 1) == 1)
					return (1);
				else
					ft_exit(map, str, 0, 0);
			}
			x++;
		}
	}
	return (0);
}

void	aff_calc(char **calc)
{
	int	i;

	i = 0;
	while (calc[i])
	{
		ft_putendl(calc[i]);
		i++;
	}
}

void	ft_call_all(char **tetris, int count, char *buf, int fd)
{
	tetris = get_in_calc(buf, count, 0, 0);
	free(buf);
	valid(tetris, -1, -1, 0);
	convert_hash(tetris, 0, 0);
	fillit(tetris, count);
	close(fd);
}

int		ft_sqrt(int len)
{
	int i;

	i = 2;
	while (i * i < len)
		i++;
	return (i);
}
