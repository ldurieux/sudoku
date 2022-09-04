/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_print_cells.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:18:07 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 18:18:08 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include "sudoku_internal.h"

#define LINE_SEP		"           |           |           \n"
#define FULL_LINE_SEP	"-----------#-----------#-----------\n"
#define LINE_SEP_SIZE	36

static inline void	print_item(const int *cells, int item_idx, int x, int y)
{
	char	res;

	res = (char)cells[cell_item_idx(x, y, item_idx)];
	if (res == 0)
		res = '.';
	else
		res += '0';
	write(STDOUT, &res, 1);
}

void	sudoku_print_cells_line(const int *cells, int y)
{
	int		x;
	int		item_idx;

	item_idx = 0;
	while (item_idx < CELL_SIZE)
	{
		x = 0;
		while (x < SUDOKU_WIDTH)
		{
			if (!(x % 3) && x)
				write(STDOUT, "|", 1);
			print_item(cells, item_idx, x, y);
			print_item(cells, item_idx + 1, x, y);
			print_item(cells, item_idx + 2, x, y);
			x++;
			if (x % 3)
				write(STDOUT, " ", 1);
		}
		item_idx += 3;
		write(STDOUT, "\n", 1);
	}
}

void	sudoku_print_cells(const int *cells)
{
	int		y;

	if (!cells)
		return ;
	y = 0;
	while (y < SUDOKU_HEIGHT)
	{
		if (!(y % 3) && y)
			write(STDOUT, FULL_LINE_SEP, LINE_SEP_SIZE);
		sudoku_print_cells_line(cells, y);
		y++;
		if (y % 3)
			write(STDOUT, LINE_SEP, LINE_SEP_SIZE);
	}
}
