#include "rtv.h"

void	keyboard_core(t_rtv *rtv)
{
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_ESCAPE])
		exit(0);
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_UP])
	{
		t_plane *p = rtv->scene->objects[0]->type;

		p->distance += 1000;
		printf("distance - %f\n", p->distance);
//		rtv->scene->obj[0]->sphere->pos.x -= 10.0;
		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_DOWN])
	{
		t_plane *p = rtv->scene->objects[0]->type;
		p->distance -= 1000;
		printf("distance - %f\n", p->distance);
//		rtv->scene->obj[0]->sphere->pos.x += 10.0;
		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_RIGHT])
	{
		t_plane *p = rtv->scene->objects[0]->type;

		p->normal.x += 50;
//		rtv->scene->obj[0]->sphere->pos.x -= 10.0;
		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_LEFT])
	{
		t_plane *p = rtv->scene->objects[0]->type;

		p->normal.x -= 50;
//		rtv->scene->obj[0]->sphere->pos.x += 10.0;
		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
}