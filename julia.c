/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:15:55 by Deydou            #+#    #+#             */
/*   Updated: 2018/03/06 18:18:41 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fractal(t_env *tmp)
{
	tmp->xmax = 2.4;
	tmp->xmin = -2.4;
	tmp->ymax = 1.5;
	tmp->ymin = -1.5;
}

void ft_create_julia(t_env *tmp)
{
	double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
  	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
  	// double zoom = 1; //you can change these to zoom and change position
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
   			// newRe = 1.5 * (x - WINDOW_L/ 2) / (0.5 * (zoom + tmp->zoom_f) * WINDOW_L) + (0 + tmp->moveX);
   	 		// newIm = (y - WINDOW_H / 2) / (0.5 * (zoom + tmp->zoom_f) * WINDOW_H) + (0 + tmp->moveY);
			newRe = tmp->xmin + ((tmp->xmax - tmp->xmin) / WINDOW_L * x) + tmp->moveX;
			newIm = tmp->ymin + ((tmp->ymax - tmp->ymin) / WINDOW_H * y) + tmp->moveY;
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
			rgb = HSVtoRGB(i % 256, 1, i < maxIterations);
			fill_pixel(tmp, x, y, createRGBA(rgb.r, rgb.g, rgb.b));
			y++;
		}	
		x++;
	}
}
