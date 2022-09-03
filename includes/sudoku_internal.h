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

typedef struct s_sudoku
{
	int	*cells;
}	t_sudoku;

t_sudoku	sudoku_make(int *grid);

/* get index of value in a 1d array
 * from x and y pos */
//NOLINTBEGIN(readability-magic-number)
static inline int	grid_idx(int x, int y)
{
	return (y * SUDOKU_WIDTH + x);
}

static inline int	cell_idx(int x, int y)
{
	return (y * (SUDOKU_WIDTH * CELL_SIZE) + x * CELL_SIZE);
}
//NOLINTEND

#endif // SUDOKU_INTERNAL_H
