/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 14:29:26 by npimenof          #+#    #+#             */
/*   Updated: 2019/07/31 15:57:34 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int		**create_grid(char *str, t_vars *vars, int i, char *marks)
{
	int		**grid;

	if (!(grid = malloc(sizeof(int*) * vars->yy + 1)))
		return (0);
	while (str[i] != '\0' && vars->y < vars->yy)
	{
		if (!(grid[vars->y] = malloc(sizeof(int) * vars->xx)))
			return (0);
		vars->x = 0;
		while (str[i] != '\n')
		{
			if (str[i] == marks[0])
				grid[vars->y][vars->x] = 1;
			else if (str[i] == marks[1])
				grid[vars->y][vars->x] = 0;
			else
				return (0);
			vars->x++;
			i++;
		}
		i++;
		vars->y++;
	}
	grid[vars->y] = 0;
	return (grid);
}

char	**split_rows(char *str, t_vars *vars, int i)
{
	char	**grid;

	if (!(grid = malloc(sizeof(char*) * vars->yy + 1)))
		return (0);
	vars->y = 0;
	while (str[i] != '\0' && vars->y < vars->yy)
	{
		if (!(grid[vars->y] = malloc(sizeof(char) * vars->xx + 2)))
			return (0);
		vars->x = 0;
		while (str[i] != '\n')
		{
			grid[vars->y][vars->x] = str[i];
			vars->x++;
			i++;
		}
		grid[vars->y][vars->x] = '\n';
		grid[vars->y][vars->x + 1] = '\0';
		i++;
		vars->y++;
	}
	free(str);
	grid[vars->y] = 0;
	return (grid);
}

void	ft_putnbr(int nb)
{
	long i;

	i = nb;
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
	}
	if (i > 9)
	{
		ft_putnbr(i / 10);
		ft_putchar(i % 10 + '0');
	}
	else
	{
		ft_putchar(i + '0');
	}
}
