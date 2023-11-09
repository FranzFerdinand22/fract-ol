/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fptacek <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:09:16 by fptacek           #+#    #+#             */
/*   Updated: 2023/10/26 17:09:21 by fptacek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// libraries
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

// variables
# define ERROR_INPUT "Wrong input"
# define X_SIZE 800
# define Y_SIZE 800

// colors
# define BLACK      0x000000
# define WHITE      0xFFFFFF
# define RED        0xFF0000
# define GREEN      0x00FF00
# define BLUE       0x0000FF
# define YELLOW     0xFFFF00
# define CYAN       0x00FFFF
# define MAGENTA    0xFF00FF
# define ORANGE     0xFFA500
# define PURPLE     0x800080
# define PINK       0xFFC0CB
# define TEAL       0x008080
# define LIME       0x00FF00
# define GOLD       0xFFD700
# define VIOLET     0xEE82EE
# define TURQUOISE  0x40E0D0
# define PLUM       0xDDA0DD
# define CORAL      0xFF6F61

// complex numbers
typedef struct s_complex
{
	double	real;
	double	img;
}	t_complex;

// image
typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_lenght;
	int		endian;
}	t_image;

// fractal
typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	int		nbr_of_iter;
	double	escaped_value;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	t_image	img;
}	t_fractal;

// init
void	init(t_fractal *fractal);
void	malloc_error(void);
void	data_init(t_fractal *fractal);
void	evenst_init(t_fractal *fractal);

// utils
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	putstr_fd(char *s, int fd);
double	ft_atodbl(char *str);

// math utils
double	map(double unscaled_num, double new_min, \
		double new_max, double old_max);
/* t_complex	sqrt_complex(t_complex num);
t_complex	sum_complex(t_complex a, t_complex b); */

// render
void	my_pixel_put(t_image *img, int x, int y, int color);
void	handle_pixel(int x, int y, t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *farcatal);

// events
int		key_handler(int keysym, t_fractal *fractal);
int		close_handler(t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif
