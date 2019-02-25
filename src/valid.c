/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:46:50 by bcharman          #+#    #+#             */
/*   Updated: 2019/02/19 22:49:08 by aharlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	map_is_valid(char **map, t_params params)
{
	int i;
	int j;

	j = -1;
	while (++j < params.l)
	{
		i = -1;
		while (++i < params.c)
		{
			if (map[j][i] != params.e && map[j][i] != params.o)
				return (0);
		}
	}
	return (1);
}
