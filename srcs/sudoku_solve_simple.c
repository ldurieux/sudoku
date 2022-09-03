/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solve_simple.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:41:02 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 22:41:04 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_internal.h"

typedef struct s_solve_data
{
	int	*cells;
	int	idx;
}	t_solve_data;

static inline t_bool	solve_from_line(t_solve_data *data, int *cell, int val)
{
	int	x;
	int	y;
	int	*cur_cell;

	x = -1;
	y = data->idx / SUDOKU_WIDTH;
	while (++x < SUDOKU_WIDTH)
	{
		cur_cell = data->cells + cell_idx(x, y);
		if (cur_cell == cell)
			continue ;
		if (cell_contains(cur_cell, val))
			return (0);
	}
	cell_set(cell, val);
	return (1);
}

static inline t_bool	solve_from_row(t_solve_data *data, int *cell, int val)
{
	int	x;
	int	y;
	int	*cur_cell;

	x = data->idx % SUDOKU_WIDTH;
	y = -1;
	while (++y < SUDOKU_HEIGHT)
	{
		cur_cell = data->cells + cell_idx(x, y);
		if (cur_cell == cell)
			continue ;
		if (cell_contains(cur_cell, val))
			return (0);
	}
	cell_set(cell, val);
	return (1);
}

static t_bool	solve_from_group(t_solve_data *data, int *cell, int val)
{
	int		group_x;
	int		group_y;
	int		x;
	int		y;
	int		*cur_cell;

	group_x = (data->idx % SUDOKU_WIDTH) / 3 * 3;
	group_y = (data->idx / SUDOKU_WIDTH) / 3 * 3;
	y = group_y - 1;
	while (++y < group_y + 3)
	{
		x = group_x - 1;
		while (++x < group_x + 3)
		{
			cur_cell = data->cells + cell_idx(x, y);
			if (cur_cell == cell)
				continue ;
			if (cell_contains(cur_cell, val))
				return (0);
		}
	}
	cell_set(cell, val);
	return (1);
}

static inline t_bool	solve_cell(t_solve_data *data)
{
	int	*cell;
	int	idx;

	cell = data->cells + (t_ptrdiff)data->idx * CELL_SIZE;
	if (cell_count(cell) <= 1)
		return (0);
	idx = -1;
	while (++idx < CELL_SIZE)
	{
		if (!cell[idx])
			continue ;
		if (solve_from_line(data, cell, cell[idx]))
			return (1);
		if (solve_from_row(data, cell, cell[idx]))
			return (1);
		if (solve_from_group(data, cell, cell[idx]))
			return (1);
	}
	return (0);
}

/* try to solve every cell until no cell
 * were solved in the loop
*/
void	sudoku_solve_simple(int *cells)
{
	t_solve_data	d;
	t_bool			again;

	d.cells = cells;
	again = 1;
	while (again)
	{
		again = 0;
		d.idx = -1;
		while (++d.idx < SUDOKU_HEIGHT * SUDOKU_WIDTH)
			if (solve_cell(&d))
				again = 1;
		if (again)
			sudoku_cleanup(cells);
	}
}
