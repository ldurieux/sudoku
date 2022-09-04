/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:18:05 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 18:18:07 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include "sudoku_internal.h"

void	cell_init(int *cell, int value)
{
	int	idx;

	idx = -1;
	if (!value)
		while (++idx < CELL_SIZE)
			cell[idx] = idx + 1;
	else
	{
		while (++idx < CELL_SIZE)
		{
			cell[idx] = 0;
			if (idx == value - 1)
				cell[idx] = value;
		}
	}
}

int	*sudoku_make(const int *grid)
{
	int	*cells;
	int	x;
	int	y;

	cells = malloc(sizeof(int) * SUDOKU_WIDTH * SUDOKU_HEIGHT * CELL_SIZE);
	if (!cells)
		return (NULL);
	y = -1;
	while (++y < SUDOKU_HEIGHT)
	{
		x = -1;
		while (++x < SUDOKU_WIDTH)
			cell_init(cells + cell_idx(x, y), grid[grid_idx(x, y)]);
	}
	sudoku_cleanup(cells);
	return (cells);
}
