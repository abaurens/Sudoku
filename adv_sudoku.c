/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adv_sudoku.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:52:48 by abaurens          #+#    #+#             */
/*   Updated: 2018/08/17 01:37:59 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

#include <stdio.h>

int		count_possibilities_in_square(t_sudoku *sudoku, int x, int y, int v)
{
	int	p;
	int	yy;
	int	xx;

	p = 0;
	yy = y / 3 * 3 - 1;
	while (++yy < y / 3 * 3 + 3)
	{
		xx = x / 3 * 3 - 1;
		while (++xx < x / 3 * 3 + 3)
		{
			if ((sudoku->cells[yy][xx].possible & v_tab[v]) == 0)
			{
				p++;
			}
		}
	}
	if (p == 1)
		printf("%d possible positions for digit %d in square [%d, %d]\n", p, v, x, y);
	return (p);
}

/*
void	adv_reduce_lines_possibilities(t_sudoku *sudoku)
{

}
*/


/*
void	adv_reduce_columns_possibilities(t_sudoku *sudoku)
{

}
*/

void	adv_reduce_squares_possibilities(t_sudoku *sudoku)
{
	int	x;
	int	y;
	int	v;

	y = -1;
	while (++y < 9)
	{
		x = -1;
		while (++x < 9)
		{
			v = 0;
			while (++v < 10)
			{
				if (sudoku->cells[y][x].value)
					continue;
				if ((sudoku->cells[y][x].possible & v_tab[v]) != 0)
					continue;
				if (count_possibilities_in_square(sudoku, x, y, v) == 1)
				{
					sudoku->cells[y][x].value = v;
					sudoku->cells[y][x].possible = CN - v_tab[v];
					simple_reduction(sudoku);
					break;
				}
			}
		}
	}
}
