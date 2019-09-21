//
// Created by ivan on 9/15/19.
//

#include "JsonParser.h"

Crocodile getCrocodileByNumber(char *json, int n){
    int species = getIntValueInJsonArray(json, "crocodiles", n, "species");
    int posX = getIntValueInJsonArray(json, "crocodiles", n, "posX");
    int posY = getIntValueInJsonArray(json, "crocodiles", n, "posY");
    int alive = getIntValueInJsonArray(json, "crocodiles", n, "alive");
    Crocodile crocodile = {.alive = alive, .posX = posX, .posY = posY, .species = species};
    return crocodile;
}

void updateEntities(char *json){
    lists->numOfCrocodiles = getIntValueInJson(json, "numOfCrocodiles");
    lists->numOfFruits = getIntValueInJson(json, "numOfFruits");
    for (int i = 0; i < lists->numOfCrocodiles; i++){
        Crocodile tmpCrocodile = getCrocodileByNumber(json, i);
        lists->cocrodileList[i].species = tmpCrocodile.species;
        lists->cocrodileList[i].posX = tmpCrocodile.posX;
        lists->cocrodileList[i].posY = tmpCrocodile.posY;
        lists->cocrodileList[i].alive = tmpCrocodile.alive;
    }
    for (int i = 0; i < lists->numOfFruits; i++){
        Fruit tmpFruit = getFruitByNumber(json, i);
        lists->fruitList[i].species = tmpFruit.species;
        lists->fruitList[i].posX = tmpFruit.posX;
        lists->fruitList[i].posY = tmpFruit.posY;
        lists->fruitList[i].alive = tmpFruit.alive;
        lists->fruitList[i].score = tmpFruit.score;
    }

}

int getIntValueInJsonArray(char *json, char *array, int i, char *data){
    cJSON *parsedJson = cJSON_Parse(json);
    cJSON *arr = cJSON_GetObjectItemCaseSensitive(parsedJson, array);
    cJSON *obj = cJSON_GetArrayItem(arr, i);
    cJSON *intValue = cJSON_GetObjectItemCaseSensitive(obj, data);
    int intToReturn = intValue->valueint;
    cJSON_Delete(parsedJson);
    return intToReturn;
}

Fruit getFruitByNumber(char *json, int n) {
    int species = getIntValueInJsonArray(json, "fruits", n, "species");
    int posX = getIntValueInJsonArray(json, "fruits", n, "posX");
    int posY = getIntValueInJsonArray(json, "fruits", n, "posY");
    int alive = getIntValueInJsonArray(json, "fruits", n, "alive");
    int score = getIntValueInJsonArray(json, "fruits", n, "score");
    Fruit fruit = {.alive = alive, .posX = posX, .posY = posY, .species = species, .score = score};
    return fruit;
}

int getIntValueInJson(char *json, char *data){
    cJSON *parsedJson = cJSON_Parse(json);
    cJSON *intValue = cJSON_GetObjectItemCaseSensitive(parsedJson, data);
    int intToReturn = intValue->valueint;
    cJSON_Delete(parsedJson);
    return intToReturn;
}

char *updateJsonFromStruct(char *json){
    cJSON *parsedJson = cJSON_Parse(json);
    cJSON *cjsonGameOn = cJSON_CreateNumber(lists->gameOn);
    cJSON *cjsonHp = cJSON_CreateNumber(lists->Hp);
    cJSON *cjsonNumOfCrocodiles = cJSON_CreateNumber(lists->numOfCrocodiles);
    cJSON *cjsonNumOfFruits = cJSON_CreateNumber(lists->numOfFruits);
    cJSON *cjsonCrocodilesAlive = cJSON_CreateIntArray(lists->crocodilesAlive, lists->numOfCrocodiles);
    cJSON *cjsonFruitsAlive = cJSON_CreateIntArray(lists->fruitsAlive, lists->numOfFruits);
    cJSON_ReplaceItemInObjectCaseSensitive(parsedJson, "gameOn", cjsonGameOn);
    cJSON_ReplaceItemInObjectCaseSensitive(parsedJson, "Hp", cjsonHp);
    cJSON_ReplaceItemInObjectCaseSensitive(parsedJson, "numOfCrocodiles", cjsonNumOfCrocodiles);
    cJSON_ReplaceItemInObjectCaseSensitive(parsedJson, "numOfFruits", cjsonNumOfFruits);
    cJSON_ReplaceItemInObjectCaseSensitive(parsedJson, "crocodilesAlive", cjsonCrocodilesAlive);
    cJSON_ReplaceItemInObjectCaseSensitive(parsedJson, "fruitsAlive", cjsonFruitsAlive);
    char *jsonToReturn = parsedJson->string;
    cJSON_Delete(parsedJson);
    return jsonToReturn;
}

