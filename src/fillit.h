/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ojerroud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:29:32 by ojerroud          #+#    #+#             */
/*   Updated: 2017/07/05 14:29:39 by ojerroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# define BUFF_SIZE 546

void	error(void);
int		ft_verif(char *s, int i, int hash, int dot);
int		ft_check_pieces(char *str);
int		valid_tetris(char **tetris, int i, int j);
int		check_map(char **square, char *str, int i, int j);
void	valid(char **tetris, int i, int j, int hash);
int		count_tetriminos(char *str);
int		count_nr(char **str);
void	convert_hash(char **tetris, int i, int j);
int		dots_number(char *str);
void	free_square(char **square);
int		resolve(char **tetris, char **map, int i);
void	aff_calc(char **calc);
void	ft_call_all(char **tetris, int count, char *buf, int fd);
int		ft_sqrt(int len);
char	**get_in_calc(char *array, int count, int i, int j);
char	**fix_tetris(char **square, char *str, int i, int j);
char	**ft_exit(char **square, char *str, int i, int j);
char	**new_square(int size);
void	fillit(char **calc, int nb);

#endif
