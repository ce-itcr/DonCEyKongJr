#include "socketClient.h"

#define PORT 8080

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
    if(inet_pton(AF_INET, "192.168.0.14", &serv_addr.sin_addr)<=0)
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
    if(inet_pton(AF_INET, "192.168.0.14", &serv_addr.sin_addr)<=0)
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
//    while(valread) {
//        buffer[valread]='\0';    // explicit null termination: updated based on comments
//        printf("%s\n",valread); // print the current receive buffer with a newline
//        fflush(stdout);         // make sure everything makes it to the output
//        buffer[0]='\0';         // clear the buffer : I am 99% sure this is not needed now
//        valread--;
//    }
    return buffer;
}