/*
 controller.c -

 This file is part of DonCE Y Kong Jr, the same correspondent to Project III for the course of Languages, Compilers and Interpreters. (CE3104), Languages module.
 The project consists in the implementation of an application that reaffirms the knowledge of the imperative and object-oriented programming paradigms.
 For more information about the project visit: https://github.com/ce-itcr/DonCEyKongJr

 File Version    : 1.0
 Authors         : Github @ angelortizv
 Last modified   : 19/09/2019, 00:20, @angelortizv
*/

#include "controller.h"

GameState game;
SDL_Window* window = NULL;

void runGame(){
    initializeGame(window, &game);
    loadGame(&game);
    lists->gameOn = 1;
    SDL_Renderer *renderer = NULL;
    int done = 0;
    while(!done){
        done = processEvents(window, &game);
        doRender(renderer, &game);
        SDL_Delay(10);
    }

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
    SDL_Renderer *renderer = NULL;
    int done = 0;
    printf("entro\n");
    while(!done){
        done = processEvents(window, &game);
        doRender(renderer, &game);
        SDL_Delay(10);
    }
    closeGame(window, &game);
    pthread_exit(0);
}