//
// Created by jesquivel on 9/20/19.
//

#include "communication.h"

void startCommunication(){
    while(lists->gameON){
        enviar(escuchar());
    }
}