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

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <time.h>

#define GRAVITY  0.35f

typedef struct
{
	float x, y;
	float dx, dy;
	short life;
	char *name;
	int onLedge;

	int animFrame, facingLeft, slowingDown;
} DKJr;

typedef struct{
	int x, y, w, h;
} Ledge;

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

typedef struct Crocodile{
	int posX;
	int posY;
	int species;
	int speed;
	int width;
	int height;
	int alive;
} Crocodile;

typedef struct Lists{
	int score;
	int gameOn;
	int Hp;
	Crocodile cocrodileList[50];
	Fruit fruitList[50];
	int crocodilesAlive[50];
	int fruitsAlive[50];
	Ledge terrainList[50];
	int numOfTerrain;
	int numOfCrocodiles;
	int numOfFruits;
	int currentNumberOfFruits;
	int currentNumberOfCrocodiles;
}Lists;

Lists *lists;

typedef struct{
    DKJr player;

    Ledge ledges[100];
    Ledge underledges[100];

    SDL_Texture *playerFrames[2];
    SDL_Texture *brick;
    SDL_Texture *background;
    SDL_Texture *menu;
    SDL_Texture *platform;
    SDL_Texture *safetyKey;
    SDL_Texture *mario;
    SDL_Texture *dk;
    SDL_Texture *jail;
    SDL_Texture *scoreholder;

    int time;
    int windowPage;

    SDL_Renderer *renderer;
} GameState;


void loadGame(GameState *game);
void process(GameState *game);
void collisionDetect(GameState *game);
int processEvents(SDL_Window *window, GameState *game);
void doRender(SDL_Renderer *renderer, GameState *game);
void runner();


#endif //DONCEYKONGJR_GAME_H