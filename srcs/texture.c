#include "../includes/wolf3d.h"

void	showsky(t_acz *az)
{
	double new;

	new = (az->info->angle * 100) * 3200 / 600;
	while (new < 0)
		new += 3200;
	while (new > 3200)
		new -= 3200;
	az->game->rsky.x = 0;
	az->game->rsky.y = 0;
	az->game->rsky.w = 800;
	az->game->rsky.h = 300;

	az->game->rsky2.x = new;
	az->game->rsky2.y = 0;
	az->game->rsky2.w = 800;
	az->game->rsky2.h = 300;
	
	az->game->rground.x = 0;
	az->game->rground.y = 300;
	az->game->rground.w = 800;
	az->game->rground.h = 300;
}

void	load_texture(SDL_Renderer *render, SDL_Texture **texture, char *path)
{
	SDL_Surface	*surface;

	surface = IMG_Load(path);
	surface == NULL ? stop_exec("cant load surface\n") : 0;
	*texture = SDL_CreateTextureFromSurface(render, surface);
	SDL_FreeSurface(surface);
}
