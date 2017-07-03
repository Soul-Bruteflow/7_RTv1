#include "rtv1.h"

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
//	raycast_init(wolf);
//	wolf_font_init(wolf);
//	wolf_audio_init(wolf);
	while ((running(&rtv->sdl->event, &rtv->sdl->key_state)))
	{
//		raycast_core(wolf);

//		update_time(wolf);
		keyboard_core(rtv);
	}
}