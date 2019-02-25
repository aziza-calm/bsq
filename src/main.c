/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:23:14 by bcharman          #+#    #+#             */
/*   Updated: 2019/02/19 22:34:02 by aharlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_call(int fd)
{
	char		**map;
	t_params	params;
	t_max		max;

	params.e = 'i';
	params.o = 'i';
	params.f = 'i';
	params.c = 1;
	params.l = 1;
	map = reader(fd, &params);
	if (map == 0 || map_is_valid(map, params) == 0)
	{
		write(2, "map error\n", 10);
		return ;
	}
	max = find_square(map, params);
	print_map(map, max, params);
	free(map);
}

int		main(int argc, char **argv)
{
	int			k;
	int			fd;

	k = 0;
	if (argc > 1)
	{
		while (++k < argc)
		{
			fd = open(argv[k], O_RDONLY);
			ft_call(fd);
		}
	}
	else
		ft_call(0);
	return (0);
}
