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

int		*sudoku_make(const int *grid);
void	sudoku_print_cells(const int *cells);

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
