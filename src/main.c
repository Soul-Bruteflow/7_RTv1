/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 12:13:15 by mvlad             #+#    #+#             */
/*   Updated: 2017/06/08 12:14:44 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv_includes.h"
//
//int		main(int ac, char **av)
//{
//	t_rtv	*rtv;
//
//	if (ac == 2)
//	{
//		rtv = rtv_init(av);
//		screen_create(rtv, 800, 600, "RTv1, 800x600\0");
//
//		rtv->scene = create_sceen(1);
//
//
//		screen_clear(rtv);
//
//		ray_cast(rtv);
////		ft_noise(rtv);
//
//		screen_update(rtv);
////
//		rtv_loop(rtv);
//
//
//
////error test
////		rtv_error(sdl_window_error, rtv->utl->errors);
//
////		wolf = wolf_init(wolf, 800, 600, "wolf3d, \0");
////		wolf->av = av;
////		map_parser(wolf);
////		wolf->pitch = 800 *4;
////		wolf->offset = 0;
////		game_loop(wolf);
////		quit(wolf);
//	}
//	else
//		rtv_error(usage_error);
//}



/* A simple ray tracer */

#include <stdio.h>
//#include <stdbool.h> /* Needed for boolean datatype */
#include <math.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

/* Width and height of out image */
#define WIDTH  800
#define HEIGHT 600

///* Check if the ray and sphere intersect */
//t_bool intersectRaySphere(t_ray *r, t_obj3d *object, float *t){
//
//	t_sphere *s;
//	t_obj3d *o;
//	t_bool retval;
//
//	o = object;
//	s = object->type;
//
//	/* A = d.d, the vector dot product of the direction */
//	float A = vec3d_dot(&r->dir, &r->dir);
//
//	/* We need a vector representing the distance between the start of
//	 * the ray and the position of the circle.
//	 * This is the term (p0 - c)
//	 */
//	t_vec3d dist = vec3d_sub(&r->start, &o->pos);
//
//	/* 2d.(p0 - c) */
//	float B = 2 * vec3d_dot(&r->dir, &dist);
//
//	/* (p0 - c).(p0 - c) - r^2 */
//	float C = vec3d_dot(&dist, &dist) - (s->radius * s->radius);
//
//	/* Solving the discriminant */
//	float discr = B * B - 4 * A * C;
//
//	/* If the discriminant is negative, there are no real roots.
//	 * Return false in that case as the ray misses the sphere.
//	 * Return true in all other cases (can be one or two intersections)
//	 * t represents the distance between the start of the ray and
//	 * the point on the sphere where it intersects.
//	 */
//	if(discr < 0)
//		retval = false;
//	else{
//		float sqrtdiscr = sqrtf(discr);
//		float t0 = (-B + sqrtdiscr)/(2);
//		float t1 = (-B - sqrtdiscr)/(2);
//
//		/* We want the closest one */
//		if(t0 > t1)
//			t0 = t1;
//
//		/* Verify t1 larger than 0 and less than the original t */
//		if((t0 > 0.001f) && (t0 < *t)){
//			*t = t0;
//			retval = true;
//		}else
//			retval = false;
//	}
//
//	return retval;
//}

/////* Output data as PPM file */
//void saveppm(char *filename, unsigned char *img, int width, int height){
//	/* FILE pointer */
//	FILE *f;
//
//	/* Open file for writing */
//	f = fopen(filename, "w");
//
//	/* PPM header info, including the size of the image */
//	fprintf(f, "P6 %d %d %d\n", width, height, 255);
//
//	/* Write the image data to the file - remember 3 byte per pixel */
//	fwrite(img, 3, width*height, f);
//
//	/* Make sure you close the file */
//	fclose(f);
//}

/*
** Find closest intersection
*/
t_bool	object_intersect(t_obj3d **objects, t_ray *r, int *cur_obj, t_vec3d *new_start)
{
	float	t;
	int		i;
	t_vec3d	scaled;

	t = 20000.0f;
	i = -1;
	while(i++ < 2)
	{
		if (objects[i]->intersect(r, objects[i], &t))
			*cur_obj = i;
	}
	if(*cur_obj == -1)
		return (false);
	scaled = vec3d_scale(t, &r->dir);
	*new_start = vec3d_add(&r->start, &scaled);
	return (true);
}

/*
** Find the normal for this new vector at the point of intersection.
*/
t_bool normal_of_intersect(t_vec3d *normal, t_vec3d *new_start, t_obj3d **objects, int cur_obj)
{
	float temp;
	*normal = vec3d_sub(new_start, &objects[cur_obj]->pos);
	temp = vec3d_dot(normal, normal);
	if(temp == 0)
		return false;
	temp = 1.0f / sqrtf(temp);
	*normal = vec3d_scale(temp, normal);
	return true;
}

