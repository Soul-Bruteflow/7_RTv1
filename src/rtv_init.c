#include "rtv1.h"
#include "rtv1_error.h"
#include "rtv1_support.h"
#include "rtv1_defines.h"
#include "rtv1_constants.h"

t_rtv	*rtv_init(char **av)
{
	t_rtv *rtv_tmp;

//	type *pointer = malloc(num_elems * sizeof(*pointer));

	rtv_tmp = malloc(sizeof(*(rtv_tmp)));
	if (rtv_tmp == NULL)
		rtv_error(malloc_error);

	rtv_tmp->sdl = malloc(sizeof(*(rtv_tmp->sdl)));
	if (rtv_tmp->sdl == NULL)
		rtv_error(malloc_error);

	rtv_tmp->win = malloc(sizeof(*(rtv_tmp->win)));
	if (rtv_tmp->sdl == NULL)
		rtv_error(malloc_error);

	rtv_tmp->calc = malloc(sizeof(*(rtv_tmp->calc)));
	if (rtv_tmp->calc == NULL)
		rtv_error(malloc_error);

	rtv_tmp->scene = malloc(sizeof(*(rtv_tmp->scene)));
	if (rtv_tmp->scene == NULL)
		rtv_error(malloc_error);

	rtv_tmp->av = av;
	rtv_tmp->win->draw_buf = NULL;
	rtv_tmp->win->pitch = 800 * 4;
	rtv_tmp->win->offset = 0;

	return (rtv_tmp);
}