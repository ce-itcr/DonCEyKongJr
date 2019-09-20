/*
 socketClient.c -

 This file is part of DonCE Y Kong Jr, the same correspondent to Project III for the course of Languages, Compilers and Interpreters. (CE3104), Languages module.
 The project consists in the implementation of an application that reaffirms the knowledge of the imperative and object-oriented programming paradigms.
 For more information about the project visit: https://github.com/ce-itcr/DonCEyKongJr

 File Version    : 1.0
 Authors         : Github@angelortizv, Github@jesquivel48, Github@isolis2000
 Last modified   : 18/17/2019, 16:00, @jesquivel48
*/

#include "socketClient.h"

#define PORT 8080

Socket() {
}

char* enviar(char* Mensaje) {
    printf("p0.15519\n");
    struct sockaddr_in address;
    int sock, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    printf("p0.25\n");
    if(inet_pton(AF_INET, "192.168.0.21", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
    }
    printf("p0.5\n");
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
    }
    printf("p1\n");
    strcpy(buffer, Mensaje);
    sleep(1);
    send(sock, buffer, strlen(buffer),0 );
//    printf("Hello message sent\n");
    close(sock);
    return "";
}

char* escuchar()
{
    struct sockaddr_in address;
    int sock, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
    }

    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "192.168.0.21", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
    }
    valread = read( sock , buffer, 1024);
    printf("%s\n", buffer);
    updateEntities(buffer);
    close(sock);
    return buffer;
}