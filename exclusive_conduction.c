/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exclusive_conduction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 22:52:48 by abaurens          #+#    #+#             */
/*   Updated: 2018/08/21 02:40:38 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"

#include <stdio.h>

int		count_possibilities_in_line(t_sudoku *sudoku, int y, int v)
{
	int	p;
	int	x;

	p = 0;
	x = -1;
	while (++x < 9)
	{
		if ((sudoku->cells[y][x].possible & v_tab[v]) == 0)
			p++;
	}
	if (p == 1)
		printf("%d possible positions for digit %d in line %d\n", p, v, y);
	return (p);
}

int		count_possibilities_in_column(t_sudoku *sudoku, int x, int v)
{
	int	p;
	int	y;

	p = 0;
	y = -1;
	while (++y < 9)
	{
		if ((sudoku->cells[y][x].possible & v_tab[v]) == 0)
			p++;
	}
	if (p == 1)
		printf("%d possible positions for digit %d in column %d\n", p, v, x);
	return (p);
}

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
				p++;
		}
	}
	if (p == 1)
		printf("%d possible positions for digit %d in square [%d, %d]\n", p, v, x, y);
	return (p);
}

/*
void	adv_reduce_lines_possibilities(t_sudoku *sudoku)
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
				if (count_cell_possibilities(&sudoku->cells[y][x]) <= 1)
					continue;
				if ((sudoku->cells[y][x].possible & v_tab[v]) != 0)
					continue;
				if (count_possibilities_in_line(sudoku, y, v) == 1)
				{
					sudoku->cells[y][x].possible = CN - v_tab[v];
					break;
				}
			}
		}
	}
}

void	adv_reduce_columns_possibilities(t_sudoku *sudoku)
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
				if (count_cell_possibilities(&sudoku->cells[y][x]) <= 1)
					continue;
				if ((sudoku->cells[y][x].possible & v_tab[v]) != 0)
					continue;
				if (count_possibilities_in_column(sudoku, x, v) == 1)
				{
					sudoku->cells[y][x].possible = CN - v_tab[v];
					break;
				}
			}
		}
	}
}

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
				if (count_cell_possibilities(&sudoku->cells[y][x]) <= 1)
					continue;
				if ((sudoku->cells[y][x].possible & v_tab[v]) != 0)
					continue;
				if (count_possibilities_in_square(sudoku, x, y, v) == 1)
				{
					sudoku->cells[y][x].possible = CN - v_tab[v];
					break;
				}
			}
		}
	}
}*/

char		has_to_be_here(t_sudoku *sudoku, int x, int y, int v)
{
	if (count_possibilities_in_line(sudoku, y, v) == 1)
		return (1);
	if (count_possibilities_in_column(sudoku, x, v) == 1)
		return (1);
	return (count_possibilities_in_square(sudoku, x, y, v) == 1);
}

void		exclusive_reduction(t_sudoku *sudoku)
{
	int		x;
	int		y;
	int		v;
	char	l;

	l = 1;
	while (l && !(l = 0) && (y = -1))
	{
		while (++y < 9 && (x = -1))
		{
			while (++x < 9 && !(v = 0))
			{
				while (++v < 10)
				{
					if (count_cell_possibilities(&sudoku->cells[y][x]) <= 1 ||
						(sudoku->cells[y][x].possible & v_tab[v]) != 0)
						continue;
					if (has_to_be_here(sudoku, x, y, v) && (l = 1))
						sudoku->cells[y][x].possible = CN - v_tab[v];
				}
			}
		}
	}
	/*adv_reduce_lines_possibilities(sudoku);
	adv_reduce_columns_possibilities(sudoku);
	adv_reduce_squares_possibilities(sudoku);*/
}
