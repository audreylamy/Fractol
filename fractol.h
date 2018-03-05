/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:49:43 by alamy             #+#    #+#             */
/*   Updated: 2018/03/05 18:09:46 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WINDOW_L 1500
# define WINDOW_H 1200
# define PI 3.14159265359

# include "minilibx/mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

# define EXIT 53
# define RESET 49
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125

# define ZOOM_UP 69
# define ZOOM_DOWN 78
# define ZOOM_Z_UP 92
# define ZOOM_Z_DOWN 85
# define ALL_COLOR 8
# define COLOR_RED 15
# define COLOR_BLUE 5
# define COLOR_GREEN 11

# define SCROLL_UP 4
# define SCROLL_DOWN 5

typedef struct	s_colorrgb
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}				t_colorrgb;

typedef struct	s_colorhsv
{
	double		h;
	double		s;
	double		v;
}				t_colorhsv;

typedef struct	s_img
{
	void	*img_ptr;
	char	*data;
	int		bpp;
	int		size_bits;
	int		endian;
	int		color;
}				t_img;

typedef struct	s_env
{
	void	*mlx;
	void	*win;
	t_img	img;
	float 	moveX;
	float 	moveY;
	int		zoom_f;
}				t_env;

int				main(int argc, char **argv);
void			ft_create_image(t_env *tmp, char *str);
void 			ft_create_julia(t_env *tmp);
void			ft_create_mendelbrot(t_env *tmp);
void			ft_burn_ship(t_env *tmp);
void			ft_create_tricorn(t_env *tmp);
void			ft_create_barnsleyfern(t_env *tmp);
void			fill_pixel(t_env *t, int x, int y, int color);
void			fill_pixel_julia(t_env *t, int x, int y, t_colorrgb color);
int				my_key_funct(int keycode, t_env *tmp);
t_colorrgb		HSVtoRGB(double r, double g, double b);

void			ft_redraw_image(t_env *tmp);

#endif
