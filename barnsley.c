/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   barnsley.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:29:37 by alamy             #+#    #+#             */
/*   Updated: 2018/03/07 11:26:33 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>
#include <time.h> 
#include <limits.h>

void ft_create_barnsleyfern(t_env *tmp)
{
	unsigned long iter; // nb iterations
	double x0;
	double y0;
	double x1;
	double y1;
	int		zoom_b;
	int diceThrow;
	t_colorrgb rgb;
	iter = 500000;
	x0 = 0;
	y0 = 0;
	zoom_b = 110;
 
	while(iter > 0)
	{
		diceThrow = rand() % 100;
	
		if (diceThrow == 0)
		{
			x1 = 0;
			y1 = 0.16 * y0;
		}
		else if (diceThrow >= 1 && diceThrow <= 7)
		{
			x1 = -0.15 * x0 + 0.28 * y0;
			y1 = 0.26 * x0 + 0.24 * y0 + 0.44;
		}
		else if (diceThrow >= 8 && diceThrow <= 15)
		{
			x1 = 0.2 * x0 - 0.26 * y0;
			y1 = 0.23 * x0 + 0.22 * y0 + 1.6;
		}
		else
		{
			x1 = 0.85 * x0 + 0.04 * y0;
			y1 = -0.04 * x0 + 0.85 * y0 + 1.6;
		}
		rgb = HSVtoRGB(323, 1, 0.46);
		fill_pixel(tmp, zoom_b * x1 + WINDOW_L / 2.0, zoom_b * y1, createRGBA(rgb.r, rgb.g, rgb.b));
		x0 = x1;
		y0 = y1;
		iter--;
	}
 
}
 