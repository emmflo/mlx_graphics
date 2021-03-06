/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eflorenz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 19:25:17 by eflorenz          #+#    #+#             */
/*   Updated: 2018/01/10 19:25:28 by eflorenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"
#include <math.h>
#include <stdlib.h>

#include <stdio.h>

void	g_rect_fill(t_img *img, t_rect_int rect, int color)
{
	t_point_int	pt;

	pt.x = rect.x;
	while (pt.x < rect.x + rect.w)
	{
		pt.y = rect.y;
		while (pt.y < rect.y + rect.h)
		{
			g_put_pixel(img, pt, color);
			pt.y++;
		}
		pt.x++;
	}
}

void	g_rect_fill_lerp(t_img *img, t_rect_int rect, t_gradient color)
{
	t_point_int	pt;
	t_point_int	real_pt;

	pt.x = 0;
	while (pt.x < rect.w)
	{
		pt.y = 0;
		real_pt.x = pt.x + rect.x;
		while (pt.y < rect.h)
		{
			real_pt.y = pt.y + rect.y;
			g_put_pixel(img, real_pt, lerp_rbg(color, (double)pt.x / (double)rect.w));
			pt.y++;
		}
		pt.x++;
	}
}

void	g_rect_hue_gradient(t_img *img, t_rect_int rect)
{
	t_point_int	pt;
	t_point_int	real_pt;
	t_hsv		color;
	int		rgb;

	pt.x = 0;
	while (pt.x < rect.w)
	{
		pt.y = 0;
		color.hue = (double)pt.x * 360 / (double)rect.w;
		color.saturation = 1;
		color.value = 1;
		rgb = g_hsv_to_color(color);
		real_pt.x = pt.x + rect.x;
		while (pt.y < rect.h)
		{
			real_pt.y = pt.y + rect.y;
			g_put_pixel(img, real_pt, rgb);
			pt.y++;
		}
		pt.x++;
	}
}

void	g_rect_hsv_gradient(t_img *img, t_rect_int rect, double hue)
{
	t_point_int	pt;
	t_point_int	real_pt;
	t_hsv		color;

	pt.x = 0;
	while (pt.x < rect.w)
	{
		pt.y = 0;
		real_pt.x = pt.x + rect.x;
		while (pt.y < rect.h)
		{
			color.hue = hue;
			color.saturation = (double)pt.x / (double)rect.w;
			color.value = (double)(rect.h - pt.y) / (double)rect.h;
			real_pt.y = pt.y + rect.y;
			g_put_pixel(img, real_pt, g_hsv_to_color(color));
			pt.y++;
		}
		pt.x++;
	}
}

void	g_img_fill(t_img *img, int color)
{
	t_rect_int	rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = img->width;
	rect.h = img->height;
	g_rect_fill(img, rect, color);
}

void	g_window_fill(t_window *win, int color)
{
	t_img		*screen;

	screen = win->img_next;
	g_img_fill(screen, color);
}
