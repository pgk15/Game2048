//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <ctime>
#include <SDL2/SDL.h>
//#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_image.h>
#include<SDL2_image/SDL_image.h>
#include<SDL2_ttf/SDL_ttf.h>
using namespace std;

#include "Public.hpp"
#include "SDL_default.hpp"
#include "Solve_Event.hpp"
#include "Create_Random.hpp"
#include "Show.hpp"

int main(int argc, char* argv[]){
    srand((unsigned int)time(NULL));
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Event e;
    TTF_Font* font;
    SDL_Surface* surface;
    SDL_Texture* texture=NULL;
    SDL_Color color;


    Game game = Game(PLAY, 4);
    SCREEN_WIDTH = BOX_WIDTH * game.level;
    SCREEN_HEIGHT = BOX_HEIGHT * game.level;

    initSDL(window, renderer);
    font = TTF_OpenFont("/Users/phamgiakhiem/Desktop/cpp/SDL2/SDL2/VeraMoBd.ttf", 30);
    if(font == NULL) logSDLError(cout, "TTF OpenFont", true);
    color = { 150, 250, 30 };

    //color = { 50, 50, 50 };
    vvB box, last_box;
    for(int i = 0; i < game.level; ++ i){
        vector<Box> v;
        for(int j = 0; j < game.level; ++ j){
            v.push_back(Box{j * BOX_HEIGHT, i * BOX_WIDTH, 0});
        }
        box.push_back(v);
    }
    box[0][0].value = 2;
    create_Random(box, game);
    refressScreen(renderer, box, game, surface, texture, font, color);
    while(true){
        solve_Event(e, game, box, last_box);
        if(game.mode == QUIT) break;
        if(game.mode!= UNDO) create_Random(box, game);
        refressScreen(renderer, box, game, surface, texture, font, color);
    }

    SDL_Delay(100);
    quitSDL(window, renderer);
    //exit(1);
    cout<<"Thank you!";
    return 0;
}
