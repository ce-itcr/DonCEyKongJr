/*
 controller.c - interface between game functions and client-server communication

 This file is part of DonCE Y Kong Jr, the same correspondent to Project III for the course of Languages, Compilers and Interpreters. (CE3104), Languages module.
 The project consists in the implementation of an application that reaffirms the knowledge of the imperative and object-oriented programming paradigms.
 For more information about the project visit: https://github.com/ce-itcr/DonCEyKongJr

 File Version    : 1.0
 Authors         : Github@angelortizv, Github@jesquivel48
 Last modified   : 22/09/2019, 22:50, @angelortizv
*/

#ifndef DONCEYKONGJR_CONTROLLER_H
#define DONCEYKONGJR_CONTROLLER_H

#include "app/game.h"
#include "communication/socketClient.h"
#include "communication/JsonParser.h"
#include <pthread.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

void runGame();
void* runCommunication(void* arg);
void* runGameThread(void* arg);

#endif //DONCEYKONGJR_CONTROLLER_H
