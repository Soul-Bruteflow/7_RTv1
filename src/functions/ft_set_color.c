#include "rtv.h"

t_rgbap		ft_set_color(float r, float g, float b, float a)
{
	t_rgbap tmp;

	tmp.red = r;
	tmp.green = g;
	tmp.blue = b;
	tmp.alpha = a;
	return (tmp);
}