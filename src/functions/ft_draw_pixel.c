#include "rtv1.h"
#include "rtv1_defines.h"

/*
** 0 - blue, 1 - green, 2 - red, 3 - alpha;
*/
void	ft_draw_pixel(Uint16 x, Uint16 y, t_rgba *color, Uint8 *draw_buffer)
{
	Uint32	offset;

	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		offset = (Uint32)((WIDTH * 4 * y) + x * 4);
		draw_buffer[offset + 0] = color->blue;
		draw_buffer[offset + 1] = color->green;
		draw_buffer[offset + 2] = color->red;
		draw_buffer[offset + 3] = color->alpha;
	}
}