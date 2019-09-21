/*
 game.c -

 This file is part of DonCE Y Kong Jr, the same correspondent to Project III for the course of Languages, Compilers and Interpreters. (CE3104), Languages module.
 The project consists in the implementation of an application that reaffirms the knowledge of the imperative and object-oriented programming paradigms.
 For more information about the project visit: https://github.com/ce-itcr/DonCEyKongJr

 File Version    : 1.0
 Authors         : Github @ angelortizv
 Last modified   : 19/09/2019, 00:20, @angelortizv
*/

#include "game.h"

int processEvents(SDL_Window *window, Game *game){
  SDL_Event event;
  int done = 0;

  while(SDL_PollEvent(&event)){
    switch(event.type){
      case SDL_WINDOWEVENT_CLOSE:{
        if(window){
          SDL_DestroyWindow(window);
          window = NULL;
          done = 1;
        }
      }
      break;
      case SDL_KEYDOWN:{
        switch(event.key.keysym.sym){
          case SDLK_ESCAPE:
            done = 1;
          break;
        }
      }
      break;
      case SDL_QUIT:
        done = 1;
      break;
    }
  }

  const Uint8 *state = SDL_GetKeyboardState(NULL);
  if(state[SDL_SCANCODE_LEFT]){
  	checkPlayerCollision(game,"");
    game->player.x -= 1*game->sizeMult;
    game->player.pCollider.x -= 1*game->sizeMult;
  }
  if(state[SDL_SCANCODE_RIGHT]){
  	checkPlayerCollision(game,"");
    game->player.x += 1*game->sizeMult;
    game->player.pCollider.x += 1*game->sizeMult;
  }
  if(state[SDL_SCANCODE_UP]){
  	checkPlayerCollision(game,"-y");
    game->player.y -= 1*game->sizeMult;
    game->player.pCollider.y -= 1*game->sizeMult;
  }
  if(state[SDL_SCANCODE_DOWN]){
	  checkPlayerCollision(game,"+y");
      game->player.y += 1*game->sizeMult;
      game->player.pCollider.y += 1*game->sizeMult;
  }
  return done;
}

void checkPlayerCollision(Game* game,char* direction){
		for(int i = 0; i < lists->numOfCrocodiles;i++){
			if(checkCollision(game->player.pCollider,lists->cocrodileList[i].rCollider)){
				game->player.alive = 0;
			}
		}
		for(int i = 0; i < lists->numOfFruits;i++){
			if(checkCollision(game->player.pCollider,lists->fruitList[i].rCollider)){
				lists->score += lists->fruitList[i].score;
				lists->fruitList[i].alive = 0;
			}
		}
		for(int i = 0; i < lists->numOfTerrain;i++){
			if(checkCollision(game->player.pCollider,lists->terrainList[i].tCollider)){
				if(direction == "+y") {
					game->player.y -= 10;
					game->player.pCollider.y -= 10;
				}else if(direction == "-y"){
					game->player.y += 10;
					game->player.pCollider.y += 10;
				}

			}
		}
}

