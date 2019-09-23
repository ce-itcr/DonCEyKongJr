#include "game.h"

void loadGame(GameState *game) {
    SDL_Surface *surface = NULL;

    surface = IMG_Load("img/background.png");
    if (surface == NULL) {
        printf("Cannot find background.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->background = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/menu2.png");
    if (surface == NULL) {
        printf("Cannot find menu.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->menu = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/jr_a.png");
    if (surface == NULL) {
        printf("Cannot find player_lta.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->playerFrames[0] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/jr_b.png");
    if (surface == NULL) {
        printf("Cannot find player_ltb.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->playerFrames[1] = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/platform.png");
    if (surface == NULL) {
        printf("Cannot find brick.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->brick = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/liana.png");
    if (surface == NULL) {
        printf("Cannot find liana.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->liana = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("img/downplatform.png");
    if (surface == NULL) {
        printf("Cannot find downplatform.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->platform = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);


    surface = IMG_Load("img/safetkey.png");
    if (surface == NULL) {
        printf("Cannot find safetykey.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->safetyKey = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/mario.png");
    if (surface == NULL) {
        printf("Cannot find mario.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->mario = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/jail.png");
    if (surface == NULL) {
        printf("Cannot find mario.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->jail = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/dk.png");
    if (surface == NULL) {
        printf("Cannot find dk.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->dk = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/scoreholder.png");
    if (surface == NULL) {
        printf("Cannot find scoreholder.png!\n\n");
        SDL_Quit();
        exit(1);
    }

    game->scoreholder = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/kremling_blue.png");
    if (surface == NULL) {
        printf("Cannot find kremling_blue.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->blueKremling = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/kremling_red.png");
    if (surface == NULL) {
        printf("Cannot find kremling_red.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->redKremling = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/fruit_bananas.png");
    if (surface == NULL) {
        printf("Cannot find fruit_bananas.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->bananas = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/fruit_oranges.png");
    if (surface == NULL) {
        printf("Cannot find fruit_oranges.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->oranges = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    surface = IMG_Load("img/fruit_strawberry.png");
    if (surface == NULL) {
        printf("Cannot find fruit_strawberry.png!\n\n");
        SDL_Quit();
        exit(1);
    }
    game->strawberry = SDL_CreateTextureFromSurface(game->renderer, surface);
    SDL_FreeSurface(surface);

    game->player.x = 40;
    game->player.y = 240 - 40;
    game->player.dx = 0;
    game->player.dy = 0;
    game->player.onLedge = 0;
    game->player.onLiana = 0;
    game->player.animFrame = 0;
    game->player.facingLeft = 1;
    game->player.slowingDown = 0;
    game->player.onLiana = 0;

    game->sizeMult = 3;
    game->windowPage = 0;

    game->time = 0;

    //init ledges
    for (int i = 0; i < 100; i++) {
        game->ledges[i].w = 256;
        game->ledges[i].h = 20;
        game->ledges[i].x = i * 256;
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

    //init underLedges
    for (int i = 0; i < 100; i++) {
        game->underledges[i].w = 256;
        game->underledges[i].h = 20;
        game->underledges[i].x = i * 256;
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

    for (int i = 0; i < 100; i++) {
        game->lianas[i].w = 256;
        game->lianas[i].h = 20;
        game->lianas[i].x = i * 256;
        game->lianas[i].y = 650;
    }


    game->lianas[89].x = 297;
    game->lianas[89].y = 52;
    game->lianas[89].w = 5;
    game->lianas[89].h = 50;

    game->lianas[90].x = 297;
    game->lianas[90].y = 295;
    game->lianas[90].w = 5;
    game->lianas[90].h = 50;

    game->lianas[91].x = 177;
    game->lianas[91].y = 295;
    game->lianas[91].w = 5;
    game->lianas[91].h = 268;

    game->lianas[92].x = 681;
    game->lianas[92].y = 105;
    game->lianas[92].w = 5;
    game->lianas[92].h = 385;

    game->lianas[93].x = 609;
    game->lianas[93].y = 105;
    game->lianas[93].w = 5;
    game->lianas[93].h = 380;

    game->lianas[94].x = 537;
    game->lianas[94].y = 175;
    game->lianas[94].w = 5;
    game->lianas[94].h = 260;

    game->lianas[95].x = 465;
    game->lianas[95].y = 175;
    game->lianas[95].w = 5;
    game->lianas[95].h = 300;

    game->lianas[96].x = 393;
    game->lianas[96].y = 150;
    game->lianas[96].w = 5;
    game->lianas[96].h = 240;

    game->lianas[97].x = 297;
    game->lianas[97].y = 150;
    game->lianas[97].w = 5;
    game->lianas[97].h = 330;

    game->lianas[98].x = 105;
    game->lianas[98].y = 150;
    game->lianas[98].w = 5;
    game->lianas[98].h = 390;

    game->lianas[99].x = 34;
    game->lianas[99].y = 150;
    game->lianas[99].w = 5;
    game->lianas[99].h = 410;

    for(int i = 0; i < 100; i++){
        game->lianas[i].eCollider.x = game->lianas[i].x;
        game->lianas[i].eCollider.y = game->lianas[i].y;
        game->lianas[i].eCollider.w = game->lianas[i].w;
        game->lianas[i].eCollider.h = game->lianas[i].h;
    }


}

void process(GameState *game){
    game->time++;
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

void collisionDetect(GameState *game) {
    //Check for collision with any ledges
    for (int i = 0; i < 100; i++) {
        float mw = 48, mh = 48;
        float aw = 10, ah = 10;
        float mx = game->player.x, my = game->player.y;
        float bx = game->ledges[i].x, by = game->ledges[i].y, bw = game->ledges[i].w, bh = game->ledges[i].h;
        float ubx = game->underledges[i].x, uby = game->underledges[i].y, ubw = game->underledges[i].w, ubh = game->underledges[i].h;

        //Check collisions for ledges
        if (mx + mw / 2 > bx && mx + mw / 2 < bx + bw) {
            if (my < by + bh && my > by && game->player.dy < 0) {
                game->player.y = by + bh;
                my = by + bh;
                game->player.dy = 0;
                game->player.onLedge = 1;
            }
        }
        if (mx + mw > bx && mx < bx + bw) {
            if (my + mh > by && my < by && game->player.dy > 0) {
                game->player.y = by - mh;
                my = by - mh;
                game->player.dy = 0;
                game->player.onLedge = 1;
            }
        }
        if (my + mh > by && my < by + bh) {
            if (mx < bx + bw && mx + mw > bx + bw && game->player.dx < 0) {
                game->player.x = bx + bw;
                mx = bx + bw;
                game->player.dx = 0;
            } else if (mx + mw > bx && mx < bx && game->player.dx > 0) {
                game->player.x = bx - mw;
                mx = bx - mw;
                game->player.dx = 0;
            }
        }

        //Check collisions for underledges
        if (mx + mw / 2 > ubx && mx + mw / 2 < ubx + ubw) {
            if (my < uby + ubh && my > uby && game->player.dy < 0) {
                game->player.y = uby + ubh;
                my = by + ubh;
                game->player.dy = 0;
                game->player.onLedge = 1;
            }
        }
        if (mx + mw > ubx && mx < ubx + ubw) {
            if (my + mh > uby && my < uby && game->player.dy > 0) {
                game->player.y = uby - mh;
                my = uby - mh;
                game->player.dy = 0;
                game->player.onLedge = 1;
            }
        }
        if (my + mh > uby && my < uby + ubh) {
            if (mx < ubx + bw && mx + mw > ubx + bw && game->player.dx < 0) {
                game->player.x = ubx + ubw;
                mx = ubx + ubw;
                game->player.dx = 0;
            } else if (mx + mw > ubx && mx < ubx && game->player.dx > 0) {
                game->player.x = bx - mw;
                mx = ubx - mw;
                game->player.dx = 0;
            }

        }

    }
}

void ObjectCollision(GameState* game){
    SDL_Rect pCollider = {game->player.x, game->player.y, 48, 48};
    for(int i = 0; i < lists->numOfCrocodiles;i++){
        if(checkCollision(pCollider,lists->cocrodileList[i].eCollider)){
            game->player.life--;
            lists->commOn = 1;
        }
    }
    for(int i = 0; i < lists->numOfFruits;i++) {
        if (checkCollision(pCollider, lists->fruitList[i].eCollider) && lists->fruitList[i].alive) {
            printf("for %d\n", i);
            lists->score += lists->fruitList[i].score;
            lists->fruitList[i].alive = 0;
            lists->fruitsAlive[i] = 0;
            lists->commOn = 1;
        }
    }

    for(int i = 0; i < 100;i++) {
        if (checkCollision(pCollider, game->lianas[i].eCollider)) {
            game->player.dy = 0;
            game->player.onLiana = 1;
            break;
        }
        game->player.onLiana = 0;
    }
}

bool checkCollision(SDL_Rect a, SDL_Rect b){
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;

    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if( bottomA <= topB ){
        return false;
    }
    if( topA >= bottomB ){
        return false;
    }
    if( rightA <= leftB ){
        return false;
    }
    if( leftA >= rightB ){
        return false;
    }


    return true;
}

int processEvents(SDL_Window *window, GameState *game) {
    SDL_Event event;
    int done = 0;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_WINDOWEVENT_CLOSE: {
                if (window) {
                    SDL_DestroyWindow(window);
                    window = NULL;
                    done = 1;
                }
            }
                break;
            case SDL_KEYDOWN: {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        done = 1;
                        break;
                    case SDLK_UP:
                        if(game->player.onLedge) {
                            game->player.dy = -8;
                            game->player.onLedge = 0;
                        }
                        else if(game->player.onLiana) {
                            game->player.dy = -10;
                            game->player.onLiana = 0;
                        }
                        break;
                    case SDLK_DOWN:
                        if(game->player.onLiana){
                            game->player.dy = 8;
                            game->player.onLiana = 0;
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

    if (game->windowPage == 0 && event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            int mouseX, mouseY;
            SDL_GetMouseState(&mouseX, &mouseY);

            if (playGame_btn(game, mouseX, mouseY)) {
                game->windowPage = 1;
            }
        }
    }

    //More jumping
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_UP]) {
        game->player.dy -= 0.2f;
    }

    //Walking
    if (state[SDL_SCANCODE_LEFT]) {
        game->player.dx -= 0.5;
        if (game->player.dx < -6) {
            game->player.dx = -6;
        }
        game->player.facingLeft = 1;
        game->player.slowingDown = 0;
    } else if (state[SDL_SCANCODE_RIGHT]) {
        game->player.dx += 0.5;
        if (game->player.dx > 6) {
            game->player.dx = 6;
        }
        game->player.facingLeft = 0;
        game->player.slowingDown = 0;
    } else {
        game->player.animFrame = 0;
        game->player.dx *= 0.8f;
        game->player.slowingDown = 1;
        if (fabsf(game->player.dx) < 0.1f) {
            game->player.dx = 0;
        }
    }
    return done;
}

int playGame_btn(GameState *game, int mouseX, int mouseY){
    int playXLeft = 12*8*game->sizeMult;
    int playXRight = 19*8*game->sizeMult;
    int playYDown = (248*game->sizeMult)-(6*8*game->sizeMult);
    int playYUp = (248*game->sizeMult)-(10*8*game->sizeMult);

    if ((mouseX > playXLeft && mouseX < playXRight) == 0){
        return 0;
    }
    if ((mouseY > playYUp && mouseY < playYDown) == 0){
        return 0;
    }
    return 1;
}

void doRender(SDL_Renderer *renderer, GameState *game){

    if(game->windowPage == 0){
        SDL_Rect menuRect = {0, 0,  248*3, 216*3};
        SDL_RenderCopy(game->renderer, game->menu, NULL, &menuRect);
    }
    if(game->windowPage == 1){

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

        SDL_Rect scoreholderRect = {540,0, 200, 100};
        SDL_RenderCopy(game->renderer, game->scoreholder, NULL, &scoreholderRect);

        for(int i = 0; i < 100; i++){
            SDL_Rect ledgeRect = { game->ledges[i].x, game->ledges[i].y, game->ledges[i].w, game->ledges[i].h };
            SDL_RenderCopy(renderer, game->brick, NULL, &ledgeRect);
        }

        for(int i = 0; i < 100; i++){
            SDL_Rect underledges = { game->underledges[i].x, game->underledges[i].y, game->underledges[i].w, game->underledges[i].h };
            SDL_RenderCopy(renderer, game->platform, NULL, &underledges);
        }

        for(int i = 0; i < 100; i++){
            SDL_Rect lianasRect = { game->lianas[i].x, game->lianas[i].y, game->lianas[i].w, game->lianas[i].h };
            SDL_RenderCopy(renderer, game->liana, NULL, &lianasRect);
        }

        for(int i = 0; i < lists->numOfFruits; i++){
            if(lists->fruitList[i].alive) {
                SDL_Rect fruits = {lists->fruitList[i].eCollider.x, lists->fruitList[i].eCollider.y,
                                   lists->fruitList[i].eCollider.w, lists->fruitList[i].eCollider.h};
                if (lists->fruitList[i].species == 0) {
                    SDL_RenderCopy(renderer, game->bananas, NULL, &fruits);
                } else if (lists->fruitList[i].species == 1) {
                    SDL_RenderCopy(renderer, game->oranges, NULL, &fruits);
                } else {
                    SDL_RenderCopy(renderer, game->strawberry, NULL, &fruits);
                }
            }
        }

        for(int i = 0; i < lists->numOfCrocodiles; i++){
            SDL_Rect crocodile = {lists->cocrodileList[i].eCollider.x, lists->cocrodileList[i].eCollider.y, lists->cocrodileList[i].eCollider.w, lists->cocrodileList[i].eCollider.h};
            if(lists->cocrodileList[i].species == 0){
                SDL_RenderCopy(renderer, game->blueKremling, NULL, &crocodile);
            }else{
                SDL_RenderCopy(renderer, game->redKremling, NULL, &crocodile);
            }
        }

        //draw a rectangle at player's position
        SDL_Rect rect = { game->player.x, game->player.y, 70, 70};
        SDL_RenderCopyEx(renderer, game->playerFrames[game->player.animFrame],
                         NULL, &rect, 0, NULL, (game->player.facingLeft == 0));

    }

    //We are done drawing, "present" or show to the screen what we've drawn
    SDL_RenderPresent(renderer);
}

void updateFruitsAndCrocodiles(){
    printf("%d\n",lists->currentNumberOfCrocodiles);
    printf("%d\n",lists->currentNumberOfFruits);
    printf("%d\n",lists->numOfCrocodiles);
    printf("%d\n",lists->numOfFruits);
    for(int i = lists->currentNumberOfFruits; i < lists->numOfFruits;i++) {
        lists->fruitList[i].eCollider.x = lists->fruitList[i].posX;
        lists->fruitList[i].eCollider.y = lists->fruitList[i].posY;
        lists->fruitList[i].eCollider.h = 25;
        lists->fruitList[i].eCollider.w = 40;
    }
    lists->currentNumberOfFruits = lists->numOfFruits;
    for(int i = lists->currentNumberOfCrocodiles; i < lists->numOfCrocodiles; i++){
        lists->cocrodileList[i].eCollider.x = lists->cocrodileList[i].posX;
        lists->cocrodileList[i].eCollider.y = lists->cocrodileList[i].posY;
        lists->cocrodileList[i].eCollider.h = 50;
        lists->cocrodileList[i].eCollider.w = 50;
    }
    lists->currentNumberOfCrocodiles = lists->numOfCrocodiles;
}

void closeGame(SDL_Window *window, GameState *game, SDL_Renderer *renderer){
    //Shutdown game and unload all memory
    SDL_DestroyTexture(game->playerFrames[0]);
    SDL_DestroyTexture(game->playerFrames[1]);
    SDL_DestroyTexture(game->brick);
    SDL_DestroyTexture(game->platform);
    SDL_DestroyTexture(game->safetyKey);
    SDL_DestroyTexture(game->mario);
    SDL_DestroyTexture(game->dk);
    SDL_DestroyTexture(game->jail);
    SDL_DestroyTexture(game->background);
    SDL_DestroyTexture(game->menu);
    SDL_DestroyTexture(game->scoreholder);

    // Close and destroy the window
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);

    // Clean up
    SDL_Quit();
}