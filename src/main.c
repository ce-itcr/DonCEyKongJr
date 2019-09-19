/* 
 main.c - main file to run the DonCEKongJr client application.

 This file is part of DonCE Y Kong Jr, the same correspondent to Project III for the course of Languages, Compilers and Interpreters. (CE3104), Languages module.
 The project consists in the implementation of an application that reaffirms the knowledge of the imperative and object-oriented programming paradigms.
 For more information about the project visit: https://github.com/ce-itcr/DonCEyKongJr

 File Version    : 1.0
 Authors         : Github @ angelortizv
 Last modified   : 19/09/2019, 00:20, @angelortizv
*/

#include <stdio.h>
#include "communication/socketClient.h"
#include "controller.h"

int main(int argc, char *argv[]){

    runGame();

    enviar("communication tests");
    escuchar();
    return EXIT_SUCCESS;
}