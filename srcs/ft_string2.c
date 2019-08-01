/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:31:22 by npimenof          #+#    #+#             */
/*   Updated: 2019/07/31 19:40:29 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

char	*elems_to_string(t_list *node, int size)
{
	char	*str;
	t_list	*tmp;
	int		last;

	last = 0;
	if (size <= 0)
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	str[0] = '\0';
	while (node)
	{
		str = ft_strcat(str, node->data, &last);
		tmp = node;
		node = node->next;
		free(tmp->data);
		free(tmp);
	}
	free(node);
	return (str);
}

void	dimensions(char *str, int height, int i, t_vars *vars)
{
	while (str[i] != '\n')
		i++;
	while (str[++i] != '\n' && str[i] != '\0')
		vars->xx++;
	vars->row_len = vars->xx;
	while (str[i] != '\0' && vars->yy <= height)
	{
		if (str[i] == '\n')
		{
			if (vars->row_len != vars->xx)
				break ;
			vars->yy++;
			vars->row_len = -1;
		}
		vars->row_len++;
		i++;
	}
	if (vars->yy < height || vars->xx == 0)
		vars->yy = 0;
	else
		vars->yy = height;
	str[i] = '\0';
}
