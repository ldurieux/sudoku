/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_is_solved.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:53:56 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 22:53:58 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_internal.h"

t_bool	sudoku_is_solved(int *cells)
{
	int	idx;

	idx = -1;
	while (++idx < SUDOKU_WIDTH * SUDOKU_HEIGHT)
		if (cell_count(cells + (t_ptrdiff)idx * CELL_SIZE) != 1)
			return (0);
	return (1);
}
