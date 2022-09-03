/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:25:31 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 20:25:32 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_internal.h"

int	cell_value(const int *cell)
{
	int	idx;

	if (cell_count(cell) != 1)
		return (0);
	idx = -1;
	while (++idx < CELL_SIZE)
		if (cell[idx])
			return (idx + 1);
	return (0);
}
