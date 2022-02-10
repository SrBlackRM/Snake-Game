#ifndef VIEW_DRAW_H_INCLUDED
#define VIEW_DRAW_H_INCLUDED
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"
#include "mechanics.h"


SDL_Window* window = NULL;
const int WIDTH = 760;
const int HEIGHT = 580;
int update = 4;
SDL_Surface* superficie = NULL;
SDL_Surface* imagem_snake = NULL;
SDL_Renderer* render = NULL;
SDL_Texture* background = NULL;


int draw_initialize();
int destroy_window(SDL_Window* window);
void load_sprites(SDL_Surface* carrega_sprite, const char* sprite);
void move_draw();
void respawn_point();
void show_score();

#include "snake.h"
#include "points.h"
#include "view_draw.c"
#endif // VIEW_DRAW_H_INCLUDED
