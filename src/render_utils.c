/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:09:02 by fptacek           #+#    #+#             */
/*   Updated: 2023/10/26 17:09:06 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	map(double unscaled_num, double new_min, \
		double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num) / \
			(old_max) + new_min);
}

void	my_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + ((y * img->line_lenght) + (x * (img->bpp / 8)));
	*(unsigned int *)dst = color;
}

void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *farcatal)
{
	if (!ft_strncmp(farcatal->name, "julia", 5))
	{
		c->real = farcatal->julia_x;
		c->img = farcatal->julia_y;
	}
	else
	{
		c->real = z->real;
		c->img = z->img;
	}
}
