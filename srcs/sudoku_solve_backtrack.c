/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solve_backtrack.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 00:50:03 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/04 00:50:04 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_internal.h"

static inline t_bool	ret_success(int *cells, int *copy)
{
	ft_memcpy(cells, copy, sizeof(int) * CELLS_LEN);
	free(copy);
	return (1);
}

static inline int	*prepare_copy(int *cells, int cell_idx,
								int *cell, int item_idx)
{
	int	*copy;

	copy = malloc(sizeof(int) * CELLS_LEN);
	if (!copy)
		return (NULL);
	ft_memcpy(copy, cells, sizeof(int) * CELLS_LEN);
	cell_set(copy + (t_ptrdiff)cell_idx * CELL_SIZE, cell[item_idx]);
	sudoku_solve_simple(copy);
	return (copy);
}

//NOLINTNEXTLINE(misc-no-recursion)
t_bool	sudoku_solve_backtrack(int *cells, int cell_idx)
{
	int	item_idx;
	int	*cell;
	int	*copy;

	if (sudoku_is_impossible(cells))
		return (0);
	if (sudoku_is_solved(cells))
		return (1);
	item_idx = -1;
	cell = cells + (t_ptrdiff)cell_idx * CELL_SIZE;
	if (cell_count(cell) == 1)
		return (sudoku_solve_backtrack(cells, cell_idx + 1));
	while (++item_idx != CELL_SIZE)
	{
		if (!cell[item_idx])
			continue ;
		copy = prepare_copy(cells, cell_idx, cell, item_idx);
		if (!copy)
			return (0);
		if (sudoku_solve_backtrack(copy, cell_idx + 1))
			return (ret_success(cells, copy));
		free(copy);
	}
	return (0);
}
