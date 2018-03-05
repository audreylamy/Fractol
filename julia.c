/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:15:55 by Deydou            #+#    #+#             */
/*   Updated: 2018/03/05 16:57:33 by alamy            ###   ########.fr       */
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

	if (s == 0)
	{
		r = v;
		g = v;
		b = v;
	}
	else
	{
		int i;
		double f, p, q, t;

		if (h == 360)
			h = 0;
		else
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

void ft_create_julia(t_env *tmp)
{
	double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
  	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
  	double zoom = 1, moveX = 0, moveY = 0; //you can change these to zoom and change position
 	//int color = 0x00FFFF; //the RGB color value for the pixel
	t_colorrgb rgb;
 	int maxIterations = 300; //after how much iterations the function should stop
	int y;
	int x;
	int i;

	// cRe = -0.038088;
  	// cIm = 0.97;

	// cRe = -1.417022285618;
  	// cIm = 0;

	// cRe = 0.285;
  	// cIm = 0.013;
	
	// cRe = 0.285;
  	// cIm = 0.01;

	// cRe = 0.3;
  	// cIm = 0.5;

  	cRe = -0.7;
  	cIm = 0.27015;

	x = 0;
	while(x < WINDOW_L)
	{
		y = 0;
  		while(y < WINDOW_H)
  		{
   			newRe = 1.5 * (x - WINDOW_L/ 2) / (0.5 * zoom * WINDOW_L) + moveX;
   	 		newIm = (y - WINDOW_H / 2) / (0.5 * zoom * WINDOW_H) + moveY;
			i = 0;	
    		while (i < maxIterations)
   			{
      			oldRe = newRe;
      			oldIm = newIm;
     			newRe = oldRe * oldRe - oldIm * oldIm + cRe;
     		 	newIm = 2 * oldRe * oldIm + cIm;
     			if((newRe * newRe + newIm * newIm) > 4) 
				 	break;
				i++;
    		}
			rgb = HSVtoRGB(i % 286, 1, i < maxIterations);
			fill_pixel_julia(tmp, x, y, rgb);
			y++;
		}	
		x++;
	}
}
