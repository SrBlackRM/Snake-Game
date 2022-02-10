#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>


typedef struct{

    int tamanho;
    int scale;
    SDL_Rect sprite_position_src;
    SDL_Rect sprite_position_dest;
    SDL_Texture* textura_snake;

} SNAKE;

SNAKE snake;

SNAKE** snakes;
SDL_Surface* sprite_snake;


void snakes_init(SNAKE** snake_vector, char * nome_sprite);
void snakes_free(SNAKE** snake_vector);
void snake_init(SNAKE snakex, int posx, int posy);
void graphics_map(SNAKE** snake_vector);

//void snake_init(SNAKE snake, int posx, int posy);

#include "snake.c"
#endif // SNAKE_H_INCLUDED
