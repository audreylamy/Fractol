/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:59:39 by alamy             #+#    #+#             */
/*   Updated: 2018/03/06 18:44:38 by alamy            ###   ########.fr       */
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
     tmp->xmin = interpolate(mouseRe, tmp->xmin, interpolation);
     tmp->ymin = interpolate(mouseIm, tmp->ymin, interpolation);
     tmp->xmax = interpolate(mouseRe, tmp->xmax, interpolation);
     tmp->ymax = interpolate(mouseIm, tmp->ymax, interpolation);
}

int		my_mouse_funct(int button, int x, int y, t_env *tmp)
{
	double mouseRe;
	double mouseIm;
	
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
	mouseRe = (double)x / (WINDOW_L / (tmp->xmax - tmp->xmin)) + tmp->xmin;
	mouseIm = (double)y / (WINDOW_H / (tmp->ymax - tmp->ymin)) + tmp->ymin;
	if (button == CLIC_LEFT)
	{
		t_zoom(tmp, mouseRe, mouseIm, 2);
	}
	ft_redraw_image(tmp);
	return (0);
}
