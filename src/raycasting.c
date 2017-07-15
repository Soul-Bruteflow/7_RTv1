#include "rtv1.h"
#include "objects.h"

void ray_cast(t_rtv *rtv)
{
	int i;
	int j;
	i = 0;
	while (i < rtv->win->height)
	{
		j = 0;
		rtv->scene->ray->start.y = i;
		while (j < rtv->win->width)
		{
			rtv->scene->obj[0]->hit = intersect_sphere(rtv->scene->ray, rtv->scene->obj[0]->sphere);
			if(rtv->scene->obj[0]->hit)
				printf("++");
			else
				printf("--");
			rtv->scene->ray->start.x = j;
			j++;
		}
		printf("\n");
		i++;
	}
}