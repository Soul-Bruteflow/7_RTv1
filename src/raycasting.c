#include "rtv1.h"
#include "objects.h"

void action(t_rtv *rtv)
{
	/* Find closest intersection */
	float t = 20000.0f;
	int currentSphere = -1;

	unsigned int i;
	for(i = 0; i <= 0; i++){
		if(intersect_sphere(rtv->scene->ray, rtv->scene->obj[i]->sphere, &t))
			currentSphere = i;
	}
	if(currentSphere == -1) return;



	vector scaled = vectorScale(t, &r.dir);
	vector newStart = vectorAdd(&r.start, &scaled);

	/* Find the normal for this new vector at the point of intersection */
	vector n = vectorSub(&newStart, &spheres[currentSphere].pos);
	float temp = vectorDot(&n, &n);
	if(temp == 0) return;

	temp = 1.0f / sqrtf(temp);
	n = vectorScale(temp, &n);

	/* Find the material to determine the colour */
	material currentMat = materials[spheres[currentSphere].material];

	/* Find the value of the light at this point */
	unsigned int j;
	for(j=0; j < 3; j++){
		light currentLight = lights[j];
		vector dist = vectorSub(&currentLight.pos, &newStart);
		if(vectorDot(&n, &dist) <= 0.0f) continue;
		float t = sqrtf(vectorDot(&dist,&dist));
		if(t <= 0.0f) continue;

		ray lightRay;
		lightRay.start = newStart;
		lightRay.dir = vectorScale((1/t), &dist);

		/* Calculate shadows */
		bool inShadow = false;
		unsigned int k;
		for (k = 0; k < 3; ++k) {
			if (intersectRaySphere(&lightRay, &spheres[k], &t)){
				inShadow = true;
				break;
			}
		}
		if (!inShadow){
			/* Lambert diffusion */
			float lambert = vectorDot(&lightRay.dir, &n) * coef;
			red += lambert * currentLight.intensity.red * currentMat.diffuse.red;
			green += lambert * currentLight.intensity.green * currentMat.diffuse.green;
			blue += lambert * currentLight.intensity.blue * currentMat.diffuse.blue;
		}
	}
	/* Iterate over the reflection */
	coef *= currentMat.reflection;

	/* The reflected ray start and direction */
	r.start = newStart;
	float reflect = 2.0f * vectorDot(&r.dir, &n);
	vector tmp = vectorScale(reflect, &n);
	r.dir = vectorSub(&r.dir, &tmp);

	level++;
}

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
			while((coef > 0.0f) && (level < 15));
				action(rtv);
			draw_pixel(i, j, &tmp_color, rtv);
//			rtv->scene->obj[0]->hit = intersect_sphere(rtv->scene->ray, rtv->scene->obj[0]->sphere);
//			rtv->scene->obj[1]->hit = intersect_plane_ray(rtv->scene->ray, rtv->scene->obj[1]->plane);
//			if(rtv->scene->obj[0]->hit)
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