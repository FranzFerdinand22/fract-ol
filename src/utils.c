/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:54:11 by fptacek           #+#    #+#             */
/*   Updated: 2023/10/26 16:55:22 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	while ((*s1 == *s2) && *s1 && *s2 && i < n)
	{
		s1++;
		s2++;
		i++;
	}
	return (*s1 - *s2);
}

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s)
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

long	int_part(long num, int minus, char *str)
{
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (*str != '.' && *str)
	{
		num = (num * 10) + (*str - '0');
		str++;
	}
	return (num * minus);
}

double	fract_part(double num, double pow, char *str)
{
	while (*str != '.' && *str)
		str++;
	if (*str == '.')
		str++;
	while (*str)
	{
		pow /= 10;
		num = num + (*str - '0') * pow;
		str++;
	}
	return (num);
}

// takes cmd line args and converts to long double
double	ft_atodbl(char *str)
{
	long	int_part_value;
	double	fract_part_value;
	double	pow;

	pow = 1;
	int_part_value = 0;
	fract_part_value = 0;
	int_part_value = int_part(0, 1, str);
	fract_part_value = fract_part(0, pow, str);
	return (int_part_value + fract_part_value);
}
