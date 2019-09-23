#include "controller.h"

GameState gameState;
SDL_Window *window;
SDL_Renderer *renderer;

void runGame(){
    lists->gameOn = 1;
    lists->score = 0;
    lists->hp = 1;
    lists->commOn = 0;

    window = NULL;
    renderer = NULL;

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

    pthread_t tid;
    pthread_create(&tid,NULL,runGameThread,(void *)&tid);
//    pthread_create(&tid,NULL,runCommunication,(void *)&tid);
    pthread_join(tid,NULL);
}

void* runCommunication(void* arg){
    escuchar();
    while(lists->gameOn){
        if(lists->commOn){
            char *string = updateJsonFromStruct();
            printf("holi\n");
            printf("%s\n", string);
            printf("holi2\n");
            enviar(string);
            escuchar();
        }
        sleep(5);
    }
    pthread_exit(0);
}

void* runGameThread(void* arg){
    // The window is open: enter program loop (see SDL_PollEvent)
    int done = 0;

    //Event loop
    while(!done){
        done = processEvents(window, &gameState);
        process(&gameState);
        collisionDetect(&gameState);
        ObjectCollision(&gameState);
        doRender(renderer, &gameState);
    }

    closeGame(window, &gameState, renderer);
    pthread_exit(0);
}