/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franta <franta@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 11:54:17 by fptacek           #+#    #+#             */
/*   Updated: 2023/10/24 18:05:42 by franta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// 	int (*f)(void *param)
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
}

// 	int (*f)(int keycode, void *param)
int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.1 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.1 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y += (0.1 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y -= (0.1 * fractal->zoom);
	else if (keysym == XK_Page_Up)
		fractal->nbr_of_iter += 10;
	else if (keysym == XK_Page_Down)
		fractal->nbr_of_iter -= 10;
	fractal_render(fractal);
	return (0);
}

// int (*f)(int button, int x, int y, void *param)
int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == Button5)
		fractal->zoom *= 0.90;
	else if (button == Button4)
		fractal->zoom *= 1.10;
	fractal_render(fractal);
	return (0);
}
