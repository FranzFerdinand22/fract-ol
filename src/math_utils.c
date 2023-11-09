/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 15:42:50 by fptacek           #+#    #+#             */
/*   Updated: 2023/10/26 15:42:56 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, \
		double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num) / \
			(old_max) + new_min);
}

t_complex	sqrt_complex(t_complex num)
{
	t_complex	res;

	res.real = (num.real * num.real) - (num.img * num.img);
	res.img = 2 * num.real * num.img;
	return (res);
}

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	sum;

	sum.real = a.real + b.real;
	sum.img = a.img + b.img;
	return (sum);
}
