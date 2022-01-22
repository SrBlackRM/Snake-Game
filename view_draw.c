SDL_Window* create_window(SDL_Window* window){

    printf("Iniciando VIDEO e AUDIO SDL.\n");
    if( ( SDL_Init ( SDL_INIT_VIDEO || SDL_INIT_AUDIO ) == 0 ) ){  // SDL_Init() serve para iniciar algum sistema
        window = SDL_CreateWindow("SNAKE GAME - By MOTA", 100, 50, WIDTH, HEIGHT, 0);                                                          // serve para retornar o erro.
    }
    else{
        SDL_Log("Erro na inicializacao: %s", SDL_GetError());
    }
    return window;
}

int destroy_window(SDL_Window* window){
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
}

void load_sprites(SDL_Surface* carrega_sprite, const char* sprite){
    carrega_sprite = IMG_Load(sprite);
}
