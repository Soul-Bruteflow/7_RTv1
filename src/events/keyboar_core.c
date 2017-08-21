#include "rtv.h"

void	keyboard_core(t_rtv *rtv)
{
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_ESCAPE])
		exit(0);
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_UP])
	{
//		rtv->scene->obj[0]->sphere->pos.x -= 10.0;
		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_DOWN])
	{
//		rtv->scene->obj[0]->sphere->pos.x += 10.0;
		clear_window(rtv);
		raytrace(rtv);
		render_present(rtv);
	}
}