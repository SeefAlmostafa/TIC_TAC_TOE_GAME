#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Game {
private:
    char matrix[3][3] = {'1','2','3','4','5','6','7','8','9'};
	string name;
	char player;
	char Pos;
	// private methods
	char checkRowsAndCols(bool);
	bool foundAWinner(char);
	char checkDiagonals();
	void switchTurn();
	bool allCellsFilled();

public:
	Game(string);
	void printMatrix();
	char whoWin();
	void play();
	string get_game_Name()const;
};

#endif // GAME_H_INCLUDED
