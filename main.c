/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 11:58:17 by abaurens          #+#    #+#             */
/*   Updated: 2018/08/21 04:04:59 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "sudoku.h"

const unsigned short v_tab[] = { CA, C1, C2, C3, C4, C5, C6, C7, C8, C9 };

int				main(int ac, char **av)
{
	t_sudoku	sudoku;

	if (!check_args(ac, av, &sudoku))
		return (1);
	inclusive_reduction(&sudoku);
	debug_display(&sudoku);
	reduce_possibilities(&sudoku);
	debug_display(&sudoku);
	reduce_possibilities(&sudoku);
	debug_display(&sudoku);
	reduce_possibilities(&sudoku);
	debug_display(&sudoku);
	return (0);
}
