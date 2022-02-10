#include <stdio.h>
#include <stdlib.h>
#ifndef MECHANICS_H_INCLUDED
#define MECHANICS_H_INCLUDED
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_image.h"
#include "view_draw.h"
#include "snake.h"
#include "points.h"
#include <stdlib.h>
#include <time.h>


//VARIABLES
struct Control
{
    int* key_right;
    int* key_left;
    int* key_down;
    int* key_up;
};

struct Control keys;

float move_x = 0;
float move_y = 0;
float acelerate = 1;
int game_score = 0;

//FUNCTIONS
void set_keys();
SDL_Event get_key();
void mechanics_init();
void free_keys();
int loss_verify();
void rand_points();
int colision(SNAKE obj1,Points obj2);
void score();

#include "mechanics.c"
#endif // MECHANICS_H_INCLUDED
