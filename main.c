#include <stdio.h>
#include <stdlib.h>
#include "mechanics.h"
#include "view_draw.h"

int main(int argc, char *argv[])
{
    mechanics_init();
    if(create_window(window) != NULL){
        while(!SDL_QuitRequested()){
            move_start();
        }
    }
    else{
        printf("Erro na criação da janela: %s", SDL_GetError());
    }

    destroy_window(window);

    return 0;
}
