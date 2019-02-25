/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aharlaw <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 20:32:20 by aharlaw           #+#    #+#             */
/*   Updated: 2019/02/19 23:49:16 by aharlaw          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		get_num_of_digits(int num)
{
	int c;

	c = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num = num / 10;
		c++;
	}
	return (c);
}

char	get_digit(int n)
{
	if (n > 0)
		return ('0' + (n % 10));
	else
		return ('0' + (-1 * (n % 10)));
}

char	*ft_itoa(int n)
{
	int		digits;
	int		sign;
	char	*ret;

	if (n < 0)
		sign = 1;
	else
		sign = 0;
	digits = get_num_of_digits(n);
	ret = (char*)malloc(sizeof(char) * (digits + sign + 1));
	ret[digits + sign] = '\0';
	if (sign)
		ret[0] = '-';
	else if (n > 0)
		digits--;
	else
		ret[0] = '0';
	while (n)
	{
		ret[digits] = get_digit(n);
		n = n / 10;
		digits--;
	}
	return (ret);
}
