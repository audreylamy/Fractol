/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:46:20 by Deydou            #+#    #+#             */
/*   Updated: 2018/03/07 16:54:35 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#

void	ft_redraw_image(t_env *tmp)
{
	mlx_clear_window(tmp->mlx, tmp->win);
	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
	tmp->img.data = (int*)mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp,
	&tmp->img.size_bits, &tmp->img.endian);
	if (tmp->num_f == 1)
		ft_create_julia(tmp);
	else if (tmp->num_f == 2)
		ft_create_mandelbrot(tmp);
	else if (tmp->num_f == 3)
		ft_burn_ship(tmp);
	else if (tmp->num_f == 4)
		ft_create_barnsleyfern(tmp);
	else if (tmp->num_f == 5)
		ft_create_tricorn(tmp);
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img_ptr, 0, 0);
}

int		my_key_funct(int keycode, t_env *tmp)
{
	if (keycode == EXIT)
	{
		mlx_destroy_image(tmp->mlx, tmp->img.img_ptr);
		exit(1);
	}
	if (keycode == LEFT)
		tmp->fractal.moveX += 0.1;
	else if (keycode == RIGHT)
		tmp->fractal.moveX -= 0.1;
	else if (keycode == UP)
		tmp->fractal.moveY += 0.1;
	else if (keycode == DOWN)
		tmp->fractal.moveY -= 0.1;
	else if (keycode == ITER_UP)
		tmp->fractal.iter += 50;
	else if (keycode == ITER_DOWN)
		tmp->fractal.iter -= 50;
	else if (keycode == COLOR_UP)
		tmp->c += 5;
	else if (keycode == COLOR_DOWN)
		tmp->c -= 5;
	else if (keycode == STOP)
	{
		 if (tmp->julia.stop == 0)
            tmp->julia.stop = 1;
        else if (tmp->julia.stop == 1)
            tmp->julia.stop = 0;
	}
	else if (keycode == JULIA)
	{
		init_julia(tmp);
		tmp->num_f = 1;
	}
	else if (keycode == MANDELBROT)
		tmp->num_f = 2;
	else if (keycode == BURNSHIP)
		tmp->num_f = 3;
	else if (keycode == BARNSLEY)
		tmp->num_f = 4;
	else if (keycode == TRICORN)
		tmp->num_f = 5;
	ft_redraw_image(tmp);
	return (0);
}

