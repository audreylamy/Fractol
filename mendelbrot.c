/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mendelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 15:21:25 by Deydou            #+#    #+#             */
/*   Updated: 2018/03/06 18:24:30 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_create_mendelbrot(t_env *tmp)
{
	double pr, pi;           //real and imaginary part of the pixel p
  	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
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
   			pr = tmp->xmin + ((tmp->xmax - tmp->xmin) / WINDOW_L * x) + tmp->moveX;
    		pi = tmp->ymin + ((tmp->ymax - tmp->ymin) / WINDOW_H * y) + tmp->moveY;
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
			fill_pixel(tmp, x, y, createRGBA(rgb.r, rgb.g, rgb.b));
			y++;
		}
		x++;
    }
}
