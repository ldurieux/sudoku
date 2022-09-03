/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 01:03:23 by ldurieux          #+#    #+#             */
/*   Updated: 2022/09/04 01:03:24 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "sudoku.h"

//NOLINTBEGIN(readability-magic-number)
int	main(void)
{
	int	grid[81] = {
		0, 0, 4,  0, 2, 0,  1, 0, 6,
		0, 0, 0,  0, 0, 0,  0, 8, 0,
		5, 0, 0,  0, 0, 7,  0, 0, 0,

		0, 6, 0,  2, 0, 0,  0, 0, 0,
		0, 0, 1,  0, 6, 0,  3, 0, 4,
		0, 0, 0,  0, 0, 0,  0, 0, 9,

		4, 0, 0,  5, 0, 0,  8, 0, 3,
		0, 0, 0,  0, 3, 0,  0, 9, 0,
		0, 0, 8,  0, 0, 0,  0, 2, 0,
	};

	ft_putendl_fd("to solve :", STDOUT);
	sudoku_print_grid(grid);
	ft_putendl_fd("", STDOUT);
	if (!sudoku_solve(grid))
	{
		ft_putendl_fd("\nCouldn't solve sudoku", STDOUT);
		return (1);
	}
	ft_putendl_fd("\nsolved :", STDOUT);
	sudoku_print_grid(grid);
	return (0);
}
//NOLINTEND
