/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:25:26 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 20:25:27 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_internal.h"

int	cell_count(const int	*cell)
{
	int	idx;
	int	count;

	count = 0;
	idx = -1;
	while (++idx < CELL_SIZE)
		if (cell[idx])
			count++;
	return (count);
}
