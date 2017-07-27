#include <rtv1.h>

void	draw_pixel(Uint16 x, Uint16 y, t_rgba *color, t_rtv *rtv)
{
	Uint32	offset;

	if (x >= 0 && x <= rtv->win->width && y >= 0 && y <= rtv->win->height)
	{
		offset = (Uint32)((rtv->win->width * 4 * y) + x * 4);
		rtv->win->draw_buf[offset + 0] = color->blue;		// b
		rtv->win->draw_buf[offset + 1] = color->green;		// g
		rtv->win->draw_buf[offset + 2] = color->red;		// r
		rtv->win->draw_buf[offset + 3] = color->alpha;		// a
	}
}