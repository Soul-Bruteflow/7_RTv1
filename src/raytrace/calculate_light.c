#include "rtv.h"

t_bool calculate_shadows(t_obj3d **objects, t_ray *light_ray, float *t2)
{
	int k;

	k = -1;
	while (k++ < 2)
	{
		if (objects[k]->intersect(light_ray, objects[k], t2))
		{
			return (true);
		}
	}
	return (false);
}

float lambert(t_ray *light_ray, t_vec3d *normal, float *coef)
{
	return (vec3d_dot(&light_ray->dir, normal) * *coef);
}

/*
** Lambert diffusion
*/
void lamb_dif(float lamb, t_rgbap *color, t_light cur_light, t_material cur_mat)
{
	color->red += lamb * cur_light.intensity.red * cur_mat.diffuse.red;
	color->green += lamb * cur_light.intensity.green * cur_mat.diffuse.green;
	color->blue += lamb * cur_light.intensity.blue * cur_mat.diffuse.blue;
}

/*
** Iterate over the reflection
** The reflected ray start and direction
*/
void calculate_reflection(t_rtv *rtv)
{
	rtv->calc->coef *= rtv->calc->cur_mat.reflection;
	rtv->scene->ray.start = rtv->calc->new_start;
	rtv->calc->reflect = 2.0f * vec3d_dot(&rtv->scene->ray.dir, &rtv->calc->intersect_normal);
	rtv->calc->tmp = vec3d_scale(rtv->calc->reflect, &rtv->calc->intersect_normal);
	rtv->scene->ray.dir = vec3d_sub(&rtv->scene->ray.dir, &rtv->calc->tmp);
}

/*
** Find the value of the light at this point
*/
void calculate_light(t_rtv *rtv)
{
	int			j;
	t_light		cur_light;
	t_vec3d		dist;
	float		t2;
	t_ray		light_ray;

	j = -1;
	while(j++ < 2)
	{
		cur_light = *rtv->scene->lights[j];
		dist = vec3d_sub(&cur_light.pos, &rtv->calc->new_start);
		// <= 0.0f
		if(vec3d_dot(&rtv->calc->intersect_normal, &dist) < 0.0001f)
			continue;
		t2 = sqrtf(vec3d_dot(&dist, &dist));
		// <= 0.0f
		if(t2 < 0.0001f)
			continue;
		light_ray.start = rtv->calc->new_start;
		light_ray.dir = vec3d_scale((1/t2), &dist);
		if (!(calculate_shadows(rtv->scene->objects, &light_ray, &t2)))
		{
			float lamb = lambert(&light_ray, &rtv->calc->intersect_normal, &rtv->calc->coef);
			lamb_dif(lamb, &rtv->calc->color, cur_light, rtv->calc->cur_mat);
		}
	}
}