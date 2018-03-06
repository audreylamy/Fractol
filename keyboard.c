/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:46:20 by Deydou            #+#    #+#             */
/*   Updated: 2018/03/06 18:33:04 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_redraw_image(t_env *tmp)
{
	mlx_clear_window(tmp->mlx, tmp->win);
	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
	tmp->img.data = (int*)mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp,
	&tmp->img.size_bits, &tmp->img.endian);
	if (tmp->fractal == 1)
		ft_create_julia(tmp);
	else if (tmp->fractal == 2)
		ft_create_mendelbrot(tmp);
	else if (tmp->fractal == 3)
		ft_burn_ship(tmp);
	else if (tmp->fractal == 4)
		ft_create_barnsleyfern(tmp);
	else if (tmp->fractal == 5)
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
	{
		tmp->moveX += 0.01;
		ft_redraw_image(tmp);
	}
	if (keycode == RIGHT)
	{
		tmp->moveX -= 0.01;
		ft_redraw_image(tmp);
	}
	if (keycode == UP)
	{
		tmp->moveY += 0.01;
		ft_redraw_image(tmp);
	}
	if (keycode == DOWN)
	{
		tmp->moveY -= 0.01;
		ft_redraw_image(tmp);
	}
	return (0);
}

