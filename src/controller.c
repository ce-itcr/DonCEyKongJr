#include "controller.h"

void runGame(){
    lists->gameOn = 1;

    GameState gameState;
    SDL_Window *window;

    window = NULL;
    SDL_Renderer *renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    int initted=IMG_Init(flags);

    srandom((int)time(NULL));

    window = SDL_CreateWindow("DonCE Y Kong Jr",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              248*3,
                              216*3,
                              0
    );
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    gameState.renderer = renderer;

    loadGame(&gameState);

    // The window is open: enter program loop (see SDL_PollEvent)
    int done = 0;

    //Event loop
    while(!done){
        done = processEvents(window, &gameState);
        process(&gameState);
        collisionDetect(&gameState);
        doRender(renderer, &gameState);
    }

    closeGame(window, &gameState, renderer);


//    pthread_t tid;
//    pthread_create(&tid,NULL,runGameThread,(void *)&tid);
//    pthread_create(&tid,NULL,runCommunication,(void *)&tid);
//    pthread_join(tid,NULL);
}

void* runCommunication(void* arg){
    while(lists->gameOn){
        escuchar();
    }
    pthread_exit(0);
}

void* runGameThread(void* arg){
//    int done = 0;
//    printf("entro\n");
//    while(!done){
//        done = processEvents(window, &game);
//        doRender(renderer, &game);
//        SDL_Delay(10);
//    }
//    closeGame(window, &game);
//    pthread_exit(0);
}