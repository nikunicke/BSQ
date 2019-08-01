/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceptions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:43:54 by npimenof          #+#    #+#             */
/*   Updated: 2019/07/31 23:21:14 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		headercheck(char *grid)
{
	int		i;
	int		numbers;
	int		others;

	numbers = 0;
	others = 0;
	i = 0;
	if (grid[0] > '9' || grid[0] < '0')
		return (1);
	while (grid[i] >= '0' && grid[i] <= '9')
	{
		i++;
		numbers++;
	}
	while (grid[i] != '\n')
	{
		i++;
		others++;
	}
	if (others > 3 || (others + numbers) < 4 || numbers < 1)
		return (1);
	return (0);
}

int		error_output(void)
{
	write(2, "map error\n", 10);
	return (1);
}

int		variable_handler(int ac, char **av, t_vars *vars)
{
	vars->errors = read_loop(ac, av, 0, vars);
	if (vars->errors > 0)
		return (1);
	else
		return (0);
}

t_vars	*var_reset(t_vars *vars)
{
	vars->length = 0;
	vars->xx = 0;
	vars->yy = 0;
	vars->x = 0;
	vars->y = 0;
	vars->row_len = 0;
	vars->max = 0;
	vars->max_x = 0;
	vars->max_y = 0;
	return (vars);
}

t_vars	*var_init(t_vars *vars)
{
	if (!(vars = malloc(sizeof(t_vars))))
		return (0);
	vars->length = 0;
	vars->errors = 0;
	vars->xx = 0;
	vars->yy = 0;
	vars->x = 0;
	vars->y = 0;
	vars->row_len = 0;
	vars->fd = 0;
	vars->max = 0;
	vars->max_x = 0;
	vars->max_y = 0;
	return (vars);
}
