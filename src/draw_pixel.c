#include <rtv1.h>

void	draw_pixel(Uint16 x, Uint16 y, t_rgba *color, t_rtv *rtv)
{
	Uint32	offset;

	offset = (Uint32)((rtv->win->width * 4 * y) + x * 4);
	rtv->win->draw_buf[offset + 0] = color->b;		// b
	rtv->win->draw_buf[offset + 1] = color->g;		// g
	rtv->win->draw_buf[offset + 2] = color->r;		// r
	rtv->win->draw_buf[offset + 3] = color->a;		// a
}