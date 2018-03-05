/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:23:18 by alamy             #+#    #+#             */
/*   Updated: 2018/03/05 18:28:50 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void fill_pixel_julia(t_env *t, int x, int y, t_colorrgb rgbcolor)
{	
 	//((int*)tmp->img.data)[(y * WINDOW_L) + x] = color;

	if (x >= 0 && y >= 0 && x < WINDOW_L && y < WINDOW_H)
	{
		t->img.data[y * t->img.size_bits + x * t->img.bpp / 8] = rgbcolor.r;
		t->img.data[y * t->img.size_bits + x * t->img.bpp / 8 + 1] = rgbcolor.g;
		t->img.data[y * t->img.size_bits + x * t->img.bpp / 8 + 2] = rgbcolor.b;
	}
}

t_colorrgb HSVtoRGB(double h, double s, double v)
{
	t_colorrgb rgb;
	double r = 0, g = 0, b = 0;
	int i;
	double f, p, q, t;
	while (h < 0) { h += 360; };
  	while (h >= 360) { h -= 360; };
	if (s <= 0)
	{
		r = v;
		g = v;
		b = v;
	}
	else
	{
		h = h / 60;
		i = (int)trunc(h);
		f = h - i;
		p = v * (1.0 - s);
		q = v * (1.0 - (s * f));
		t = v * (1.0 - (s * (1.0 - f)));
		switch (i)
		{
		case 0:
			r = v;
			g = t;
			b = p;
			break;

		case 1:
			r = q;
			g = v;
			b = p;
			break;

		case 2:
			r = p;
			g = v;
			b = t;
			break;

		case 3:
			r = p;
			g = q;
			b = v;
			break;

		case 4:
			r = t;
			g = p;
			b = v;
			break;

		case 5:
        	r = v;
        	g = p;
       		b = q;
        break;

		case 6:
        	r = v;
        	g = t;
        	b = p;
        break;

		default:
			r = v;
			g = p;
			b = q;
			break;
		}
	}
	rgb.r = r * 255;
	rgb.g = g * 255;
	rgb.b = b * 255;
	return rgb;
}
