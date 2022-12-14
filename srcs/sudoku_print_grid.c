/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_print_grid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 17:31:30 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 17:31:31 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include "sudoku_internal.h"

#define LINE_SEP		"---#---#---\n"
#define LINE_SEP_SIZE	12

static inline char	get_char(const int *grid, int x, int y)
{
	int	res;

	res = grid[grid_idx(x, y)];
	if (res == 0)
		return ('.');
	return ((char)(res + '0'));
}

void	sudoku_print_grid(const int *grid)
{
	int		x;
	int		y;
	char	chr;

	if (!grid)
		return ;
	y = -1;
	while (++y < SUDOKU_HEIGHT)
	{
		if (!(y % 3) && y)
			write(STDOUT, LINE_SEP, LINE_SEP_SIZE);
		x = -1;
		while (++x < SUDOKU_WIDTH)
		{
			if (!(x % 3) && x)
				write(STDOUT, "|", 1);
			chr = get_char(grid, x, y);
			write(STDOUT, &chr, 1);
		}
		write(STDOUT, "\n", 1);
	}
}
