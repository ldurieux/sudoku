/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:18:09 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 18:18:10 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"
#include "sudoku_internal.h"

t_bool	sudoku_solve(int *grid)
{
	int	*cells;

	cells = sudoku_make(grid);
	if (!cells)
		return (0);
	sudoku_print_cells(cells);
	free(cells);
	return (0);
}
