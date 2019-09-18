/* 
 main.c - main file to run the DonCEKongJr client application.

 This file is part of DonCE Y Kong Jr, the same correspondent to Project III for the course of Languages, Compilers and Interpreters. (CE3104), Languages module.
 The project consists in the implementation of an application that reaffirms the knowledge of the imperative and object-oriented programming paradigms.
 For more information about the project visit: https://github.com/ce-itcr/DonCEyKongJr

 File Version    : 1.0
 Authors         : Github @ angelortizv
 Last modified   : 09/17/2019, 16:00, @angelortizv
*/

#include <stdio.h>
#include "src/communication/socketClient.h"
#include "src/app/Interface.h"

int main(int argc, char *argv[]){
    gtk_init(&argc,&argv);
    loadInterface();
    gtk_main();

    enviar("Hola");
    escuchar();
    return EXIT_SUCCESS;
}