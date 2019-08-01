/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npimenof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 10:58:10 by npimenof          #+#    #+#             */
/*   Updated: 2019/07/31 15:41:18 by npimenof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

char	*ft_strdup(char *src, unsigned int n)
{
	char	*dest;
	int		i;

	if (!(dest = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src, int *last)
{
	int	i;
	int	j;

	i = 0;
	while (dest[*last] != '\0')
		(*last)++;
	j = 0;
	while (src[j])
	{
		dest[*last + j] = src[j];
		j++;
	}
	*last += j;
	dest[*last] = '\0';
	return (dest);
}

int		ft_atoi(char *str)
{
	int		i;
	long	result;
	long	pn;

	result = 0;
	pn = 1;
	i = 0;
	while (str[i] < 43)
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		pn = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return ((int)(result * pn));
}
