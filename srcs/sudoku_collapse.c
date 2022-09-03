/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_collapse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:45:44 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 20:45:45 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_internal.h"

void	sudoku_collapse(int *cells, int *grid)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SUDOKU_HEIGHT)
	{
		x = -1;
		while (++x < SUDOKU_WIDTH)
			grid[grid_idx(x, y)] = cell_value(cells + cell_idx(x, y));
	}
}