t_bool calculate_shadows(t_obj3d **objects, t_ray *light_ray, float *t2)
{
	int k;

	k = -1;
	while (k++ < 2)
	{
		if (objects[k]->intersect(light_ray, objects[k], t2))
		{
			return  (true);
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
		if(vec3d_dot(&rtv->calc->intersect_normal, &dist) <= 0.0f)
			continue;
		t2 = sqrtf(vec3d_dot(&dist, &dist));
		if(t2 <= 0.0f)
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

void set_raycast(t_rtv *rtv, Uint16 x, Uint16 y)
{
	rtv->calc->level = -1;
	rtv->calc->coef = 1.0;
	rtv->calc->color.red = 0;
	rtv->calc->color.green = 0;
	rtv->calc->color.blue = 0;
	rtv->scene->ray.start.x = x;
	rtv->scene->ray.start.y = y;
	rtv->scene->ray.start.z = -2000;
	rtv->scene->ray.dir.x = 0;
	rtv->scene->ray.dir.y = 0;
	rtv->scene->ray.dir.z = 1;
}

t_rgba set_pixel_color(t_rtv *rtv)
{
	t_rgba color;

	color.red = (unsigned char)min(rtv->calc->color.red * 255.0f, 255.0f);
	color.green = (unsigned char)min(rtv->calc->color.green * 255.0f, 255.0f);
	color.blue = (unsigned char)min(rtv->calc->color.blue * 255.0f, 255.0f);
	color.alpha = SDL_ALPHA_OPAQUE;
	return (color);
}

void ray_trace(t_rtv *rtv)
{
	while((rtv->calc->coef > 0.0f) && (rtv->calc->level++ < 15))
	{
		rtv->calc->cur_obj = -1;
		if (object_intersect(rtv->scene->objects, &rtv->scene->ray, &rtv->calc->cur_obj, &rtv->calc->new_start) == false)
			break;
		if (normal_of_intersect(&rtv->calc->intersect_normal, &rtv->calc->new_start, rtv->scene->objects, rtv->calc->cur_obj) == false)
			break;
		rtv->calc->cur_mat = *rtv->scene->materials[rtv->scene->objects[rtv->calc->cur_obj]->material];
		calculate_light(rtv);
		calculate_reflection(rtv);
	}
}

int main(int ac, char **av)
{
	t_rtv	*rtv;

//	t_material materials[13];
//	materials[0].diffuse.red = 1;
//	materials[0].diffuse.green = 1;
//	materials[0].diffuse.blue = 1;
//	materials[0].diffuse.alpha = SDL_ALPHA_OPAQUE;
//	materials[0].reflection = 0;
//
//	materials[1].diffuse.red = 0;
//	materials[1].diffuse.green = 1;
//	materials[1].diffuse.blue = 0;
//	materials[1].diffuse.alpha = SDL_ALPHA_OPAQUE;
//	materials[1].reflection = 0.5;
//
//	materials[2].diffuse.red = 0;
//	materials[2].diffuse.green = 0;
//	materials[2].diffuse.blue = 1;
//	materials[2].diffuse.alpha = SDL_ALPHA_OPAQUE;
//	materials[2].reflection = 0.9;
//
//	t_sphere *spheres = malloc(23 * sizeof(spheres));
//
////	spheres[0].pos.x = 0;
////	spheres[0].pos.y = 0;
////	spheres[0].pos.z = 0;
//	spheres[0].radius = 100;
////	spheres[0].material = 0;
//
////	spheres[1].pos.x = 400;
////	spheres[1].pos.y = 400;
////	spheres[1].pos.z = 0;
//	spheres[1].radius = 100;
////	spheres[1].material = 1;
//
////	spheres[2].pos.x = 500;
////	spheres[2].pos.y = 140;
////	spheres[2].pos.z = 0;
//	spheres[2].radius = 100;
////	spheres[2].material = 2;
//
//	t_light lights[13];
//	lights[0].pos.x = 0;
//	lights[0].pos.y = 240;
//	lights[0].pos.z = -100;
//	lights[0].intensity.red = 1;
//	lights[0].intensity.green = 1;
//	lights[0].intensity.blue = 1;
//
//	lights[1].pos.x = 3200;
//	lights[1].pos.y = 3000;
//	lights[1].pos.z = -1000;
//	lights[1].intensity.red = 0.6;
//	lights[1].intensity.green = 0.7;
//	lights[1].intensity.blue = 1;
//
//	lights[2].pos.x = 600;
//	lights[2].pos.y = 0;
//	lights[2].pos.z = -100;
//	lights[2].intensity.red = 0.3;
//	lights[2].intensity.green = 0.5;
//	lights[2].intensity.blue = 1;
//
//	t_obj3d	*objects = malloc(23 * sizeof(objects));
//	objects[0].type = &spheres[0];
//	objects[0].intersect = intersectRaySphere;
//	objects[0].pos.x = 0;
//	objects[0].pos.y = 0;
//	objects[0].pos.z = 0;
//	objects[0].material = 0;
//
//	objects[1].type = &spheres[1];
//	objects[1].intersect = intersectRaySphere;
//	objects[1].pos.x = 400;
//	objects[1].pos.y = 400;
//	objects[1].pos.z = 0;
//	objects[1].material = 1;
//
//	objects[2].type = &spheres[2];
//	objects[2].intersect = intersectRaySphere;
//	objects[2].pos.x = 500;
//	objects[2].pos.y = 140;
//	objects[2].pos.z = 0;
//	objects[2].material = 2;

	rtv = rtv_init(av);
	screen_create(rtv, 800, 600, "RTv1, 800x600\0");

	rtv->scene = create_scene(1);

	screen_clear(rtv);
	int x, y;
	for(y=0;y<HEIGHT;y++)
	{
		for(x=0;x<WIDTH;x++)
		{
			set_raycast(rtv, x, y);
			ray_trace(rtv);
			rtv->calc->pixel_color = set_pixel_color(rtv);
			draw_pixel(x, y, &rtv->calc->pixel_color, rtv);
		}
	}
	screen_update(rtv);
	rtv_loop(rtv);
	return (0);
}

