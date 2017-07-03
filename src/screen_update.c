#include "rtv1.h"

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

/*
** Clears screen.
** Sets render draw color to black and clears the window with it.
*/

void	screen_clear(t_rtv *rtv)
{
	SDL_SetRenderDrawColor(rtv->sdl->renderer, 0, 0, 0, 255);
	SDL_RenderClear(rtv->sdl->renderer);
}

/*
**  Shows what was drawn.
*/

void	screen_update(t_rtv *rtv)
{
//	wolf->sur_message = TTF_RenderText_Blended(wolf->font,
//			wolf->fps, wolf->white);
//	wolf->tex_message = SDL_CreateTextureFromSurface(wolf->sdl->renderer,
//			wolf->sur_message);
//	SDL_FreeSurface(wolf->sur_message);
	SDL_UpdateTexture(rtv->win->screen, NULL, &rtv->win->draw_buf[0], 800 * 4);
	SDL_RenderCopy(rtv->sdl->renderer, rtv->win->screen, NULL, NULL);
//	SDL_RenderCopy(wolf->sdl->renderer, wolf->tex_message,
//			NULL, &wolf->message_rect);
	SDL_RenderPresent(rtv->sdl->renderer);
	bzero(rtv->win->draw_buf, 800 * 600 * 4);
}