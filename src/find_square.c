/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:30:33 by bcharman          #+#    #+#             */
/*   Updated: 2019/02/18 22:54:59 by aharlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		get_max_side(int x, int y, char **map, t_params params)
{
	int d;
	int i;

	d = 0;
	while (x + d < params.c && y + d < params.l)
	{
		i = x;
		while (i <= x + d)
		{
			if (map[y + d][i] == params.o)
				return (d - 1);
			i++;
		}
		i = y;
		while (i < y + d)
		{
			if (map[i][x + d] == params.o)
				return (d - 1);
			i++;
		}
		d++;
	}
	return (d - 1);
}

t_max	fill_values(int x, int y, int d)
{
	t_max max;

	max.x = x;
	max.y = y;
	max.d = d;
	return (max);
}

t_max	find_square(char **map, t_params params)
{
	int		i;
	int		j;
	int		d;
	t_max	max;

	max = fill_values(0, 0, -1);
	i = -1;
	while (++i < params.l)
	{
		j = -1;
		while (++j < params.c)
		{
			d = get_max_side(j, i, map, params);
			if (d > max.d)
				max = fill_values(j, i, d);
		}
	}
	return (max);
}
