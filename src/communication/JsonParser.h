//
// Created by ivan on 9/15/19.
//

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
