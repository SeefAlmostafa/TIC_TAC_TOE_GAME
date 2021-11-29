#include "Game.h"

void Game::printMatrix() {
	system("cls");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << this->matrix[i][j] <<"\t";
		}
		cout <<endl<<endl<<endl;
	}
}

char Game::checkRowsAndCols(bool checkCols) {
    int i = 0,j = 0;
    int xc = 0;
    int oc = 0;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            char curr = 0;
            if(checkCols) {
                curr = matrix[j][i];
            } else {
                curr = matrix[i][j];
            }
            if (curr == 'X')
                xc++;
            else if(curr == 'O')
                oc++;
            if (xc == 3 || oc == 3) {
                return xc > oc ? 'X':'O';
            }
        }
        xc = 0;
        oc = 0;
	}

	return '.';
}

char Game::checkDiagonals() {
         if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') return 'X';
    else if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') return 'O';
	else if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X') return 'X';
	else if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O') return 'O';
	else return '.';
}

bool Game::foundAWinner(char c) {
    return c == 'O' || c == 'X';
}

bool Game::allCellsFilled() {
    int i,j;
    int counter = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            char c = matrix[i][j];
            if(c != 'X' && c != 'O') {
                counter++;
            }
        }
    }
        return counter == 0;
}

char Game::whoWin(){
    char rowsAnswer = checkRowsAndCols(false); // check rows
    if(foundAWinner(rowsAnswer)) {
        return rowsAnswer;
    }
    char colsAnswer = checkRowsAndCols(true); // check cols
    if(foundAWinner(colsAnswer)) {
        return colsAnswer;
    }
    char diagonalsAnswer = checkDiagonals();
    if(foundAWinner(diagonalsAnswer)) {
        return diagonalsAnswer;
    }
    if(allCellsFilled()) {
        return 'Z';
    } else {
        return '.';
    }
}

void Game::play() {
	cout << "Player"<<"("<<this->player<<")"<<" Enter a position: ";
	cin >> Pos;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[i][j] == this->Pos) {
				matrix[i][j] = this->player;
			}
		}
	}
    this->switchTurn();
}

string Game::get_game_Name()const{
    return this->name;
}

Game::Game(string name):name(name){
    player = 'X';
}

void Game::switchTurn(){

    if (this->player == 'X')
		this->player = 'O';
	else
		this->player = 'X';
}
