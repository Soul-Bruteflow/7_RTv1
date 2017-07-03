#include "rtv1.h"

void	keyboard_core(t_rtv *rtv)
{
	if (SDL_KEYDOWN && rtv->sdl->key_state[SDL_SCANCODE_ESCAPE])
		exit(0);
}