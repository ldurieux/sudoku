/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_cleanup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:25:33 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 20:25:37 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_internal.h"

typedef struct s_cleanup_data
{
	int	*cells;
	int	val;
	int	idx;
}	t_cleanup_data;

static t_bool	cells_cleanup_line(t_cleanup_data *data)
{
	t_bool	res;
	int		x;
	int		y;

	res = 0;
	x = -1;
	y = data->idx / SUDOKU_WIDTH;
	while (++x < SUDOKU_WIDTH)
	{
		if (x == data->idx % SUDOKU_WIDTH)
			continue ;
		if (cell_remove(data->cells + cell_idx(x, y), data->val))
			res = 1;
	}
	return (res);
}

static t_bool	cells_cleanup_row(t_cleanup_data *data)
{
	t_bool	res;
	int		x;
	int		y;

	res = 0;
	x = data->idx % SUDOKU_HEIGHT;
	y = -1;
	while (++y < SUDOKU_HEIGHT)
	{
		if (y == data->idx / SUDOKU_WIDTH)
			continue ;
		if (cell_remove(data->cells + cell_idx(x, y), data->val))
			res = 1;
	}
	return (res);
}

static t_bool	cells_cleanup_group(t_cleanup_data *data)
{
	t_bool	res;
	int		group_x;
	int		group_y;
	int		x;
	int		y;

	res = 0;
	group_x = (data->idx % SUDOKU_WIDTH) / 3 * 3;
	group_y = (data->idx / SUDOKU_WIDTH) / 3 * 3;
	y = group_y - 1;
	while (++y < group_y + 3)
	{
		x = group_x - 1;
		while (++x < group_x + 3)
		{
			if (y * SUDOKU_WIDTH + x == data->idx)
				continue ;
			if (cell_remove(data->cells + cell_idx(x, y), data->val))
				res = 1;
		}
	}
	return (res);
}

static inline void	call_cleanup(t_bool *again, t_cleanup_data *data,
					t_bool (*f)(t_cleanup_data *))
{
	if (*again)
		f(data);
	else
		*again = f(data);
}

void	sudoku_cleanup(int *cells)
{
	t_bool			again;
	t_cleanup_data	d;

	d.cells = cells;
	again = 1;
	while (again)
	{
		again = 0;
		d.idx = -1;
		while (++d.idx < SUDOKU_HEIGHT * SUDOKU_WIDTH)
		{
			d.val = cell_value(cells + (t_ptrdiff)d.idx * CELL_SIZE);
			if (d.val)
			{
				call_cleanup(&again, &d, cells_cleanup_line);
				call_cleanup(&again, &d, cells_cleanup_row);
				call_cleanup(&again, &d, cells_cleanup_group);
			}
		}
	}
}
