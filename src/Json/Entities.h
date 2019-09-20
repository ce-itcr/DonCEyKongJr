//
// Created by ivan on 9/18/19.
//

#ifndef JSON_ENTITIES_H
#define JSON_ENTITIES_H

#include <allegro5/allegro.h>

typedef struct Crocodile{
    int posX;
    int posY;
    int species;
    int speed;
    int width;
    int height;
    int alive;
} Crocodile;

typedef struct Fruit{
    int posX;
    int posY;
    int species;
    int score;
    int speed;
    int width;
    int height;
    int alive;
} Fruit;

//Crocodile crocodiles[];
//Fruit fruits[];
//
//Fruit *getFruits(char *json);
//Crocodile *getCrocodiles(char *json);


#endif //JSON_ENTITIES_H
