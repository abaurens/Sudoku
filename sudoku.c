/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 17:27:26 by abaurens          #+#    #+#             */
/*   Updated: 2018/08/21 03:53:32 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

int		count_cell_possibilities(t_cell *cell)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (i < 9)
	{
		if (!(cell->possible & v_tab[i + 1]))
			count++;
		i++;
	}
	return (count);
}

int		get_cell_value(t_cell *cell)
{
	int i;

	i = 0;
	if (count_cell_possibilities(cell) > 1)
		return (0);
	while (i < 9)
	{
		if (!(cell->possible & v_tab[i + 1]))
			return(i + 1);
		i++;
	}
	return (0);
}

void	reduce_possibilities(t_sudoku *sudoku)
{
	exclusive_reduction(sudoku);
	inclusive_reduction(sudoku);
}