void initializeGame(SDL_Window *window, Game *game){
	SDL_Init(SDL_INIT_VIDEO);

	lists->gameON = 1;
	game->sizeMult = 3;
	game->x = 248*game->sizeMult;
	game->y = 216*game->sizeMult;
	game->player.x = 0;
	game->player.y = game->y-(4*(8*game->sizeMult));
    game->player.pCollider.x = 0;
    game->player.pCollider.y = game->y-(4*(8*game->sizeMult));
    game->player.pCollider.w = 35;
    game->player.pCollider.h = 35;

	window = SDL_CreateWindow("DonCE y Kong Jr",                    
							SDL_WINDOWPOS_UNDEFINED,            
							SDL_WINDOWPOS_UNDEFINED,            
							248*game->sizeMult,                       
							216*game->sizeMult,                     
							0);                                  

	game->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void gameRender(Game *game) {
    SDL_Rect backRect = {0, 0, game->x, game->y};
    SDL_RenderCopy(game->renderer, game->backgroundImage, NULL, &backRect);

    SDL_Rect playerRect = {game->player.x, game->player.y, 25 * game->sizeMult, 16 * game->sizeMult};
    SDL_RenderCopy(game->renderer, game->playerImage, NULL, &playerRect);

    Terrain *terrain0 = malloc(sizeof(Terrain));
    Terrain *terrain1 = malloc(sizeof(Terrain));
    Terrain *terrain2 = malloc(sizeof(Terrain));
    Terrain *terrain3 = malloc(sizeof(Terrain));
    Terrain *terrain4 = malloc(sizeof(Terrain));
    Terrain *terrain5 = malloc(sizeof(Terrain));
    Terrain *terrain6 = malloc(sizeof(Terrain));
    Terrain *terrain7 = malloc(sizeof(Terrain));
    Terrain *terrain8 = malloc(sizeof(Terrain));
    Terrain *terrain9 = malloc(sizeof(Terrain));
    Terrain *terrain10 = malloc(sizeof(Terrain));

    int dir[11][4] = {{0,   600, 20, 200},
                      {252, 555, 20, 100},
                      {375, 585, 20, 80},
                      {475, 554, 20, 100},
                      {590, 535, 20, 100},
                      {550, 360, 25, 325},
                      {105, 410, 23, 150},
                      {110, 290, 23, 100},
                      {0,   142, 28, 430},
                      {385, 165, 25, 200},
                      {200, 75,  25, 50}};
    Terrain *ter[11] = {terrain0, terrain1, terrain2, terrain3, terrain4, terrain5, terrain6, terrain7, terrain8,
                        terrain9, terrain10};

    for (int i = 0; i < 11; i++) {
        ter[i]->tCollider.x = dir[i][0];
        ter[i]->tCollider.y = dir[i][1];
        ter[i]->tCollider.h = dir[i][2];
        ter[i]->tCollider.w = dir[i][3];
        lists->terrainList[i] = *ter[i];
//		SDL_RenderCopy(game->renderer,game->blueKremlingImage,NULL,&ter[i]->tCollider);
    }

    lists->numOfTerrain = 11;

    SDL_RenderPresent(game->renderer);
}

void loadGraphics(Game *game){

	SDL_Surface *backgroundSurface = NULL;
	SDL_Surface *playerSurface = NULL;
	SDL_Surface *blueKremlinSurface = NULL;
	SDL_Surface *redKremlinSurface = NULL;
	SDL_Surface *bananasSurface = NULL;
	SDL_Surface *orangesSurface = NULL;
	SDL_Surface *strawberrySurface = NULL;

	backgroundSurface = IMG_Load("img/background.png");
	playerSurface = IMG_Load("img/dkjr.png");
	blueKremlinSurface = IMG_Load("img/kremling_blue.png");
	redKremlinSurface = IMG_Load("img/kremling_red.png");
	bananasSurface = IMG_Load("img/fruit_bananas.png");
	orangesSurface = IMG_Load("img/fruit_oranges.png");
	strawberrySurface = IMG_Load("img/fruit_strawberry.png");

	if (backgroundSurface == NULL){
		printf("Cannot find background.png\n\n");
		SDL_Quit();
		exit(1);
	}
	if (playerSurface == NULL){
		printf("Cannot find dkjr.png\n\n");
		SDL_Quit();
		exit(1);
	}
	if (blueKremlinSurface == NULL){
		printf("Cannot find kremling_blue.png\n\n");
		SDL_Quit();
		exit(1);
	}
	if (redKremlinSurface == NULL){
		printf("Cannot find kremling_red.png\n\n");
		SDL_Quit();
		exit(1);
	}
	if (bananasSurface == NULL){
		printf("Cannot find fruit_bananas.png\n\n");
		SDL_Quit();
		exit(1);
	}
	if (orangesSurface == NULL){
		printf("Cannot find fruit_oranges.png\n\n");
		SDL_Quit();
		exit(1);
	}
	if (strawberrySurface == NULL){
		printf("Cannot find fruit_strawberry.png\n\n");
		SDL_Quit();
		exit(1);
	}

	game->playerImage = SDL_CreateTextureFromSurface(game->renderer, playerSurface);
	game->backgroundImage = SDL_CreateTextureFromSurface(game->renderer, backgroundSurface);
	game->blueKremlingImage = SDL_CreateTextureFromSurface(game->renderer, blueKremlinSurface);
	game->redKremlingImage = SDL_CreateTextureFromSurface(game->renderer, redKremlinSurface);
	game->bananasImage = SDL_CreateTextureFromSurface(game->renderer, bananasSurface);
	game->orangesImage = SDL_CreateTextureFromSurface(game->renderer, orangesSurface);
	game->strawberryImage = SDL_CreateTextureFromSurface(game->renderer, strawberrySurface);

	SDL_FreeSurface(playerSurface);
	SDL_FreeSurface(backgroundSurface);
	SDL_FreeSurface(blueKremlinSurface);
	SDL_FreeSurface(redKremlinSurface);
	SDL_FreeSurface(bananasSurface);
	SDL_FreeSurface(orangesSurface);
	SDL_FreeSurface(strawberrySurface);
}

void closeGame(SDL_Window *window, Game* game){
	SDL_DestroyTexture(game->playerImage);
	SDL_DestroyTexture(game->backgroundImage);
	SDL_DestroyTexture(game->blueKremlingImage);
	SDL_DestroyTexture(game->redKremlingImage);
	SDL_DestroyTexture(game->bananasImage);
	SDL_DestroyTexture(game->orangesImage);
	SDL_DestroyTexture(game->strawberryImage);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(game->renderer);
	SDL_Quit();
}

bool checkCollision( SDL_Rect a, SDL_Rect b ){
    int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	if( bottomA <= topB ){
		return false;
	}
	if( topA >= bottomB ){
		return false;
	}
	if( rightA <= leftB ){
		return false;
	}
	if( leftA >= rightB ){
		return false;
	}

	return true;
}

//void updateFruitsAndCrocodiles(){
//    for(int i = lists->currentNumberOfFruits; i < lists->numOfFruits;i++){
//        lists->fruitList[i].rCollider.x = lists->fruitList[i].posX;
//        lists->fruitList[i].rCollider.y = lists->fruitList[i].posY;
//        lists->fruitList[i].rCollider.h = lists->fruitList[i].height;
//        lists->fruitList[i].rCollider.w = lists->fruitList[i].width;
//        if(lists->fruitList[i].species == 0){
//            SDL_RenderCopy(game->renderer,game->bananasImage,NULL,&lists->fruitList[i].rCollider);
//        }else if(lists->fruitList[i].species == 1){
//            SDL_RenderCopy(game->renderer,game->orangesImage,NULL,&lists->fruitList[i].rCollider);
//        }else{
//            SDL_RenderCopy(game->renderer,game->strawberryImage,NULL,&lists->fruitList[i].rCollider);
//        }
//        currentNumberOfFruit = i;
//    }
//
//	for(int i = lists->currentNumberOfCrocodiles; i < lists->numOfCrocodiles;i++){
//		lists->cocrodileList[i].rCollider.x = lists->cocrodileList[i].posX;
//		lists->cocrodileList[i].rCollider.y = lists->cocrodileList[i].posY;
//		lists->cocrodileList[i].rCollider.h = lists->cocrodileList[i].height;
//		lists->cocrodileList[i].rCollider.w = lists->cocrodileList[i].width;
//		if(lists->cocrodileList[i].species == 0){
//			SDL_RenderCopy(game->renderer,game->blueKremlingImage,NULL,&lists->cocrodileList[i].rCollider);
//		}else{
//			SDL_RenderCopy(game->renderer,game->redKremlingImage,NULL,&lists->cocrodileList[i].rCollider);
//		}
//		currentNumberOfCrocodiles = i;
//	}
//}