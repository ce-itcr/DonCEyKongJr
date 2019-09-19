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
    game->player.x -= 1*game->sizeMult;
  }
  if(state[SDL_SCANCODE_RIGHT]){
    game->player.x += 1*game->sizeMult;
  }
  if(state[SDL_SCANCODE_UP]){
    game->player.y -= 1*game->sizeMult;
  }
  if(state[SDL_SCANCODE_DOWN]){
    game->player.y += 1*game->sizeMult;
  }
  return done;
}

void initializeGame(SDL_Window *window, Game *game){
	SDL_Init(SDL_INIT_VIDEO);   						

	game->sizeMult = 3;
	game->x = 248*game->sizeMult;
	game->y = 216*game->sizeMult;
	game->player.x = 0;
	game->player.y = game->y-(4*(8*game->sizeMult));
	window = SDL_CreateWindow("DonCE y Kong Jr",                    
							SDL_WINDOWPOS_UNDEFINED,            
							SDL_WINDOWPOS_UNDEFINED,            
							248*game->sizeMult,                       
							216*game->sizeMult,                     
							0);                                  

	game->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void gameRender(Game *game){
	SDL_Rect backRect = {0, 0, game->x, game->y};
	SDL_RenderCopy(game->renderer, game->backgroundImage, NULL, &backRect);

    SDL_Rect playerRect = {game->player.x, game->player.y, 25*game->sizeMult, 16*game->sizeMult};
    SDL_RenderCopy(game->renderer, game->playerImage, NULL, &playerRect);
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

void closeGame(SDL_Window *window, Game *game){
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