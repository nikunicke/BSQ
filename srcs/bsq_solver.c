/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq_solver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 17:19:37 by npimenof          #+#    #+#             */
/*   Updated: 2019/08/01 09:34:44 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		min(int **grid, int x, int y)
{
	int		nums[3];

	nums[0] = grid[y][x - 1];
	nums[1] = grid[y - 1][x];
	nums[2] = grid[y - 1][x - 1];
	if (nums[0] > nums[1])
		nums[0] = nums[1];
	if (nums[0] > nums[2])
		nums[0] = nums[2];
	return (nums[0]);
}

void	setmax(int **grid, t_vars *vars)
{
	vars->y = -1;
	while (++vars->y < vars->yy)
	{
		vars->x = 0;
		while (vars->x < vars->xx)
		{
			if (grid[vars->y][vars->x] > 0)
			{
				if (vars->max < grid[vars->y][vars->x])
				{
					vars->max = grid[vars->y][vars->x];
					vars->max_x = vars->x;
					vars->max_y = vars->y;
				}
			}
			vars->x++;
		}
		if (vars->y > 0)
			free(grid[vars->y - 1]);
	}
	free(grid[vars->y - 1]);
	free(grid);
}

void	bsq_solver(int **grid, t_vars *vars)
{
	vars->y = -1;
	while (++vars->y < vars->yy)
	{
		vars->x = 0;
		while (vars->x < vars->xx)
		{
			if (vars->x != 0 && vars->y != 0)
			{
				if (grid[vars->y][vars->x] > 0)
				{
					grid[vars->y][vars->x] = 1 + min(grid, vars->x, vars->y);
				}
			}
			vars->x++;
		}
	}
	setmax(grid, vars);
}

void	output(char **map, char *marks, t_vars *vars)
{
	int		i;
	int		j;

	i = vars->max;
	while (i > 0)
	{
		j = vars->max;
		while (j > 0)
		{
			map[vars->max_y - i + 1][vars->max_x - j + 1] = marks[2];
			j--;
		}
		i--;
	}
	i = 0;
	while (i < vars->yy)
	{
		ft_putstr(map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}
