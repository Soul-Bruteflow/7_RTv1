#include <SDL2/SDL.h>
#include "rtv.h"

/*
** Release resources and quit.
*/

void	rtv_quit(t_rtv *rtv)
{
	SDL_DestroyTexture(rtv->win->screen);
	SDL_DestroyRenderer(rtv->sdl->renderer);
	SDL_DestroyWindow(rtv->sdl->window);
	SDL_Quit();
}