// GameOfLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

const char DEAD =  ' ';
const char ALIVE = 'X';

const int width = 60;
const int height = 25;

#define INDEX(r, c)	((r)*width+(c))

char gameBoard1[height*width];	// current board....
char gameBoard2[height*width];	// next generation board........

char *gameBoardCurrent = gameBoard1;	// pointer to current gameboard
char *gameBoardUpdate = gameBoard2;

void render();
void initBoard();
void update();

int main() {
	int count = 0;
	initBoard();

	while(1){
		update();
		std::swap(gameBoardCurrent, gameBoardUpdate);
		std::cout << "Generation : " << count << std::endl;
		render();
		Sleep(500);
		count++;
		system("cls");
	}
	return 0;
}


void update() {
	for (int row = 1; row < height-1; row++) {
		for (int col = 1; col < width-1; col++) {
			int neighbors = 0;
			for (int i = -1; i < 2; i++) {
				for (int j = -1; j < 2; j++) {
					if (i == 0 && j == 0)	continue;	// skip self....
					if (gameBoardCurrent[INDEX(row + i, col + j)] == ALIVE)
						neighbors++;
				}
			}
			if (neighbors < 2)	// neighbors < 2, cell will die of loneliness
				gameBoardUpdate[INDEX(row, col)] = DEAD;
			if (neighbors > 3)	// neighbors > 3, cell will die of overpopulation
				gameBoardUpdate[INDEX(row, col)] = DEAD;
			if (neighbors == 3)	// neighbors== 3, cell will become alive by reproduction...
				gameBoardUpdate[INDEX(row, col)] = ALIVE;
			if (neighbors == 2)	// neighbors== 2, cell stays same...
				gameBoardUpdate[INDEX(row, col)] = gameBoardCurrent[INDEX(row, col)];
		}
	}
}

void initBoard() {
	srand(time_t(NULL));
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			// skip edges....
			if (row == 0 || col == 0 || row == height - 1 || col == width - 1) {
				gameBoardCurrent[INDEX(row, col)] = DEAD;
				gameBoardUpdate[INDEX(row, col)] = DEAD;
				continue;
			}
			int chance = rand() % 1000;
			if (chance < 100)
				gameBoardCurrent[INDEX(row, col)] = ALIVE;
			else
				gameBoardCurrent[INDEX(row, col)] = DEAD;
		}
	}
}

void render() {
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
				std::cout << gameBoardCurrent[INDEX(row, col)];
		}
		std::cout << std::endl;
	}
}