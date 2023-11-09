/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 12:38:43 by fptacek           #+#    #+#             */
/*   Updated: 2023/10/26 12:39:06 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	malloc_error(void)
{
	perror("Malloc issue");
	exit(EXIT_FAILURE);
}

void	data_init(t_fractal *fractal)
{
	fractal->nbr_of_iter = 100;
	fractal->escaped_value = 4;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->zoom = 1.0;
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->win_ptr, ButtonPress, \
			ButtonPressMask, mouse_handler, fractal);
	mlx_hook(fractal->win_ptr, DestroyNotify, \
			StructureNotifyMask, close_handler, fractal);
}

void	init(t_fractal *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (fractal->mlx_ptr == NULL)
		malloc_error();
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, \
			X_SIZE, Y_SIZE, fractal->name);
	if (fractal->win_ptr == NULL)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, X_SIZE, Y_SIZE);
	if (fractal->img.img_ptr == NULL)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}
	fractal->img.addr = mlx_get_data_addr(fractal->img.img_ptr, \
			&fractal->img.bpp, &fractal->img.line_lenght, &fractal->img.endian);
	events_init(fractal);
	data_init(fractal);
}
