#include "rtv.h"

t_bool	running(SDL_Event *event, const Uint8 **key_state)
{
	SDL_Delay(1);
	SDL_PollEvent(event);
	if (event->type == SDL_QUIT)
		return (false);
	*key_state = SDL_GetKeyboardState(NULL);
	return (true);
}

void	rtv_loop(t_rtv *rtv)
{
	while ((running(&rtv->sdl->event, &rtv->sdl->key_state)))
		keyboard_core(rtv);
}