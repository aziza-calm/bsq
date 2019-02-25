/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 20:09:43 by bcharman          #+#    #+#             */
/*   Updated: 2019/02/20 12:29:24 by bcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "ft.h"

char	*create_line(int y, int *len)
{
	char	*s;
	char	*num;
	int		i;

	s = (char*)malloc(sizeof(char) * 4096);
	num = ft_itoa(y);
	i = -1;
	while (num[++i] != '\0')
		s[i] = num[i];
	s[i] = '.';
	s[i + 1] = 'o';
	s[i + 2] = 'x';
	s[i + 3] = '\n';
	*len = i + 4;
	return (s);
}

int		get_random_0_or_1(void)
{
	int r;

	r = rand();
	r = r % 400;
	if (r > 360)
		return (0);
	else
		return (1);
}

void	fill_file(int fd, int x, int y)
{
	int		i;
	int		j;
	char	*line;
	int		len;
	int		num;

	line = create_line(y, &len);
	write(fd, line, len);
	j = -1;
	while (++j < y)
	{
		i = -1;
		while (++i < x)
		{
			num = get_random_0_or_1();
			if (num == 1)
				write(fd, ".", 1);
			else
				write(fd, "o", 1);
		}
		write(fd, "\n", 1);
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	int		x;
	int		y;

	srand(time(NULL));
	if (argc == 3)
	{
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
		fd = open("example1", O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
		fill_file(fd, x, y);
		close(fd);
	}
}
