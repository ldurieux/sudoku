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

/* return an array of cells made from grid */
int		*sudoku_make(const int *grid);

/* makes sure 2 cells does not have the same value
 * on the same line / row / group */
void	sudoku_cleanup(int *cells);

/* solve by searching for the only position
 * where a value can be */
void	sudoku_solve_simple(int *cells);
/* solve by trying different combinations of cells
 * must be called with cell_idx = 0 */
t_bool	sudoku_solve_backtrack(int *cells, int cell_idx);

/* collapse all cells into grid
 * if a cell is uncertain the corresponding value in
 * grid will be 0 */
void	sudoku_collapse(const int *cells, int *grid);

t_bool	sudoku_is_solved(const int *cells);
t_bool	sudoku_is_impossible(const int *cells);

/* print the internal state of each cell
 * used for debug purposes */
void	sudoku_print_cells(const int *cells);

/* return the count of possibilities in a cell */
int		cell_count(const int *cell);

/* return the value of cell only if cell is certain
 * otherwise returns 0 */
int		cell_value(const int *cell);
/* check if a value is possible in the cell cell */
t_bool	cell_contains(const int *cell, int val);
/* set a value in a cell, all other values become impossible */
void	cell_set(int *cell, int val);

/* remove the possibility val from cell
 * returns true if the cell has become
 * certain */
t_bool	cell_remove(int *cell, int val);

/* get index of value in a 1d array
 * from x and y pos */
/* get index of value at `x` `y` in grid */
static inline int	grid_idx(int x, int y)
{
	return (y * SUDOKU_WIDTH + x);
}

/* get index of cell at `x` `y` in cells */
static inline int	cell_idx(int x, int y)
{
	return (y * (SUDOKU_WIDTH * CELL_SIZE) + x * CELL_SIZE);
}

/* get index of item `item` in cell at `x` `y` in cells */
static inline int	cell_item_idx(int x, int y, int item)
{
	return (y * (SUDOKU_WIDTH * CELL_SIZE) + x * CELL_SIZE + item);
}

#endif // SUDOKU_INTERNAL_H
