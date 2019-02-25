/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcharman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 17:47:54 by bcharman          #+#    #+#             */
/*   Updated: 2019/02/20 12:25:08 by bcharman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_params
{
	char		e;
	char		o;
	char		f;
	int			l;
	int			c;
}				t_params;
typedef struct	s_max
{
	int			x;
	int			y;
	int			d;
}				t_max;
int				ft_atoi(char *str);
t_max			find_square(char **map, t_params params);
int				get_max_side(int x, int y, char **map, t_params params);
t_params		*read_1st_line(int fd, t_params *params);
char			*anlinie(int fd, char *str, int *nc);
char			**reader(int fd, t_params *params);
void			print_map(char **map, t_max max, t_params params);
int				map_is_valid(char **map, t_params params);
int				get_num_of_digits(int num);
char			*ft_itoa(int n);
int				ft_strlen(char *str);

#endif
