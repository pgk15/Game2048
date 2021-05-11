#ifndef _Solve_Event_
#define _Solve_Event_

#include "Move.hpp"
void solve_Event(SDL_Event& e, Game& game, vvB& box, vvB& last_box){
    while(true){
        if(SDL_PollEvent(&e) == 0) continue;
        if (e.type == SDL_QUIT){
            game.mode = QUIT;
            break;
        }
        else if (e.type == SDL_KEYDOWN){
            bool check=false;
            if (e.key.keysym.sym == SDLK_ESCAPE){
                game.mode = UNDO;
                box = last_box;
                break;
            }
            else if (e.key.keysym.sym == SDLK_LEFT) check = move_Left(box, game, last_box);
            else if(e.key.keysym.sym == SDLK_RIGHT) check = move_Right(box, game, last_box);
            else if(e.key.keysym.sym == SDLK_DOWN) check = move_Down(box, game, last_box);
            else if(e.key.keysym.sym == SDLK_UP) check = move_Up(box, game, last_box);
            game.mode = PLAY;
            if(!check) continue;
            break;
        }
        else continue;
    }
}

#endif
