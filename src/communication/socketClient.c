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
//
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
    printf("p0.15519\n");
    struct sockaddr_in address;
    int sock, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
    }
//
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
    valread = read( sock , buffer, 1024);
    printf("%s\n", buffer);
    close(sock);
    return buffer;
}