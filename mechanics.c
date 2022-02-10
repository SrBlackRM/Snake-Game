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

SDL_Event get_key(){
    SDL_Event event;
    SDL_PollEvent(&event);
    return event;
}

void move(SDL_Event key_pressed){

    switch(key_pressed.type){
        case SDL_KEYDOWN:
            if(key_pressed.key.keysym.sym == keys.key_right[0] || key_pressed.key.keysym.sym == keys.key_right[1]){
                move_x = 1;
                move_y = 0;
                imagem_snake = SDL_LoadBMP("snakeImage_right.bmp");
            }
            if(key_pressed.key.keysym.sym == keys.key_left[0] || key_pressed.key.keysym.sym == keys.key_left[1]){
                move_x = -1;
                move_y = 0;
                imagem_snake = SDL_LoadBMP("snakeImage_left.bmp");
            }
            if(key_pressed.key.keysym.sym == keys.key_up[0] || key_pressed.key.keysym.sym == keys.key_up[1]){
                move_y = -1;
                move_x = 0;

            }
            if(key_pressed.key.keysym.sym == keys.key_down[0] || key_pressed.key.keysym.sym == keys.key_down[1]){
                move_y = 1;
                move_x = 0;
            }

            if(key_pressed.key.keysym.sym == 27){
                show_score();
                printf("SAINDO...");
                exit(0);
                destroy_window(window);
            }
            break;
        }


        snake.sprite_position_dest.x += move_x * acelerate;
        snake.sprite_position_dest.y += move_y * acelerate;
        SDL_Delay(update);
}

int loss_verify(){
    if(move_x != 0 || move_y != 0){
        if(snake.sprite_position_dest.x >= WIDTH-snake.scale){
            snake.sprite_position_dest.x = WIDTH-snake.scale;
            //snake.imagem_snake = SDL_LoadBMP("snakeImage_stand_right.bmp");
            return 1;
        }
        if(snake.sprite_position_dest.x <= 0){
            snake.sprite_position_dest.x = 0;
            //snake.imagem_snake = SDL_LoadBMP("snakeImage_stand_left.bmp");
            return 1;
        }
        if(snake.sprite_position_dest.y >= HEIGHT-snake.scale){
            snake.sprite_position_dest.y = HEIGHT-snake.scale;
            return 1;
        }
        if(snake.sprite_position_dest.y <= 0){
            snake.sprite_position_dest.y = 0;
            return 1;
        }
    }

    else{
        return -1;
    }
}

void score(){
    if(colision(snake,point)==1){
        game_score += 1;
    }
}

void show_score(){
    printf("SCORE: %d\n\n",game_score);
}

int colision(SNAKE obj1,Points obj2){
    if(obj1.sprite_position_dest.x < obj2.point_rect_dest.x + obj2.point_rect_dest.w &&
       obj1.sprite_position_dest.x + obj1.sprite_position_dest.w > obj2.point_rect_dest.x &&
       obj1.sprite_position_dest.y < obj2.point_rect_dest.y + obj2.point_rect_dest.h &&
       obj1.sprite_position_dest.y + obj1.sprite_position_dest.h > obj2.point_rect_dest.y){
        return 1;
    }
    else{
        return 0;
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

void rand_points(){
    point.point_rect_dest.x = rand()%(WIDTH-point.point_size);
    point.point_rect_dest.y = rand()%(HEIGHT-point.point_size);

    //printf("Bolinha!!\nPosiçao x: %d \nPosiçao y: %d \n\n", point.point_rect_dest.x, point.point_rect_dest.y);
}
