#include "graphics.h"
#include "math.h"
#include <stdio.h>

int	g_rgb_to_color(int r, int g, int b)
{
	int	color;

	color = 0;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	return (color);
}

int	g_hsv_to_color(t_hsv hsv)
{
	double	l;
	double	m;
	double	n;
	double	f;
	int	v;
	int	ti;

	if (hsv.hue == 360.0)
		hsv.hue = 0;
	ti = (int)floor(hsv.hue / 60) % 6;
	f = hsv.hue / 60.0 - ti;
	l = hsv.value * (1.0 - hsv.saturation) * 255;
	m = hsv.value * (1.0 - f * hsv.saturation) * 255;
	n = hsv.value * (1.0 - (1.0 - f) * hsv.saturation) * 255;
	v = hsv.value * 255;
	if (ti == 0)
		return (g_rgb_to_color(v, n, l));
	if (ti == 1)
		return (g_rgb_to_color(m, v, l));
	if (ti == 2)
		return (g_rgb_to_color(l, v, n));
	if (ti == 3)
		return (g_rgb_to_color(l, m, v));
	if (ti == 4)
		return (g_rgb_to_color(n, l, v));
	if (ti == 5)
		return (g_rgb_to_color(v, l, m));
	return (0);
}
