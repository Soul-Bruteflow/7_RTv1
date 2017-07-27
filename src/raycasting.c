#include "rtv1.h"
#include "objects.h"

void ray_cast(t_rtv *rtv)
{
	Uint16 i;
	Uint16 j;
	i = 0;

	t_rgba tmp_color;
	tmp_color.red = 200;
	tmp_color.green = 0;
	tmp_color.blue = 0;
	tmp_color.alpha = SDL_ALPHA_OPAQUE;

	while (i < rtv->win->height)
	{
		j = 0;
		rtv->scene->ray->start.y = i;
		while (j < rtv->win->width)
		{
			rtv->scene->obj[0]->hit = intersect_sphere(rtv->scene->ray, rtv->scene->obj[0]->sphere);
//			rtv->scene->obj[1]->hit = intersect_plane_ray(rtv->scene->ray, rtv->scene->obj[1]->plane);
			if(rtv->scene->obj[0]->hit)
				draw_pixel(i, j, &tmp_color, rtv);
//			if(rtv->scene->obj[1]->hit)
//				draw_pixel(i, j, &tmp_color, rtv);
//				printf("++");
//			else
//				printf("--");
			rtv->scene->ray->start.x = j;
			j++;
		}
//		printf("\n");
		i++;
	}
}