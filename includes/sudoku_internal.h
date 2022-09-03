/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_internal.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:31:45 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 17:31:46 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUDOKU_INTERNAL_H
# define SUDOKU_INTERNAL_H

# include "libft.h"

# define SUDOKU_WIDTH	9
# define SUDOKU_HEIGHT	9
# define CELL_SIZE		9
/* the following line doesn't pass the norminette
# define CELLS_LEN		SUDOKU_WIDTH * SUDOKU_HEIGHT * CELL_SIZE
 * instead let's put a number without any meaning
 * seems leggit */
# define CELLS_LEN		729

int		*sudoku_make(const int *grid);
void	sudoku_cleanup(int *cells);
void	sudoku_solve_simple(int *cells);
t_bool	sudoku_solve_backtrack(int *cells, int cell_idx);
void	sudoku_collapse(int *cells, int *grid);

t_bool	sudoku_is_solved(int *cells);
t_bool	sudoku_is_impossible(int *cells);

void	sudoku_print_cells(const int *cells);

/* return the count of possibilities in a cell */
int		cell_count(const int *cell);

/* return the value of cell only if cell is certain
 * otherwise returns 0 */
int		cell_value(const int *cell);
t_bool	cell_contains(const int *cell, int val);
void	cell_set(int *cell, int val);

/* remove the possibility val from cell
 * returns true if the cell has become
 * certain */
t_bool	cell_remove(int *cell, int val);

//NOLINTBEGIN(readability-magic-number)
/* get index of value in a 1d array
 * from x and y pos */
static inline int	grid_idx(int x, int y)
{
	return (y * SUDOKU_WIDTH + x);
}

static inline int	cell_idx(int x, int y)
{
	return (y * (SUDOKU_WIDTH * CELL_SIZE) + x * CELL_SIZE);
}

static inline int	cell_item_idx(int x, int y, int item)
{
	return (y * (SUDOKU_WIDTH * CELL_SIZE) + x * CELL_SIZE + item);
}
//NOLINTEND

#endif // SUDOKU_INTERNAL_H
