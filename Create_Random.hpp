#ifndef _Create_Random_
#define _Create_Random_

void create_Random(vvB& box, Game& game){
    while(true){
        int i = rand() % game.level;
        int j = rand() % game.level;
        if(box[i][j].value) continue;
        box[i][j].value = 2;
        break;
    }
}

#endif


