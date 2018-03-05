/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Deydou <Deydou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:46:20 by Deydou            #+#    #+#             */
/*   Updated: 2018/02/20 15:47:07 by Deydou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		my_key_funct(int keycode, t_env *tmp)
{
	if (keycode == EXIT)
	{
		mlx_destroy_image(tmp->mlx, tmp->img.img_ptr);
		exit(1);
	}
	return (0);
}