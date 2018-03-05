/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:21:25 by Deydou            #+#    #+#             */
/*   Updated: 2018/03/05 16:55:25 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fill_pixel(t_env *tmp, int x, int y, int color)
{	
 	((int*)tmp->img.data)[(y * WINDOW_L) + x] = color;
}

unsigned long createRGBA(int r, int g, int b, int a)
{   
    return ((r & 0xff) << 24) + ((g & 0xff) << 16) + ((b & 0xff) << 8)
           + (a & 0xff);
}

void ft_create_mendelbrot(t_env *tmp)
{
	double pr, pi;           //real and imaginary part of the pixel p
  	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
 	double zoom = 1, moveX = -0.5, moveY = 0; //you can change these to zoom and change position
	t_colorrgb rgb;
  	int maxIterations = 300;//after how much iterations the function should stop
	int x;
	int y;
	int i;
	x = 0;
  	while (x < WINDOW_L)
	{
		y = 0;
 		while (y < WINDOW_H)
  		{
   			pr = 1.5 * (x - WINDOW_L / 2) / (0.5 * zoom * WINDOW_L) + moveX;
    		pi = (y - WINDOW_H / 2) / (0.4 * zoom * WINDOW_H) + moveY;
    		newRe = newIm = oldRe = oldIm = 0; 
			i = 0;
    		while (i < maxIterations)
    		{
      			oldRe = newRe;
      			oldIm = newIm;
     
     			newRe = oldRe * oldRe - oldIm * oldIm + pr;
      			newIm = 2 * oldRe * oldIm + pi;
      			if((newRe * newRe + newIm * newIm) > 4) 
				  	break;
				i++;
			}
			rgb = HSVtoRGB(i % 256, 1, i < maxIterations);
			fill_pixel_julia(tmp, x, y, rgb);
			y++;
		}
		x++;
    }
}