/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:08:52 by alamy             #+#    #+#             */
/*   Updated: 2018/03/07 15:40:50 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdlib.h>

void ft_create_tricorn(t_env *tmp)
{
	double pr, pi;           //real and imaginary part of the pixel p
  	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
  	t_colorrgb  rgb;
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
   			pr = tmp->fractal.xmin + ((tmp->fractal.xmax - tmp->fractal.xmin) / WINDOW_L * x) + tmp->fractal.moveX;
    		pi = tmp->fractal.ymin + ((tmp->fractal.ymax - tmp->fractal.ymin) / WINDOW_H * y) + tmp->fractal.moveY;
    		newRe = newIm = oldRe = oldIm = 0; 
			i = 0;
    		while (i < maxIterations)
    		{
      			oldRe = newRe;
      			oldIm = newIm;
     
     			newRe = oldRe * oldRe - oldIm * oldIm + pr;
      			newIm = -2 * oldRe * oldIm + pi;
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
