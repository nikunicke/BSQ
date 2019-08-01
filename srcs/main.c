/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:22:05 by npimenof          #+#    #+#             */
/*   Updated: 2019/07/31 23:25:32 by rjaakonm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		*grid_start(char *grid, char *marks, int *start, int i)
{
	int		j;
	char	*height;

	while (grid[i] != '\n')
		i++;
	marks[0] = grid[i - 3];
	marks[1] = grid[i - 2];
	marks[2] = grid[i - 1];
	marks[3] = '\0';
	height = malloc(sizeof(char) * (i - 2));
	j = 0;
	while (j < i - 3)
	{
		if (grid[j] < '0' || grid[j] > '9')
			return (0);
		height[j] = grid[j];
		j++;
	}
	height[j] = '\0';
	start[0] = i + 1;
	start[1] = ft_atoi(height);
	free(height);
	return (start);
}

int		grid_process(char *map, t_vars *vars, int start, char *marks)
{
	int		**int_grid;
	char	**grid;

	int_grid = create_grid(map, vars, start, marks);
	if (int_grid == 0)
		return (1);
	grid = split_rows(map, vars, start);
	bsq_solver(int_grid, vars);
	output(grid, marks, vars);
	return (0);
}

int		string_process(t_list *first, t_vars *vars)
{
	char	*map;
	char	marks[4];
	int		start[2];

	if (vars->length < 6)
		return (error_output());
	map = elems_to_string(first, vars->length);
	if (headercheck(map) == 1)
		return (error_output());
	start[0] = *grid_start(map, marks, start, 0);
	dimensions(map, start[1], 0, vars);
	if (!vars->yy || marks[0] == marks[1])
		return (error_output());
	if (grid_process(map, vars, start[0], marks))
		return (error_output());
	return (0);
}

int		read_loop(int ac, char **av, int i, t_vars *vars)
{
	t_list	*node;
	char	buf[BUF_SIZE + 1];

	while (++i < ac)
	{
		vars->fd = open(av[i], O_RDONLY);
		if (vars->fd == -1)
			vars->errors += error_output();
		else
		{
			node = 0;
			while ((vars->ret = read(vars->fd, buf, BUF_SIZE)))
			{
				vars->length += vars->ret;
				buf[vars->ret] = '\0';
				ft_list_push_back(&node, ft_strdup(buf, vars->ret));
			}
			vars->errors += string_process(node, vars);
		}
		close(vars->fd);
		vars = var_reset(vars);
		if (i < ac - 1)
			ft_putchar('\n');
	}
	return (vars->errors);
}

int		main(int ac, char **av)
{
	t_vars	*vars;
	t_list	*node;
	char	buf[BUF_SIZE + 1];

	vars = 0;
	vars = var_init(vars);
	if (ac > 1)
	{
		if (variable_handler(ac, av, vars))
			return (1);
	}
	else
	{
		node = 0;
		while ((vars->ret = read(0, buf, BUF_SIZE)))
		{
			vars->length += vars->ret;
			buf[vars->ret] = '\0';
			ft_list_push_back(&node, ft_strdup(buf, vars->ret));
		}
		if (string_process(node, vars))
			return (1);
	}
	free(vars);
	return (0);
}
