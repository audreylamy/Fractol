/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:09:40 by alamy             #+#    #+#             */
/*   Updated: 2018/03/07 13:40:41 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_create_image(t_env *tmp, char *str)
{
	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
	tmp->img.data = (int*)mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp,
	&tmp->img.size_bits, &tmp->img.endian);
	init_fractal(tmp);
	if (ft_strcmp(str, "julia") == 0)
	{
		tmp->fractal = 1;
		ft_create_julia(tmp);
	}
	else if (ft_strcmp(str, "mandelbrot") == 0)
	{
		tmp->fractal = 2;
		ft_create_mandelbrot(tmp);
	}
	else if (ft_strcmp(str, "burnship") == 0)
	{
		tmp->fractal = 3;
		ft_burn_ship(tmp);
	}
	else if (ft_strcmp(str, "barnsley") == 0)
	{
		tmp->fractal = 4;
		ft_create_barnsleyfern(tmp);
	}
	else if (ft_strcmp(str, "tricorn") == 0)
	{
		tmp->fractal = 5;
		ft_create_tricorn(tmp);
	}
	else
	{
		ft_putstr("usage: ./fractol [julia | mandelbrot | burnship | tricorn | barnsley]");
		exit(0);
	}
	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img_ptr, 0, 0);
}

int	main(int argc, char **argv)
{
	t_env tmp;

	if (argc != 2)
	{
		ft_putstr("usage: ./fractol [julia | mandelbrot | burnship | tricorn | barnsley]");
		exit(0);
	}
	else
	{
		tmp.mlx = mlx_init();
		tmp.win = mlx_new_window(tmp.mlx, WINDOW_L, WINDOW_H, "mlx 42");
		ft_create_image(&tmp, argv[1]);
		mlx_hook(tmp.win, 2, 0, my_key_funct, &tmp.mlx);
		mlx_hook(tmp.win, 4, 0, my_mouse_funct, &tmp.mlx);
		// mlx_hook(tmp.win, 6, 0, my_motion_hook, &tmp.mlx);
		mlx_loop(tmp.mlx);
	}
	return (0);
}
