#include "rtv.h"
#include "rtv_defines.h"
#include "objects.h"

static t_rgba set_pixel_color(t_rtv *rtv)
{
	t_rgba color;

	color.red = (unsigned char)min(rtv->calc->color.red * 255.0f, 255.0f);
	color.green = (unsigned char)min(rtv->calc->color.green * 255.0f, 255.0f);
	color.blue = (unsigned char)min(rtv->calc->color.blue * 255.0f, 255.0f);
	color.alpha = SDL_ALPHA_OPAQUE;
	return (color);
}

static void set_raytrace(t_rtv *rtv, Uint16 x, Uint16 y)
{
	rtv->calc->level = 1;
	rtv->calc->coef = 1.0;
	rtv->calc->color.red = 0;
	rtv->calc->color.green = 0;
	rtv->calc->color.blue = 0;



//	t_vec2d x_y;
//	x_y.v = (2.0f*x) / 800 - 1.0f;
//	x_y.u = (-2.0f*y) / 600 + 1.0f;
//	make_ray(rtv->scene->cam, x_y, &rtv->scene->ray);

	t_vec3d xcomp = ft_vec3d_scale(rtv->scene->cam.vpRight, ((x * rtv->scene->cam.pixelWidth) - rtv->scene->cam.halfWidth));
	t_vec3d ycomp = ft_vec3d_scale(rtv->scene->cam.vpUp, ((y * rtv->scene->cam.pixelHeight) - rtv->scene->cam.halfHeight));
////
	rtv->scene->ray.dir = ft_vec3d_unit(ft_vec3d_add3(rtv->scene->cam.eye, xcomp, ycomp));
//

//	float fovx = PI /4;
//	float fovy = 600.0f/800.0f * fovx;
//
//	rtv->scene->ray.start.x = x;
//	rtv->scene->ray.start.y = y;
//	rtv->scene->ray.start.z = -200;
//	rtv->scene->ray.dir.x = 0;
//	rtv->scene->ray.dir.y = 0;
//	rtv->scene->ray.dir.z = 1;

//	printf("start.x - %f\n", rtv->scene->ray.start.x);
//	printf("start.y - %f\n", rtv->scene->ray.start.y);
//	printf("start.z - %f\n", rtv->scene->ray.start.z);
//	printf("dir.x - %f\n", rtv->scene->ray.dir.x);
//	printf("dir.y - %f\n", rtv->scene->ray.dir.y);
//	printf("dir.z - %f\n", rtv->scene->ray.dir.z);
}

static void calculate_ray(t_rtv *rtv)
{
	while((rtv->calc->coef > 0.01f) && (rtv->calc->level++ < 15))
	{
		rtv->calc->cur_obj = -1;
		if (object_intersect(rtv, &rtv->scene->ray, &rtv->calc->cur_obj, &rtv->calc->new_start) == false)
			break;
		if (normal_of_intersect(&rtv->calc->intersect_normal, &rtv->calc->new_start, rtv->scene->objects, rtv->calc->cur_obj) == false)
			break;
		rtv->calc->material_n = rtv->scene->objects[rtv->calc->cur_obj]->material;
		rtv->calc->cur_mat = *rtv->scene->materials[rtv->scene->objects[rtv->calc->cur_obj]->material];
		calculate_light(rtv);
		calculate_reflection(rtv);
	}
}

void raytrace(t_rtv *rtv)
{
	Uint16 x;
	Uint16 y;

	y = 0;
	while (y++ < HEIGHT)
	{
		x = 0;
		while (x++ < WIDTH)
		{
			set_raytrace(rtv, x, y);
			calculate_ray(rtv);
			rtv->calc->pixel_color = set_pixel_color(rtv);
			ft_draw_pixel(x, y, &rtv->calc->pixel_color, rtv->win->draw_buf);
		}
	}
}