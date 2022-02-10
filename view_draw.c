int destroy_window(SDL_Window* window){
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
}

void move_draw(){
    /*SDL_BlitSurface(snake.imagem_snake,NULL,superficie,&snake.sprite_position);
    SDL_UpdateWindowSurface(window);
    printf("Posicao snake x: %d e Posicao snake y: %d\n",snake.sprite_position.x,snake.sprite_position.y);
    */
    snake.textura_snake = SDL_CreateTextureFromSurface(render,imagem_snake);
    //SDL_FreeSurface(imagem_snake);
    SDL_RenderClear(render);
    SDL_RenderCopy(render,background,NULL,NULL);
    SDL_RenderCopy(render,point.texture_point,&point.point_rect_src,&point.point_rect_dest);
    SDL_RenderCopy(render,snake.textura_snake,&snake.sprite_position_src,&snake.sprite_position_dest);
    SDL_RenderPresent(render);
    //printf("Posicao snake x: %d e Posicao snake y: %d\n",snake.sprite_position_dest.x,snake.sprite_position_dest.y);
}

void respawn_point(){
    SDL_Texture* Temporary_Texture = NULL;
    if(colision(snake,point)==1){
        score();
        show_score();
        Temporary_Texture = point.texture_point;
        point.texture_point = NULL;
        rand_points();
        point.texture_point = Temporary_Texture;
        SDL_RenderCopy(render,point.texture_point,&point.point_rect_src,&point.point_rect_dest);
        SDL_RenderPresent(render);
    }
}

int draw_initialize(){

    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("SNAKE GAME - By MOTA", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    render = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    superficie = SDL_LoadBMP("background.bmp");
    imagem_snake = SDL_LoadBMP("snakeImage_stand_right.bmp");
    //imagem_snake = SDL_LoadBMP("snake-graphics.bmp");

    point.imgage_point = SDL_LoadBMP("mouse1.bmp");
    point.texture_point = SDL_CreateTextureFromSurface(render,point.imgage_point);
    SDL_FreeSurface(point.imgage_point);

    background = SDL_CreateTextureFromSurface(render,superficie);
    SDL_FreeSurface(superficie);

    superficie = SDL_GetWindowSurface(window);
    SDL_UpdateWindowSurface(window);

    return 1;
}
