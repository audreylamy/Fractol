/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:59:39 by alamy             #+#    #+#             */
/*   Updated: 2018/03/08 14:06:46 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double interpolate(double start, double end, double interpolation)
{
    return start + ((end - start) * interpolation);
}

void t_zoom(t_env* tmp, double mouseRe, double mouseIm, double zoom_factor)
{
	double interpolation = 1.0 / zoom_factor;
     tmp->fractal.xmin = interpolate(mouseRe, tmp->fractal.xmin, interpolation);
     tmp->fractal.ymin = interpolate(mouseIm, tmp->fractal.ymin, interpolation);
     tmp->fractal.xmax = interpolate(mouseRe, tmp->fractal.xmax, interpolation);
     tmp->fractal.ymax = interpolate(mouseIm, tmp->fractal.ymax, interpolation);
}

int		my_mouse_funct(int button, int x, int y, t_env *tmp)
{
	double mouseRe;
	double mouseIm;
	
	mouseRe = (double)x / (WINDOW_L / (tmp->fractal.xmax - tmp->fractal.xmin)) + tmp->fractal.xmin;
	mouseIm = (double)y / (WINDOW_H / (tmp->fractal.ymax - tmp->fractal.ymin)) + tmp->fractal.ymin;
	if (button == CLIC_LEFT)
	{
		t_zoom(tmp, mouseRe, mouseIm, 2);
	}
	if (button == CLIC_RIGHT)
	{
		t_zoom(tmp, mouseRe, mouseIm, 0.5);
	}
	if (button == SCROLL_UP)
	{
		t_zoom(tmp, mouseRe, mouseIm, 2);
	}
	if (button == SCROLL_DOWN)
	{
		t_zoom(tmp, mouseRe, mouseIm, 0.5);
	}
	if (button == 8)
	{
		t_zoom(tmp, mouseRe, mouseIm, 0.5);
	}
	ft_redraw_image(tmp);
	return (0);
}

int		my_motion_hook(int x, int y, t_env *tmp)
{
	int largeur;

	y = 0;
	largeur = WINDOW_L/2;
	if (x >= 0 && y >= 0 && x <= WINDOW_L && y <= WINDOW_H && tmp->fractal.stop != 1)
	{
		if (x > 0 && x < largeur)
		{
			tmp->julia.cRe -= 0.05;
			tmp->julia.cIm -= 0.05;
		}
		else if (x > largeur && x < WINDOW_L)
		{
			tmp->julia.cRe += 0.05;
			tmp->julia.cIm += 0.05;
		}
	}
	ft_redraw_image(tmp);
	return(0);
}