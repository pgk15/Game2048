#ifndef _Public_
#define _Public_

// Khởi tạo cửa sổ game
const int BOX_WIDTH = 200;
const int BOX_HEIGHT = 200;
const string WINDOW_TITLE =  "GAME 22048";


int SCREEN_WIDTH;
int SCREEN_HEIGHT;


struct Box{
    int x, y;
    int value;
};

#define vvB vector<vector<Box>>

enum Mode{
    UNDO,
    PLAY,
    QUIT,
    END_GAME,
    WIN_GAME,
};

struct Game{
    Mode mode;
    int level;
    Game(Mode mode, int level){
        this -> mode = mode;
        this -> level = level;
    }
};

#endif

