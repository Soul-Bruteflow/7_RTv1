#include "rtv1.h"
#include "objects.h"

//void action(t_rtv *rtv, int *level, float *coef, t_rgba *tmp_color)
//{
//	/* Find closest intersection */
//	float t = 20000.0f;
//	int currentSphere = -1;
//
//	unsigned int i;
//	for(i = 0; i < 0; i++){
//		if(intersect_sphere(rtv->scene->ray, rtv->scene->obj[i]->sphere, &t))
//			currentSphere = i;
//	}
//	if(currentSphere == -1) return;
//
//	t_vec3d scaled = vec3d_scale(t, &rtv->scene->ray->dir);
//	t_vec3d newStart = vec3d_add(&rtv->scene->ray->start, &scaled);
//
//	/* Find the normal for this new vector at the point of intersection */
//	t_vec3d n = vec3d_sub(&newStart, &rtv->scene->obj[currentSphere]->sphere->pos);
//	float temp = vec3d_dot(&n, &n);
//	if(temp == 0) return;
//
//	temp = 1.0f / sqrtf(temp);
//	n = vec3d_scale(temp, &n);
//
//	/* Find the material to determine the colour */
//	t_material currentMat = *rtv->scene->material[rtv->scene->obj[currentSphere]->sphere->material];
//
//	/* Find the value of the light at this point */
//	unsigned int j;
//	for(j=0; j <= 0; j++){
//		t_light currentLight = *rtv->scene->light[j];
//		t_vec3d dist = vec3d_sub(&currentLight.pos, &newStart);
//		if(vec3d_dot(&n, &dist) <= 0.0f) continue;
//		float t = sqrtf(vec3d_dot(&dist,&dist));
//		if(t <= 0.0f) continue;
//
//		t_ray lightRay;
//		lightRay.start = newStart;
//		lightRay.dir = vec3d_scale((1/t), &dist);
//
//		/* Calculate shadows */
//		t_bool inShadow = false;
//		unsigned int k;
//		for (k = 0; k <= 0; ++k) {
//			if (intersect_sphere(&lightRay, rtv->scene->obj[k]->sphere, &t)){
//				inShadow = true;
//				break;
//			}
//		}
//		if (!inShadow){
//			/* Lambert diffusion */
//			float lambert = vec3d_dot(&lightRay.dir, &n) * *coef;
//			tmp_color->red += lambert * currentLight.intensity.red * currentMat.diffuse.red;
//			tmp_color->green += lambert * currentLight.intensity.green * currentMat.diffuse.green;
//			tmp_color->blue += lambert * currentLight.intensity.blue * currentMat.diffuse.blue;
//		}
//	}
//	/* Iterate over the reflection */
//	*coef *= currentMat.reflection;
//
//	/* The reflected ray start and direction */
////	r.start = newStart;
////	float reflect = 2.0f * vectorDot(&r.dir, &n);
////	vector tmp = vectorScale(reflect, &n);
////	r.dir = vectorSub(&r.dir, &tmp);
//
////	level++;
//}

void ray_cast(t_rtv *rtv)
{
	Uint16 i;
	Uint16 j;

	i = 0;
	while (i < rtv->win->height)
	{
		j = 0;
		rtv->scene->ray.start.y = i;
		while (j < rtv->win->width)
		{
			t_rgba tmp_color;
			tmp_color.red = 200;
			tmp_color.green = 0;
			tmp_color.blue = 0;

//			int level = 0;
//			float coef = 1.0;
//
//			rtv->scene->ray->start.x = i;
//			rtv->scene->ray->start.y = j;
//			rtv->scene->ray->start.z = -2000;
//
//			rtv->scene->ray->dir.x = 0;
//			rtv->scene->ray->dir.y = 0;
//			rtv->scene->ray->dir.z = 1;
//
//			tmp_color.alpha = SDL_ALPHA_OPAQUE;
//			action(rtv, &level, &coef, &tmp_color);
//			while((coef > 0.0f) && (level < 15));
//				action(rtv, &level, &coef, &tmp_color);
//			draw_pixel(i, j, &tmp_color, rtv);


			float t = 20000.0f;

//			rtv->scene->obj[0]->hit = intersect_sphere(rtv->scene->ray, rtv->scene->obj[0]->sphere);
//			rtv->scene->obj[1]->hit = intersect_plane_ray(rtv->scene->ray, rtv->scene->obj[1]->plane);
//			if(rtv->scene->obj[0]->hit)
			if(rtv->scene->obj[0]->hit)
				draw_pixel(i, j, &tmp_color, rtv);
//				printf("++");
//			else
//				printf("--");
			rtv->scene->ray.start.x = j;
			j++;
		}
		printf("\n");
		i++;
	}
}