#include <stdio.h>
#include <stdlib.h>
#include "mechanics.h"
#include "view_draw.h"
#include "snake.h"
#include "points.h"

int main(int argc, char *argv[])
{
    draw_initialize();
    mechanics_init();
    snake_init(snake,(WIDTH-imagem_snake->w)/2,(HEIGHT-imagem_snake->h)/2);
    snakes_init(snakes,"snake-graphics.bpm");

    points_init();

    if(window != NULL){
        while(!SDL_QuitRequested()){
            move_start();
            move_draw();
            respawn_point();
            if(loss_verify() == 1){
                break;
            }
        }
    }
    else{
        printf("Erro na criaçao da janela: %s", SDL_GetError());
    }

    snakes_free(snakes);
    SDL_FreeSurface(imagem_snake);
    SDL_FreeSurface(superficie);
    SDL_DestroyRenderer(render);
    SDL_DestroyTexture(snake.textura_snake);
    SDL_DestroyTexture(background);
    destroy_window(window);

    return 0;
}
