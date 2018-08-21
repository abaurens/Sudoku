/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inclusive_conduction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 02:22:53 by abaurens          #+#    #+#             */
/*   Updated: 2018/08/21 02:23:01 by abaurens         ###   ########.fr       */
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
			if (count_cell_possibilities(&sudoku->cells[y][x]) == 1)
			{
				xx = -1;
				v = get_cell_value(&sudoku->cells[y][x]);
				while (++xx < 9)
					if (count_cell_possibilities(&sudoku->cells[y][xx]) > 1)
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
			if (count_cell_possibilities(&sudoku->cells[y][x]) == 1)
			{
				yy = -1;
				v = get_cell_value(&sudoku->cells[y][x]);
				while (++yy < 9)
					if (count_cell_possibilities(&sudoku->cells[yy][x]) > 1)
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
			if (count_cell_possibilities(&sudoku->cells[y][x]) == 1)
			{
				yy = y / 3 * 3 - 1;
				v = get_cell_value(&sudoku->cells[y][x]);
				while (++yy < y / 3 * 3 + 3)
				{
					xx = x / 3 * 3 - 1;
					while (++xx < x / 3 * 3 + 3)
						if (count_cell_possibilities(&sudoku->cells[yy][xx]) > 1)
							sudoku->cells[yy][xx].possible |= v_tab[v];
				}
			}
		}
	}
}

void	inclusive_reduction(t_sudoku *sudoku)
{
	reduce_lines_possibilities(sudoku);
	reduce_columns_possibilities(sudoku);
	reduce_squares_possibilities(sudoku);
}
