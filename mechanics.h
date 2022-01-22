#include <stdio.h>
#include <stdlib.h>
#ifndef MECHANICS_H_INCLUDED
#define MECHANICS_H_INCLUDED
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"
#include "view_draw.h"


//VARIABLES
struct Control
{
    int* key_right;
    int* key_left;
    int* key_down;
    int* key_up;
};

struct Control keys;

int move_x = 0;
int move_y = 0;

//FUNCTIONS
void set_keys();
SDL_Event get_key();
void mechanics_init();
void free_keys();

#include "mechanics.c"
#endif // MECHANICS_H_INCLUDED
