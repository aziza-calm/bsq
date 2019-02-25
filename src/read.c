/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:37:58 by bcharman          #+#    #+#             */
/*   Updated: 2019/02/19 23:27:51 by aharlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_params		*read_1st_line(int fd, t_params *params)
{
	char		*line;
	int			len;
	int			start;

	line = (char*)malloc(4096);
	line = anlinie(fd, line, &len);
	params->l = ft_atoi(line);
	start = ft_strlen(ft_itoa(params->l));
	params->e = line[start];
	params->o = line[start + 1];
	params->f = line[start + 2];
	params->c = fd;
	return (params);
}

char			*anlinie(int fd, char *str, int *nc)
{
	int		j;
	char	c;
	int		ret;

	str = (char*)malloc(4096);
	ret = 1;
	*nc = 0;
	c = '0';
	j = -1;
	while (ret != 0 && c != '\n')
	{
		ret = read(fd, &c, 1);
		if (c != '\n')
			(*nc)++;
		str[++j] = c;
	}
	return (str);
}

int				extra(int fd)
{
	char	c;
	int		ret;

	if (fd == 0)
		return (0);
	ret = read(fd, &c, 1);
	if (ret == 1)
		return (1);
	return (0);
}

char			**reader(int fd, t_params *params)
{
	char		**map;
	int			i;
	int			j;

	params = read_1st_line(fd, params);
	fd = params->c;
	map = (char**)malloc(params->l * sizeof(*map));
	j = -1;
	while (++j < params->l)
	{
		map[j] = anlinie(fd, map[j], &params->c);
		if (j == 0)
			i = params->c;
		if (params->c != i || params->c == 0)
			return (0);
	}
	if (extra(fd))
		return (0);
	close(fd);
	return (map);
}
