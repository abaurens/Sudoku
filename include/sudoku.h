/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaurens <abaurens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 13:28:28 by abaurens          #+#    #+#             */
/*   Updated: 2018/08/21 02:24:21 by abaurens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_H
# define SUDOKU_H

# define UNUSED(x) ((void)(x))
# define MAX(x, y) ((x) > (y) ? (x) : (y))

# define C1 1 << 0/*0b000000001*/
# define C2 1 << 1/*0b000000010*/
# define C3 1 << 2/*0b000000100*/
# define C4 1 << 3/*0b000001000*/
# define C5 1 << 4/*0b000010000*/
# define C6 1 << 5/*0b000100000*/
# define C7 1 << 6/*0b001000000*/
# define C8 1 << 7/*0b010000000*/
# define C9 1 << 8/*0b100000000*/
# define CN 511/*0b111111111*/
# define CA 0/*0b000000000*/

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

extern const unsigned short v_tab[];

typedef struct		s_cell
{
	unsigned short	possible;
	char			value;
}					t_cell;

typedef struct		s_sudoku
{
	t_cell			cells[9][9];
}					t_sudoku;

/*
** preparsing.c
*/
char	check_args(int ac, char **av, t_sudoku *sudoku);

/*
** string_c.c
*/
char	contains(const char * const str, char c);

/*
** display.c
*/
void	putnbr_bin(unsigned int nb, unsigned int len, int color);
void	display_sudoku(t_sudoku *sudoku);
void	debug_display(t_sudoku *sudoku);

/*
** exclusive_conduction.c
*/
/*void	adv_reduce_lines_possibilities(t_sudoku *sudoku);
void	adv_reduce_columns_possibilities(t_sudoku *sudoku);
void	adv_reduce_squares_possibilities(t_sudoku *sudoku);*/
void	exclusive_reduction(t_sudoku *sudoku);

/*
** inclusive_conduction.c
*/
void	inclusive_reduction(t_sudoku *sudoku);

/*
** sudoku.c
*/
int		get_cell_value(t_cell *cell);
int		count_cell_possibilities(t_cell *cell);
void	reduce_possibilities(t_sudoku *sudoku);

#endif
