//
// Created by jesquivel on 9/18/19.
//

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

char* enviar(char* Mensaje);
char* escuchar();

#endif //DONCEYKONGJR_SOCKETCLIENT_H
