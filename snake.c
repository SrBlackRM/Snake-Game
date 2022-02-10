void snake_init(SNAKE snakex, int posx, int posy){
    snakex.tamanho = 65;
    snakex.scale = 50;

    //cabeca
    snakex.sprite_position_src.x = 0;
    snakex.sprite_position_src.y = 0;
    snakex.sprite_position_src.w = snakex.tamanho+5;
    snakex.sprite_position_src.h = snakex.tamanho;


    if(posx > WIDTH || posy > HEIGHT || posx < 0 || posy < 0){
        snakex.sprite_position_dest.x = 0;
        snakex.sprite_position_dest.y = 0;
        snakex.sprite_position_dest.w = snakex.tamanho;
        snakex.sprite_position_dest.h = snakex.tamanho;
        printf("\nnao foi possivel definir essa posicao, portanto, ela foi zerada\n");
    }
    else{
        snakex.sprite_position_dest.x = posx;
        snakex.sprite_position_dest.y = posy;
        snakex.sprite_position_dest.w = snakex.scale;
        snakex.sprite_position_dest.h = snakex.scale;
    }
    //printf("posicao x: %d\nposicao y: %d\n",snakex.sprite_position_dest.x,snakex.sprite_position_dest.y);
    snake = snakex;
}


void snakes_init(SNAKE** snake_vector, char * nome_sprite){
    snake_vector = malloc(20*sizeof(int));
    sprite_snake = SDL_LoadBMP(nome_sprite);
    graphics_map(snake_vector);
}

void graphics_map(SNAKE** snake_vector){
    int i,j = 0;
    int tamanho_imagem = 56;
    for(i;i<5;i++){
        for(j;j<6;j++){
            /*snake_vector[i][j].sprite_position_src.x = j*tamanho_imagem;
            snake_vector[i][j].sprite_position_src.y = i*tamanho_imagem;*/
            snake_vector[i][j].sprite_position_src.y += j*tamanho_imagem;
            printf("%d \n",snake_vector[i][j].sprite_position_src.y);
            snake_vector[i][j].sprite_position_src.x += i*tamanho_imagem;
        }
    }
}


void snakes_free(SNAKE** snake_vector){
    free(snake_vector);
    SDL_FreeSurface(sprite_snake);
}
