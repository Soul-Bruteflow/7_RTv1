#include "rtv1.h"

void	keyboard_core(t_rtv *rtv)
{
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_ESCAPE])
		exit(0);
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_UP])
	{
//		rtv->scene->obj[0]->sphere->pos.x -= 10.0;
		screen_clear(rtv);
		ray_cast(rtv);
		screen_update(rtv);
	}
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_DOWN])
	{
//		rtv->scene->obj[0]->sphere->pos.x += 10.0;
		screen_clear(rtv);
		ray_cast(rtv);
		screen_update(rtv);
	}
}