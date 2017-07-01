#include "rtv1.h"
#include "rtv_error.h"
#include "rtv1_defines.h"

t_rtv	*rtv_init(char **errors, char **av)
{
	t_rtv *rtv_tmp;

	rtv_tmp = malloc(sizeof(*(rtv_tmp)));
	if (rtv_tmp == NULL)
		rtv_error(malloc_error, errors);
	rtv_tmp->sdl = malloc(sizeof(*(rtv_tmp->sdl)));
	if (rtv_tmp->sdl == NULL)
		rtv_error(malloc_error, errors);
	rtv_tmp->sdl->draw_buffer = NULL;
	wolf->av = av;
	wolf->pitch = 800 *4;
	wolf->offset = 0;
}