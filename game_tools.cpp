#include "game_tools.h"

void runGame(Game& s){
	while (s.whoWin() == '.'){
		s.printMatrix();
		s.play();
	}
	s.printMatrix();
}

void checkResult(Game& s){
    if (s.whoWin() == 'Z')
		cout << "\nNo Winner\n" << endl;
	else
		cout << "The Winner is Player" << "(" << s.whoWin() << ")" << " Congratulation !!"<<endl;
}

