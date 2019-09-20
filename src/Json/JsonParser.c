//
// Created by ivan on 9/15/19.
//

#include "JsonParser.h"
#include "cJSON.h"
#include <stdio.h>

Crocodile getCrocodileByNumber(char *json, int n){
    int species = getIntValueInJson(json, "crocodiles", n, "species");
    int posX = getIntValueInJson(json, "crocodiles", n, "posX");
    int posY = getIntValueInJson(json, "crocodiles", n, "posY");
    int alive = getIntValueInJson(json, "crocodiles", n, "alive");
    Crocodile crocodile = {.alive = alive, .posX = posX, .posY = posY, .species = species};
    return crocodile;
}

int getIntValueInJson(char *json, char *array, int i, char *data){
    cJSON *parsedJson = cJSON_Parse(json);
    cJSON *arr = cJSON_GetObjectItemCaseSensitive(parsedJson, array);
    cJSON *obj = cJSON_GetArrayItem(arr, i);
    cJSON *intValue = cJSON_GetObjectItemCaseSensitive(obj, data);
    return intValue->valueint;
}

Fruit getFruitByNumber(char *json, int n) {
    int species = getIntValueInJson(json, "fruits", n, "species");
    int posX = getIntValueInJson(json, "fruits", n, "posX");
    int posY = getIntValueInJson(json, "fruits", n, "posY");
    int alive = getIntValueInJson(json, "fruits", n, "alive");
    int score = getIntValueInJson(json, "fruits", n, "score");
    Fruit fruit = {.alive = alive, .posX = posX, .posY = posY, .species = species, .score = score};
    return fruit;
}

