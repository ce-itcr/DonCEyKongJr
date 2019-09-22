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
        lists->crocodilesAlive[i] = 1;
    }
    for (int i = 0; i < lists->numOfFruits; i++){
        Fruit tmpFruit = getFruitByNumber(json, i);
        lists->fruitList[i].species = tmpFruit.species;
        lists->fruitList[i].posX = tmpFruit.posX;
        lists->fruitList[i].posY = tmpFruit.posY;
        lists->fruitList[i].alive = tmpFruit.alive;
        lists->fruitList[i].score = tmpFruit.score;
        lists->fruitsAlive[i] = 1;
    }
}

int getIntValueInJsonArray(char *json, char *array, int i, char *data){
    cJSON *parsedJson = cJSON_Parse(json);
    cJSON *arr = cJSON_GetObjectItemCaseSensitive(parsedJson, array);
    cJSON *obj = cJSON_GetArrayItem(arr, i);
    cJSON *intValue = cJSON_GetObjectItemCaseSensitive(obj, data);
    int intToReturn = intValue->valueint;
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
    return intToReturn;
}

char *updateJsonFromStruct(){
    cJSON *jsonToSend = cJSON_CreateObject();
//    cJSON *cjsonGameOn = cJSON_CreateNumber(lists->gameOn);
//    cJSON *cjsonHp = cJSON_CreateNumber(lists->hp);
//    cJSON *cjsonNumOfCrocodiles = cJSON_CreateNumber(lists->numOfCrocodiles);
//    cJSON *cjsonNumOfFruits = cJSON_CreateNumber(lists->numOfFruits);
//    cJSON *cjsonCrocodilesAlive = cJSON_CreateIntArray(lists->crocodilesAlive, lists->numOfCrocodiles);
//    cJSON *cjsonFruitsAlive = cJSON_CreateIntArray(lists->fruitsAlive, lists->numOfFruits);
    cJSON_AddNumberToObject(jsonToSend, "gameOn", lists->gameOn);
    cJSON_AddNumberToObject(jsonToSend, "hp", lists->hp);
    cJSON_AddNumberToObject(jsonToSend, "numOfCrocodiles", lists->numOfCrocodiles);
    cJSON_AddNumberToObject(jsonToSend, "numOfFruits", lists->numOfFruits);
    cJSON *crocodilesAliveArr = cJSON_CreateIntArray(lists->crocodilesAlive, lists->numOfCrocodiles);
    cJSON_AddItemToObject(jsonToSend, "crocodilesAlive", crocodilesAliveArr);
    cJSON *fruitsAliveArr = cJSON_CreateIntArray(lists->fruitsAlive, lists->numOfFruits);
    cJSON_AddItemToObject(jsonToSend, "fruitsAlive", fruitsAliveArr);
//    printf("%s\n", jsonToSend->valuestring);
//    printf("%s\n", jsonToSend->string);
//    printf("%s\n", cJSON_GetStringValue(jsonToSend));
    return cJSON_PrintUnformatted(jsonToSend);
}

