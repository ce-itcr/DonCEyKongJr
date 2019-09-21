/*
 JsonParser.h -

 This file is part of DonCE Y Kong Jr, the same correspondent to Project III for the course of Languages, Compilers and Interpreters. (CE3104), Languages module.
 The project consists in the implementation of an application that reaffirms the knowledge of the imperative and object-oriented programming paradigms.
 For more information about the project visit: https://github.com/ce-itcr/DonCEyKongJr

 File Version    : 1.0
 Authors         : Github@angelortizv, Github@jesquivel48, Github@isolis2000
 Last modified   : 21/09/2019, 13:00, @isolis2000
*/

#ifndef JSON_JSONPARSER_H
#define JSON_JSONPARSER_H

#include "../app/game.h"
#include "cJSON.h"
#include <stdio.h>

Crocodile getCrocodileByNumber(char *json, int n);
void updateEntities(char *json);
Fruit getFruitByNumber(char *json, int n);
int getIntValueInJsonArray(char *json, char *arr, int i, char *data);
int getIntValueInJson(char *json, char *data);

#endif //JSON_JSONPARSER_H
