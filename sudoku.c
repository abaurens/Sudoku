/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:27:26 by abaurens          #+#    #+#             */
/*   Updated: 2018/08/17 01:44:28 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

static void	reduce_lines_possibilities(t_sudoku *sudoku)
{
	int		v;
	int		y;
	int		x;
	int		xx;

	y = -1;
	while (++y < 9)
	{
		x = -1;
		while (++x < 9)
		{
			if (sudoku->cells[y][x].value != 0)
			{
				v = sudoku->cells[y][x].value;
				xx = -1;
				while (++xx < 9)
					if (sudoku->cells[y][xx].value == 0)
						sudoku->cells[y][xx].possible |= v_tab[v];
			}
		}
	}
}

static void reduce_columns_possibilities(t_sudoku *sudoku)
{
	int		v;
	int		x;
	int		y;
	int		yy;

	x = -1;
	while (++x < 9)
	{
		y = -1;
		while (++y < 9)
		{
			if (sudoku->cells[y][x].value != 0)
			{
				v = sudoku->cells[y][x].value;
				yy = -1;
				while (++yy < 9)
					if (sudoku->cells[yy][x].value == 0)
						sudoku->cells[yy][x].possible |= v_tab[v];
			}
		}
	}
}

static void reduce_squares_possibilities(t_sudoku *sudoku)
{
	int		y;
	int		x;
	int		v;
	int		xx;
	int		yy;

	x = -1;
	while (++x < 9 && (y = -1))
	{
		while (++y < 9)
		{
			if (sudoku->cells[y][x].value != 0)
			{
				yy = y / 3 * 3 - 1;
				v = sudoku->cells[y][x].value;
				while (++yy < y / 3 * 3 + 3)
				{
					xx = x / 3 * 3 - 1;
					while (++xx < x / 3 * 3 + 3)
						if (sudoku->cells[yy][xx].value == 0)
							sudoku->cells[yy][xx].possible |= v_tab[v];
				}
			}
		}
	}
}

#include <stdio.h>

void	simple_reduction(t_sudoku *sudoku)
{
	reduce_lines_possibilities(sudoku);
	reduce_columns_possibilities(sudoku);
	reduce_squares_possibilities(sudoku);
}

void	reduce_possibilities(t_sudoku *sudoku)
{
	int	c;
	int	y;
	int	x;
	int	tmp;

	y = -1;

	simple_reduction(sudoku);
	adv_reduce_squares_possibilities(sudoku);

	while (++y < 9)
	{
		x = -1;
		while (++x < 9)
		{
			c = 0;
			if (sudoku->cells[y][x].value != 0)
				continue;
			tmp = sudoku->cells[y][x].possible;
			while (tmp > 0 && c < 2)
			{
				if (tmp % 2 == 0)
					c++;
				tmp /= 2;
			}
		}
	}
	/*adv_reduce_lines_possibilities(sudoku);*/
	/*adv_reduce_columns_possibilities(sudoku);*/
}
