/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 20:25:27 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 20:25:29 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_internal.h"

/* should return true if the cell has become certain
 * instead return false if the cell is impossible, why ?
 */
t_bool	cell_remove(int *cell, int val)
{
	if (!cell[val - 1])
		return (0);
	cell[val - 1] = 0;
	return (cell_count(cell));
}
