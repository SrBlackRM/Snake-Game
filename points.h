#ifndef POINTS_H_INCLUDED
#define POINTS_H_INCLUDED
#include "SDL.h"
#include <stdlib.h>
#include <time.h>

typedef struct{
    int point_size;
    SDL_Surface* imgage_point;
    SDL_Texture* texture_point;
    SDL_Rect point_rect_src;
    SDL_Rect point_rect_dest;

} Points;

Points point;

int points_init();

#include "points.c"
#endif // POINTS_H_INCLUDED
