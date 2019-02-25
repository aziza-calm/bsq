/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:33:49 by bcharman          #+#    #+#             */
/*   Updated: 2019/02/19 20:41:40 by bcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	print_map(char **map, t_max max, t_params params)
{
	int i;
	int j;

	j = -1;
	while (++j < params.l)
	{
		i = -1;
		while (++i <= params.c)
		{
			if (j >= max.y && j <= max.y + max.d &&
				i >= max.x && i <= max.x + max.d)
				write(1, &(params.f), 1);
			else
				write(1, &map[j][i], 1);
		}
	}
}
