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

//int		main(int ac, char **av)
//{
//	t_rtv	*rtv;
//	char	*errors[number_of_errors];
//
//	rtv_init_errors(errors);
//	if (ac == 2)
//	{
//		rtv = rtv_init(errors, av);
//		screen_create(rtv, 800, 600, "RTv1, 800x600\0");
//
//		screen_clear(rtv);
//		ft_noise(rtv);
//		screen_update(rtv);
//
//		rtv_loop(rtv);
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
//		rtv_error(usage_error, errors);
//}

void *create_sceen_one()
{

}

void create_sceen(int sceen_number)
{
	if (sceen_number == 1)
	{
		create_sceen_one();
	}
}

int main(int argc, char **argv){

	/* Our ray and a sphere */
	t_sphere s;

	/* x, y for screen 'resolution' */
	int x,y;

	/* Intersect ray/sphere or not */


	/* Position the sphere */
	s.pos.x = 20;
	s.pos.y = 20;
	s.pos.z = 20;

	/* Sphere radius */
	s.radius = 20;

	/* Direction of the ray */
	r.dir.x = 0;
	r.dir.y = 0;
	r.dir.z = 1;

	/* Start position of the ray, z coordinate */
	r.start.z = 0;

	/* Iterate over every 'pixel' of our screen
	 * We use a 40x40 virtual ASCII screen for now
	 */
	for(y=0;y<40;y++){
		/* Set the y-coordinate of the start position of the ray */
		r.start.y = y;
		for(x=0;x<40;x++){
			/* Set the x-coordinate of the start position of the ray */
			r.start.x = x;

			/* Check if the ray intersects with the shpere */
			hit = intersect_sphere(&r, &s);
			if(hit)
				printf("++");
			else
				printf("--");
		}
		/* First row of the screen done, move to next row */
		printf("\n");
	}

}

