/*
 socketClient.h -

 This file is part of DonCE Y Kong Jr, the same correspondent to Project III for the course of Languages, Compilers and Interpreters. (CE3104), Languages module.
 The project consists in the implementation of an application that reaffirms the knowledge of the imperative and object-oriented programming paradigms.
 For more information about the project visit: https://github.com/ce-itcr/DonCEyKongJr

 File Version    : 1.0
 Authors         : Github @ angelortizv
 Last modified   : 18/17/2019, 16:00, @jesquivel48
*/

#ifndef DONCEYKONGJR_SOCKETCLIENT_H
#define DONCEYKONGJR_SOCKETCLIENT_H

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "JsonParser.h"
#include "../app/game.h"

char* enviar(char* Mensaje);
char* escuchar();

#endif //DONCEYKONGJR_SOCKETCLIENT_H
