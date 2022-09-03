/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_is_impossible.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:53:59 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 22:54:00 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_internal.h"

t_bool	sudoku_is_impossible(const int *cells)
{
	int	idx;

	idx = -1;
	while (++idx < SUDOKU_WIDTH * SUDOKU_HEIGHT)
		if (cell_count(cells + (t_ptrdiff)idx * CELL_SIZE) == 0)
			return (1);
	return (0);
}
