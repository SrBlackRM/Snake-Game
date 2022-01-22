void set_keys()
{
    keys.key_right = (int*)malloc(2*sizeof(int));
    keys.key_left = (int*)malloc(2*sizeof(int));
    keys.key_down = (int*)malloc(2*sizeof(int));
    keys.key_up = (int*)malloc(2*sizeof(int));

    keys.key_right[0] = 68;
    keys.key_right[1] = 100;
    keys.key_left[0] = 65;
    keys.key_left[1] = 97;
    keys.key_down[0] = 83;
    keys.key_down[1] = 115;
    keys.key_up[0] = 87;
    keys.key_up[1] = 119;
}

/*
int get_key()
{
    int key_pressed = 0;

    printf("Entre com uma tecla: ");
    key_pressed = getch();

    fflush(stdin);
    return key_pressed;
}
*/

SDL_Event get_key(){
    SDL_Event event;
    SDL_PollEvent(&event);
    return event;
}

void move(SDL_Event key_pressed){
    move_x = 0;
    move_y = 0;

    switch(key_pressed.type){
        case SDL_KEYDOWN:
            if(key_pressed.key.keysym.sym == keys.key_right[0] || key_pressed.key.keysym.sym == keys.key_right[1]){
            move_x += 1;
            }
            else if(key_pressed.key.keysym.sym == keys.key_left[0] || key_pressed.key.keysym.sym == keys.key_left[1]){
                move_x -= 1;
            }
            else if(key_pressed.key.keysym.sym == keys.key_up[0] || key_pressed.key.keysym.sym == keys.key_up[1]){
                move_y += 1;
            }
            else if(key_pressed.key.keysym.sym == keys.key_down[0] || key_pressed.key.keysym.sym == keys.key_down[1]){
                move_y -= 1;
            }

            else if(key_pressed.key.keysym.sym == 27){
                printf("SAINDO...");
                exit(0);
                destroy_window(window);
            }
            else{
                printf("TECLA PRESSIONADA ERRADA\n");
            }
            break;
        }


    if(move_x != 0 || move_y !=0){
        printf("Posicao x: %d e Posicao y: %d\n",move_x,move_y);
    }
}

void mechanics_init()
{
    set_keys();
}

void move_start(){
    move(get_key());
}

void free_keys(){
    free(keys.key_down);
    free(keys.key_left);
    free(keys.key_right);
    free(keys.key_up);
}
