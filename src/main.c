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
#include <stdbool.h> /* Needed for boolean datatype */
#include <math.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

/* Width and height of out image */
#define WIDTH  800
#define HEIGHT 600

/* Check if the ray and sphere intersect */
bool intersectRaySphere(ray *r, sphere *s, float *t){

	bool retval = false;

	/* A = d.d, the vector dot product of the direction */
	float A = vectorDot(&r->dir, &r->dir);

	/* We need a vector representing the distance between the start of
	 * the ray and the position of the circle.
	 * This is the term (p0 - c)
	 */
	vector dist = vectorSub(&r->start, &s->pos);

	/* 2d.(p0 - c) */
	float B = 2 * vectorDot(&r->dir, &dist);

	/* (p0 - c).(p0 - c) - r^2 */
	float C = vectorDot(&dist, &dist) - (s->radius * s->radius);

	/* Solving the discriminant */
	float discr = B * B - 4 * A * C;

	/* If the discriminant is negative, there are no real roots.
	 * Return false in that case as the ray misses the sphere.
	 * Return true in all other cases (can be one or two intersections)
	 * t represents the distance between the start of the ray and
	 * the point on the sphere where it intersects.
	 */
	if(discr < 0)
		retval = false;
	else{
		float sqrtdiscr = sqrtf(discr);
		float t0 = (-B + sqrtdiscr)/(2);
		float t1 = (-B - sqrtdiscr)/(2);

		/* We want the closest one */
		if(t0 > t1)
			t0 = t1;

		/* Verify t1 larger than 0 and less than the original t */
		if((t0 > 0.001f) && (t0 < *t)){
			*t = t0;
			retval = true;
		}else
			retval = false;
	}

	return retval;
}

///* Output data as PPM file */
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

int main(int argc, char *argv[]){

	ray r;

	material materials[3];
	materials[0].diffuse.red = 1;
	materials[0].diffuse.green = 0;
	materials[0].diffuse.blue = 0;
	materials[0].reflection = 0.2;

	materials[1].diffuse.red = 0;
	materials[1].diffuse.green = 1;
	materials[1].diffuse.blue = 0;
	materials[1].reflection = 0.5;

	materials[2].diffuse.red = 0;
	materials[2].diffuse.green = 0;
	materials[2].diffuse.blue = 1;
	materials[2].reflection = 0.9;

	sphere spheres[3];
	spheres[0].pos.x = 200;
	spheres[0].pos.y = 300;
	spheres[0].pos.z = 0;
	spheres[0].radius = 100;
	spheres[0].material = 0;

	spheres[1].pos.x = 400;
	spheres[1].pos.y = 400;
	spheres[1].pos.z = 0;
	spheres[1].radius = 100;
	spheres[1].material = 1;

	spheres[2].pos.x = 500;
	spheres[2].pos.y = 140;
	spheres[2].pos.z = 0;
	spheres[2].radius = 100;
	spheres[2].material = 2;

	light lights[3];

	lights[0].pos.x = 0;
	lights[0].pos.y = 240;
	lights[0].pos.z = -100;
	lights[0].intensity.red = 1;
	lights[0].intensity.green = 1;
	lights[0].intensity.blue = 1;

	lights[1].pos.x = 3200;
	lights[1].pos.y = 3000;
	lights[1].pos.z = -1000;
	lights[1].intensity.red = 0.6;
	lights[1].intensity.green = 0.7;
	lights[1].intensity.blue = 1;

	lights[2].pos.x = 600;
	lights[2].pos.y = 0;
	lights[2].pos.z = -100;
	lights[2].intensity.red = 0.3;
	lights[2].intensity.green = 0.5;
	lights[2].intensity.blue = 1;
//
//	/* Will contain the raw image */
//	unsigned char img[3*WIDTH*HEIGHT];


	int x, y;
	for(y=0;y<HEIGHT;y++){
		for(x=0;x<WIDTH;x++){

			float red = 0;
			float green = 0;
			float blue = 0;

			int level = 0;
			float coef = 1.0;

			r.start.x = x;
			r.start.y = y;
			r.start.z = -2000;

			r.dir.x = 0;
			r.dir.y = 0;
			r.dir.z = 1;

			do{
				/* Find closest intersection */
				float t = 20000.0f;
				int currentSphere = -1;

				unsigned int i;
				for(i = 0; i < 3; i++){
					if(intersectRaySphere(&r, &spheres[i], &t))
						currentSphere = i;
				}
				if(currentSphere == -1) break;

				vector scaled = vectorScale(t, &r.dir);
				vector newStart = vectorAdd(&r.start, &scaled);

				/* Find the normal for this new vector at the point of intersection */
				vector n = vectorSub(&newStart, &spheres[currentSphere].pos);
				float temp = vectorDot(&n, &n);
				if(temp == 0) break;

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

			}while((coef > 0.0f) && (level < 15));

			img[(x + y*WIDTH)*3 + 0] = (unsigned char)min(red*255.0f, 255.0f);
			img[(x + y*WIDTH)*3 + 1] = (unsigned char)min(green*255.0f, 255.0f);
			img[(x + y*WIDTH)*3 + 2] = (unsigned char)min(blue*255.0f, 255.0f);
		}
	}

	saveppm("image.ppm", img, WIDTH, HEIGHT);

	return 0;
}

