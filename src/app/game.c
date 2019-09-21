/*
 game.c -

 This file is part of DonCE Y Kong Jr, the same correspondent to Project III for the course of Languages, Compilers and Interpreters. (CE3104), Languages module.
 The project consists in the implementation of an application that reaffirms the knowledge of the imperative and object-oriented programming paradigms.
 For more information about the project visit: https://github.com/ce-itcr/DonCEyKongJr

 File Version    : 1.0
 Authors         : Github @ angelortizv
 Last modified   : 19/09/2019, 00:20, @angelortizv
*/

#include "game.h"

void loadGame(GameState *game){
    SDL_Surface *surface = NULL;

    surface = IMG_Load("img/background.png");
    if(surface == NULL){
        printf("Cannot find background.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->background = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/menu.png");
    if(surface == NULL){
        printf("Cannot find menu.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->menu = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/jr_a.png");
    if(surface == NULL){
        printf("Cannot find player_lta.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->playerFrames[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/jr_b.png");
    if(surface == NULL){
        printf("Cannot find player_ltb.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->playerFrames[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/platform.png");
    if(surface == NULL){
        printf("Cannot find brick.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->brick = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/downplatform.png");
    if(surface == NULL){
        printf("Cannot find downplatform.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->platform = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("img/safetkey.png");
    if(surface == NULL){
        printf("Cannot find safetykey.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->safetyKey = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/mario.png");
    if(surface == NULL){
        printf("Cannot find mario.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->mario = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/jail.png");
    if(surface == NULL){
        printf("Cannot find mario.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->jail = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/dk.png");
    if(surface == NULL){
        printf("Cannot find dk.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->dk = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/scoreholder.png");
    if(surface == NULL){
        printf("Cannot find scoreholder.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->scoreholder = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);


    game->player.x = 40;
    game->player.y = 240-40;
    game->player.dx = 0;
    game->player.dy = 0;
    game->player.onLedge = 0;
    game->player.animFrame = 0;
    game->player.facingLeft = 1;
    game->player.slowingDown = 0;

    game->time = 0;

    //init ledges
    for(int i = 0; i < 100; i++){
        game->ledges[i].w = 256;
        game->ledges[i].h = 20;
        game->ledges[i].x = i*256;
        game->ledges[i].y = 650;
    }

    game->ledges[94].x = 552;
    game->ledges[94].y = 368;
    game->ledges[94].w = 190;
    game->ledges[94].h = 22;

    game->ledges[95].x = 405;
    game->ledges[95].y = 176;
    game->ledges[95].w = 195;
    game->ledges[95].h = 22;

    game->ledges[96].x = 190;
    game->ledges[96].y = 80;
    game->ledges[96].w = 75;
    game->ledges[96].h = 22;

    game->ledges[97].x = 0;
    game->ledges[97].y = 155;
    game->ledges[97].w = 432;
    game->ledges[97].h = 22;

    game->ledges[98].x = 120;
    game->ledges[98].y = 295;
    game->ledges[98].w = 96;
    game->ledges[98].h = 22;

    game->ledges[99].x = 120;
    game->ledges[99].y = 415;
    game->ledges[99].w = 145;
    game->ledges[99].h = 22;

    for(int i = 0; i < 100; i++){
        game->underledges[i].w = 256;
        game->underledges[i].h = 20;
        game->underledges[i].x = i*256;
        game->underledges[i].y = 650;
    }

    game->underledges[95].x = 600;
    game->underledges[95].y = 530;
    game->underledges[95].w = 100;
    game->underledges[95].h = 200;

    game->underledges[96].x = 480;
    game->underledges[96].y = 550;
    game->underledges[96].w = 95;
    game->underledges[96].h = 140;

    game->underledges[97].x = 380;
    game->underledges[97].y = 585;
    game->underledges[97].w = 80;
    game->underledges[97].h = 140;

    game->underledges[98].x = 260;
    game->underledges[98].y = 550;
    game->underledges[98].w = 100;
    game->underledges[98].h = 140;

    game->underledges[99].x = 0;
    game->underledges[99].y = 618;
    game->underledges[99].w = 188;
    game->underledges[99].h = 100;

}

void process(GameState *game){
    //add time
    game->time++;

    //player movement
    DKJr *player = &game->player;
    player->x += player->dx;
    player->y += player->dy;

    if(player->dx != 0 && player->onLedge && !player->slowingDown){
        if(game->time % 8 == 0){
            if(player->animFrame == 0){
                player->animFrame = 1;
            }
            else{
                player->animFrame = 0;
            }
        }
    }

    player->dy += GRAVITY;
}

void collisionDetect(GameState *game){
    //Check for collision with any ledges (brick blocks)
    for(int i = 0; i < 100; i++){
        float mw = 48, mh = 48;
        float mx = game->player.x, my = game->player.y;
        float bx = game->ledges[i].x, by = game->ledges[i].y, bw = game->ledges[i].w, bh = game->ledges[i].h;
        float ubx = game->underledges[i].x, uby = game->underledges[i].y, ubw = game->underledges[i].w, ubh = game->underledges[i].h;

        //Check collisions for ledges
        if(mx+mw/2 > bx && mx+mw/2<bx+bw){
            if(my < by+bh && my > by && game->player.dy < 0){
                game->player.y = by+bh;
                my = by+bh;
                game->player.dy = 0;
                game->player.onLedge = 1;
            }
        }
        if(mx+mw > bx && mx<bx+bw){
            if(my+mh > by && my < by && game->player.dy > 0){
                game->player.y = by-mh;
                my = by-mh;
                game->player.dy = 0;
                game->player.onLedge = 1;
            }
        }
        if(my+mh > by && my<by+bh){
            if(mx < bx+bw && mx+mw > bx+bw && game->player.dx < 0){
                game->player.x = bx+bw;
                mx = bx+bw;
                game->player.dx = 0;
            }
            else if(mx+mw > bx && mx < bx && game->player.dx > 0){
                game->player.x = bx-mw;
                mx = bx-mw;
                game->player.dx = 0;
            }
        }

        //Check collisions for underledges
        if(mx+mw/2 > ubx && mx+mw/2<ubx+ubw){
            if(my < uby+ubh && my > uby && game->player.dy < 0){
                game->player.y = uby+ubh;
                my = by+ubh;
                game->player.dy = 0;
                game->player.onLedge = 1;
            }
        }
        if(mx+mw > ubx && mx<ubx+ubw){
            if(my+mh > uby && my < uby && game->player.dy > 0){
                game->player.y = uby-mh;
                my = uby-mh;
                game->player.dy = 0;
                game->player.onLedge = 1;
            }
        }
        if(my+mh > uby && my<uby+ubh){
            if(mx < ubx+bw && mx+mw > ubx+bw && game->player.dx < 0){
                game->player.x = ubx+ubw;
                mx = ubx+ubw;
                game->player.dx = 0;
            }
            else if(mx+mw > ubx && mx < ubx && game->player.dx > 0){
                game->player.x = bx-mw;
                mx = ubx-mw;
                game->player.dx = 0;
            }
        }

    }
}

int processEvents(SDL_Window *window, GameState *game){
    SDL_Event event;
    int done = 0;

    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_WINDOWEVENT_CLOSE:{
                if(window){
                    SDL_DestroyWindow(window);
                    window = NULL;
                    done = 1;
                }
            }
                break;
            case SDL_KEYDOWN:{
                switch(event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        done = 1;
                        break;
                    case SDLK_UP:
                        if(game->player.onLedge){
                            game->player.dy = -8;
                            game->player.onLedge = 0;
                        }
                        break;
                }
            }
                break;
            case SDL_QUIT:
                //quit out of the game
                done = 1;
                break;
        }
    }

    //More jumping
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if(state[SDL_SCANCODE_UP]){
        game->player.dy -= 0.2f;
    }

    //Walking
    if(state[SDL_SCANCODE_LEFT]){
        game->player.dx -= 0.5;
        if(game->player.dx < -6){
            game->player.dx = -6;
        }
        game->player.facingLeft = 1;
        game->player.slowingDown = 0;
    }
    else if(state[SDL_SCANCODE_RIGHT]){
        game->player.dx += 0.5;
        if(game->player.dx > 6){
            game->player.dx = 6;
        }
        game->player.facingLeft = 0;
        game->player.slowingDown = 0;
    }
    else{
        game->player.animFrame = 0;
        game->player.dx *= 0.8f;
        game->player.slowingDown = 1;
        if(fabsf(game->player.dx) < 0.1f){
            game->player.dx = 0;
        }
    }
    return done;
}

void doRender(SDL_Renderer *renderer, GameState *game){

    //SDL_RenderClear(renderer);

    SDL_Rect backgroundRect = {0,0, 248*3, 216*3};
    SDL_RenderCopy(game->renderer, game->background, NULL, &backgroundRect);

    SDL_Rect safetykeyRect = {275,10, 50, 50};
    SDL_RenderCopy(game->renderer, game->safetyKey, NULL, &safetykeyRect);

    SDL_Rect marioRect = {175,100, 75, 75};
    SDL_RenderCopy(game->renderer, game->mario, NULL, &marioRect);

    SDL_Rect jailRect = {20,50, 150, 100};
    SDL_RenderCopy(game->renderer, game->jail, NULL, &jailRect);

    SDL_Rect dkRect = {65,60, 70, 65};
    SDL_RenderCopy(game->renderer, game->dk, NULL, &dkRect);

    SDL_Rect scoreholderRect = {570,0, 150, 95};
    SDL_RenderCopy(game->renderer, game->scoreholder, NULL, &scoreholderRect);

    for(int i = 0; i < 100; i++){
        SDL_Rect ledgeRect = { game->ledges[i].x, game->ledges[i].y, game->ledges[i].w, game->ledges[i].h };
        SDL_RenderCopy(renderer, game->brick, NULL, &ledgeRect);
    }

    for(int i = 0; i < 100; i++){
        SDL_Rect underledges = { game->underledges[i].x, game->underledges[i].y, game->underledges[i].w, game->underledges[i].h };
        SDL_RenderCopy(renderer, game->platform, NULL, &underledges);
    }

    //draw a rectangle at player's position
    SDL_Rect rect = { game->player.x, game->player.y, 70, 70};
    SDL_RenderCopyEx(renderer, game->playerFrames[game->player.animFrame],
                     NULL, &rect, 0, NULL, (game->player.facingLeft == 0));





    //We are done drawing, "present" or show to the screen what we've drawn
    SDL_RenderPresent(renderer);
}

void runner(){
    GameState gameState;
    SDL_Window *window;

    window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    //Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    //backgroundSound = Mix_LoadMUS("audio/Stage1.mp3");
    //Mix_PlayMusic(backgroundSound, -1);

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL2
    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    int initted=IMG_Init(flags);

    srandom((int)time(NULL));

    //Create an application window with the following settings:
    window = SDL_CreateWindow("DonCE Y Kong Jr",                     // window title
                              SDL_WINDOWPOS_UNDEFINED,           // initial x position
                              SDL_WINDOWPOS_UNDEFINED,           // initial y position
                              248*3,                               // width, in pixels
                              216*3,                               // height, in pixels
                              0                                  // flags
    );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    gameState.renderer = renderer;

    loadGame(&gameState);

    // The window is open: enter program loop (see SDL_PollEvent)
    int done = 0;

    //Event loop
    while(!done){
        //Check for events
        done = processEvents(window, &gameState);

        process(&gameState);
        collisionDetect(&gameState);

        //Render display
        doRender(renderer, &gameState);
    }

    //Shutdown game and unload all memory
    SDL_DestroyTexture(gameState.playerFrames[0]);
    SDL_DestroyTexture(gameState.playerFrames[1]);
    SDL_DestroyTexture(gameState.brick);
    SDL_DestroyTexture(gameState.platform);
    SDL_DestroyTexture(gameState.safetyKey);
    SDL_DestroyTexture(gameState.mario);
    SDL_DestroyTexture(gameState.dk);
    SDL_DestroyTexture(gameState.jail);
    SDL_DestroyTexture(gameState.background);
    SDL_DestroyTexture(gameState.menu);
    SDL_DestroyTexture(gameState.scoreholder);

    // Close and destroy the window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    // Clean up
    SDL_Quit();
}