//(X|O) project with c++

#include "game_tools.h"

int main(){
    Game s("Tic_tac_toe");

    runGame(s);
    checkResult(s);

    system("Pause");
    return 0;
}



