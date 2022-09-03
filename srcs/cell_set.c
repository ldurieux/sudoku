/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cell_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 22:41:00 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/03 22:41:01 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku_internal.h"

void	cell_set(int *cell, int val)
{
	ft_memset(cell, 0, sizeof(int) * CELL_SIZE);
	cell[val - 1] = val;
}
