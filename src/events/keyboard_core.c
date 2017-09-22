#include "rtv.h"

void	keyboard_core(t_rtv *rtv)
{
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_ESCAPE])
		exit(0);
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_UP])
	{
		t_cylinder *c;
		c = rtv->scene->objects[0]->type;
		c->a.x += 50;
		c->b.x += 50;
		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_DOWN])
	{
		t_cylinder *c;
		c = rtv->scene->objects[0]->type;
		c->a.x -= 50;
		c->b.x -= 50;
		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_RIGHT])
	{
		t_plane *p = rtv->scene->objects[0]->type;
		p->normal.x += 50;
		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_LEFT])
	{
		t_plane *p = rtv->scene->objects[0]->type;
		p->normal.x -= 50;
		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
}