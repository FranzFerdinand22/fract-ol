/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:08:48 by fptacek           #+#    #+#             */
/*   Updated: 2023/10/26 17:08:51 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_complex	sqrt_complex(t_complex num)
{
	t_complex	res;

	res.real = (num.real * num.real) - (num.img * num.img);
	res.img = 2 * num.real * num.img;
	return (res);
}

static t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	sum;

	sum.real = a.real + b.real;
	sum.img = a.img + b.img;
	return (sum);
}

/* 
	 ------------------------------------------------
	|	Manderlbrot:								 |
	|		z = z^2 + c; => Z(n + 1) = (Z(n))^2 + c; |
	|		run -> /.farctol mandelbrot				 |
	 ------------------------------------------------
	|	Julia:										 |
	|		z = pixel_point + constant;				 |
	|		run -> ./fractol julia <real> <img>		 |
	 ------------------------------------------------
*/

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	int			i;
	int			color;
	t_complex	z;
	t_complex	c;

	i = 0;
	z.real = (map(x, -2, 2, X_SIZE) * fractal->zoom) + fractal->shift_x;
	z.img = (map(y, 2, -2, Y_SIZE) * fractal->zoom) + fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	while (i < fractal->nbr_of_iter)
	{
		z = sqrt_complex(z);
		z = sum_complex(z, c);
		if ((z.real * z.real) + (z.img * z.img) > fractal->escaped_value)
		{
			color = map(i, BLACK, WHITE, fractal->nbr_of_iter);
			my_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		++i;
	}
	my_pixel_put(&fractal->img, x, y, BLACK);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < Y_SIZE)
	{
		x = -1;
		while (++x < X_SIZE)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, \
			fractal->img.img_ptr, 0, 0);
}
