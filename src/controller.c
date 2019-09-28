#include "controller.h"

GameState gameState;
SDL_Window *window;
SDL_Renderer *renderer;


// Name : runGame
// Parameters: N/A
// Brief: Creates the render, the game window and runs the two main threads
// Use: main.c - main
void runGame(){
    lists->gameOn = 1;
    lists->score = 0;
    lists->hp = 1;
    lists->commOn = 0;

    window = NULL;
    renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();

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
    pthread_create(&tid,NULL,runCommunication,(void *)&tid);
    pthread_create(&tid,NULL,setupArduinoComm,(void *)&tid);
    pthread_join(tid,NULL);
}

// Name : runCommunication
// Parameters: N/A
// Brief: runs the communication loop
// Use: controller.c - runGame
void* runCommunication(void* arg){
    listener();
    while(lists->gameOn){
        if(lists->commOn){
            char *string = updateJsonFromStruct();
            printf("%s\n", string);
            sendData(string);
            listener();
        }
        sleep(5);
    }
    pthread_exit(0);
}

// Name : runGameThread
// Parameters: N/A
// Brief: runs the game loop
// Use: controller.c - runGame
void* runGameThread(void* arg){
    int done = 0;
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