/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 14:38:45 by abaurens          #+#    #+#             */
/*   Updated: 2018/08/17 01:38:29 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

char		check_args(int ac, char **av, t_sudoku *sudoku)
{
	int 	i;
	int		j;
	int		value;

	i = 0;
	if (ac != 10)
		return (0);
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (!contains(".123456789", av[i][j]) || j > 8)
				return (0);
			value = (av[i][j] == '.' ? 0 : av[i][j] - '0');
			sudoku->cells[i - 1][j].value = value;
			sudoku->cells[i - 1][j].possible = value ? CN - v_tab[value] : v_tab[value];
			j++;
		}
		if (j < 9)
			return (0);
	}
	return (1);
}
