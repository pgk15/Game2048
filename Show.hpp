#ifndef _Show_
#define _Show_

int show_Text(SDL_Renderer* renderer, const string text, SDL_Surface* &surface,
               SDL_Texture* texture, TTF_Font* font, SDL_Color color, SDL_Rect& filled_rect){
    surface = TTF_RenderText_Solid(font, text.c_str(), color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);

	SDL_Rect srcRest;
	srcRest.x = 0;
	srcRest.y = 0;
    TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

    SDL_RenderCopy(renderer, texture, &srcRest, &filled_rect);

}

string change_NumberToString(int number){
    number = max(number, 0);
    string res;
    while(number > 0){
        res = char(number % 10 + 48) + res;
        number /= 10;
    }
    if(!res.size()) res = "0";
    return res;
}

void refressScreen(SDL_Renderer * renderer, vvB &box, Game& game, SDL_Surface* &surface,
               SDL_Texture* texture, TTF_Font* font, SDL_Color color){

    SDL_SetRenderDrawColor(renderer, 50, 20, 100, 255);   //black
    SDL_RenderClear(renderer);


    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for(int i = 0; i < game.level; ++ i)
        for(int j = 0; j < game.level; ++ j){
            SDL_Rect range_box;
            range_box.x = box[i][j].x;
            range_box.y = box[i][j].y;
            range_box.w = BOX_WIDTH;
            range_box.h = BOX_HEIGHT;
            SDL_RenderDrawRect(renderer, &range_box);
            if(box[i][j].value){
                string text = change_NumberToString(box[i][j].value);
                show_Text(renderer, text, surface, texture, font, color, range_box);
            }
        }
    SDL_RenderPresent(renderer);
}

#endif

