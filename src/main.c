/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 11:00:24 by ojerroud          #+#    #+#             */
/*   Updated: 2017/07/05 11:57:21 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		count;
	int		bytes;
	char	**tetris;
	char	*buf;

	if (argc != 2)
	{
		ft_putstr("Usage: ./fillit fillit_map.file\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error();
	tetris = NULL;
	buf = (char*)malloc(BUFF_SIZE + 1);
	bytes = read(fd, buf, BUFF_SIZE + 1);
	if (bytes == -1)
		error();
	buf[bytes] = '\0';
	count = count_tetriminos(buf);
	if (ft_verif(buf, 0, 0, 0) == 0 || ft_check_pieces(buf) == 0)
		error();
	ft_call_all(tetris, count, buf, fd);
	return (0);
}
