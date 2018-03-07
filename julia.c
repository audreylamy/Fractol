/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:33:52 by alamy             #+#    #+#             */
/*   Updated: 2018/03/07 16:34:23 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init_fractal(t_env *tmp)
{
	tmp->fractal.xmax = 2.4;
	tmp->fractal.xmin = -2.4;
	tmp->fractal.ymax = 1.5;
	tmp->fractal.ymin = -1.5;
}

void init_julia(t_env *tmp)
{
	tmp->julia.cRe = -0.7;
  	tmp->julia.cIm = 0.27015;
	tmp->julia.stop = 0;
}

void ft_create_julia(t_env *tmp)
{
	// double cRe, cIm;           //real and imaginary part of the constant c, determinate shape of the Julia Set
  	double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old
	t_colorrgb rgb;
 	int maxIterations = 200 + tmp->fractal.iter; //after how much iterations the function should stop
	int y;
	int x;
	int i;
	ft_putnbr(maxIterations);
	if (maxIterations == 50)
		tmp->fractal.iter = 0;
	x = 0;
	while(x < WINDOW_L)
	{
		y = 0;
  		while(y < WINDOW_H)
  		{
			newRe = tmp->fractal.xmin + ((tmp->fractal.xmax - tmp->fractal.xmin) / WINDOW_L * x) + tmp->fractal.moveX;
			newIm = tmp->fractal.ymin + ((tmp->fractal.ymax - tmp->fractal.ymin) / WINDOW_H * y) + tmp->fractal.moveY;
			i = 0;	
    		while (i < maxIterations)
   			{
      			oldRe = newRe;
      			oldIm = newIm;
     			newRe = oldRe * oldRe - oldIm * oldIm + tmp->julia.cRe;
     		 	newIm = 2 * oldRe * oldIm + tmp->julia.cIm;
     			if((newRe * newRe + newIm * newIm) > 4) 
				 	break;
				i++;
    		}
			rgb = HSVtoRGB(i % 256 + tmp->c, 1, i < maxIterations);
			fill_pixel(tmp, x, y, createRGBA(rgb.r, rgb.g, rgb.b));
			y++;
		}	
		x++;
	}
}
