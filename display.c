/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:44:35 by abaurens          #+#    #+#             */
/*   Updated: 2018/08/17 02:09:39 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sudoku.h"
#include <stdio.h>

void		putnbr_bin(unsigned int nb, unsigned int len, int color)
{
	char	c;

	if (nb / 2 > 0 || len > 1)
		putnbr_bin(nb / 2, len - 1, color - 1);
	c = nb % 2 + '0';
	if (color == 1)
		write(1, RED, 5);
	write(1, &c, 1);
	if (color == 1)
		write(1, RESET, 4);
}

void	display(t_sudoku *sudoku)
{
	int	i;
	int	j;

	i = -1;
	printf("\n");
	while (++i < 9)
	{
		j = -1;
		while (++j < 9)
		{
			printf("%2c", sudoku->cells[i][j].value ? sudoku->cells[i][j].value + '0' : '-');
			/*write(1, " ", 1);
			putnbr_bin(sudoku->cells[i][j].possible, 9, 9);*/
			/*printf(" %3d", sudoku->cells[i][j].possible);*/
		}
		printf("\n");
	}
}

void	print_cell(t_cell *cell)
{
	if (!cell->value)
		printf("%s", RED);
	printf("%c ", cell->value ? cell->value + '0' : '-');
	printf("%s", RESET);
}

void	display_sudoku(t_sudoku *sudoku)
{
	int	y;
	int	x;

	y = -1;
	printf("\n");
	while (++y < 9)
	{
		x = -1;
		if (y == 0)
			printf(CYN "┏━━━━━━┳━━━━━━┳━━━━━━┓\n" RESET);
		while (++x < 9)
		{
			if (x % 3 == 0)
				printf(CYN "┃" RESET);
			print_cell(&sudoku->cells[y][x]);
			if (x == 8)
				printf(CYN "┃" RESET);
		}
		printf("\n");
		if (y == 8)
			printf(CYN "┗━━━━━━┻━━━━━━┻━━━━━━┛\n" RESET);
		else if (y % 3 == 2)
			printf(CYN "┣━━━━━━╋━━━━━━╋━━━━━━┫\n" RESET);
	}
	UNUSED(sudoku);
}
