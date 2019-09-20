/*
 game.h -

 This file is part of DonCE Y Kong Jr, the same correspondent to Project III for the course of Languages, Compilers and Interpreters. (CE3104), Languages module.
 The project consists in the implementation of an application that reaffirms the knowledge of the imperative and object-oriented programming paradigms.
 For more information about the project visit: https://github.com/ce-itcr/DonCEyKongJr

 File Version    : 1.0
 Authors         : Github @ angelortizv
 Last modified   : 19/09/2019, 00:20, @angelortizv
*/

#ifndef DONCEYKONGJR_GAME_H
#define DONCEYKONGJR_GAME_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <jmorecfg.h>
#include <stdbool.h>

// Name     :
// Brief    : Type: 0 = bananas ; 1 = orange ; 2 = strawberry
// Use      :
typedef struct{
    int x, y;
    int alive;
    int score;
    SDL_Rect pCollider;
} DKJr;

// Name     :
// Brief    : Species: 0 = bananas ; 1 = oranges ; 2 = strawberry
// Use      :
typedef struct Fruit{
    int posX;
    int posY;
    int species;
    int score;
    int speed;
    int width;
    int height;
    int alive;
    SDL_Rect rCollider;
} Fruit;

// Name     :
// Brief    : Type: 0 = blueKremling ; 1 = redKremling
// Use      :
typedef struct Crocodile{
    int posX;
    int posY;
    int species;
    int speed;
    int width;
    int height;
    int alive;
    SDL_Rect rCollider;
} Crocodile;

typedef struct Terrain{
    int x;
    int y;
    int height;
    int width;
    SDL_Rect tCollider;
} Terrain;

typedef struct Lists{
    Crocodile cocrodileList[50];
    Fruit fruitList[50];
    Terrain terrainList[50];
    int numOfTerrain;
    int numOfCrocodiles;
    int numOfFruits;
}Lists;

Lists *lists;

// Name     :
// Brief    : 
// Use      :
typedef struct{
	int x, y;
	int sizeMult; 

	DKJr player;

	SDL_Renderer *renderer;

	SDL_Texture *backgroundImage;
	SDL_Texture *playerImage;
	SDL_Texture *blueKremlingImage;
	SDL_Texture *redKremlingImage;
	SDL_Texture *bananasImage;
	SDL_Texture *orangesImage;
	SDL_Texture *strawberryImage;
} Game;


int processEvents(SDL_Window *window, Game *game);
void initializeGame(SDL_Window *window, Game *game);
void gameRender(Game *game);
void loadGraphics(Game *game);
void closeGame(SDL_Window *window, Game *game);
bool checkCollision(SDL_Rect a,SDL_Rect b);
void checkPlayerCollision(Game* game);



#endif //DONCEYKONGJR_GAME_H