/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 15:44:35 by abaurens          #+#    #+#             */
/*   Updated: 2018/08/21 02:12:40 by abaurens         ###   ########.fr       */
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

void	print_cell(t_cell *cell)
{
	if (!cell->value)
		printf("%s", RED);
	printf("%c ", cell->value ? cell->value + '0' : '-');
	printf("%s", RESET);
}

void	display(t_sudoku *sudoku)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 9)
	{
		x = -1;
		if (y == 0)
			printf(CYN "╔═══╤═══╤═══╦═══╤═══╤═══╦═══╤═══╤═══╗\n" RESET);
		while (++x < 9)
		{
			printf(CYN "%s" RESET, x % 3 == 0 ? "║" : "│");
			print_cell(&sudoku->cells[y][x]);
		}
		printf(CYN "║" RESET);
		printf("\n");
		if (y == 8)
			printf(CYN "╚═══╧═══╧═══╩═══╧═══╧═══╩═══╧═══╧═══╝\n" RESET);
		else if (y % 3 == 2)
			printf(CYN "╠═══╪═══╪═══╬═══╪═══╪═══╬═══╪═══╪═══╣\n" RESET);
		else
			printf(CYN "╟───┼───┼───╫───┼───┼───╫───┼───┼───╢\n" RESET);
	}
	printf("\n");
	UNUSED(sudoku);
}

void	display_sudoku(t_sudoku *sudoku)
{
	int	y;
	int	x;

	y = -1;
	while (++y < 9)
	{
		x = -1;
		while (++x < 9)
		{
			putnbr_bin(sudoku->cells[y][x].possible, 9, 0);
			write(1, x < 8 ? " " : "\n", 1);
		}
	}
}

void			debug_print_cell(t_cell *cell, int l)
{
	char		*color;
	const char	*nm[3][3] = {
		{"1", "2", "3"},
		{"4", "5", "6"},
		{"7", "8", "9"}
	};

	color = (char *)GRN;
	if (count_cell_possibilities(cell) > 1)
		color = (char *)MAG;
	printf(" %s%s %s%s %s%s " RESET,
		color, !(cell->possible & v_tab[1 + 3 * l]) ? (nm[l][0]) : RED"-",
		color, !(cell->possible & v_tab[2 + 3 * l]) ? (nm[l][1]) : RED"-",
		color, !(cell->possible & v_tab[3 + 3 * l]) ? (nm[l][2]) : RED"-");
}

void	debug_display(t_sudoku *sudoku)
{
	int	y;
	int	x;
	int l;

	y = -1;
	while (++y < 9)
	{
		l = -1;
		if (y == 0)
			printf(CYN "╔═══════╤═══════╤═══════╦═══════╤═══════╤═══════╦═══════╤═══════╤═══════╗\n" RESET);
		while (++l < 3)
		{
			x = -1;
			while (++x < 9)
			{
				printf(CYN "%s" RESET, x % 3 == 0 ? "║" : "│");
				debug_print_cell(&sudoku->cells[y][x], l);
			}
			printf(CYN "║" RESET);
			printf("\n");
		}
		if (y == 8)
			printf(CYN "╚═══════╧═══════╧═══════╩═══════╧═══════╧═══════╩═══════╧═══════╧═══════╝\n" RESET);
		else if (y % 3 == 2)
			printf(CYN "╠═══════╪═══════╪═══════╬═══════╪═══════╪═══════╬═══════╪═══════╪═══════╣\n" RESET);
		else
			printf(CYN "╟───────┼───────┼───────╫───────┼───────┼───────╫───────┼───────┼───────╢\n" RESET);
	}
	printf("\n");
	UNUSED(sudoku);
}
