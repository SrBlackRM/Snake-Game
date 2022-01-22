#ifndef VIEW_DRAW_H_INCLUDED
#define VIEW_DRAW_H_INCLUDED
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"

SDL_Window* window = NULL;
const int WIDTH = 760;
const int HEIGHT = 580;
SDL_Rect sprite_rect;

SDL_Window* create_window(SDL_Window* window);
int destroy_window(SDL_Window* window);
void load_sprites(SDL_Surface* carrega_sprite, const char* sprite);

#include "view_draw.c"
#endif // VIEW_DRAW_H_INCLUDED
