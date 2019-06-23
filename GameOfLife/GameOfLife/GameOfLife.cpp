// GameOfLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

const char DEAD =  ' ';
const char ALIVE = 'X';

const int width = 40;
const int height = 40;

#define INDEX(r, c)	(r*width+c)

char gameBoard1[height*width];	// current board....
char gameBoard2[height*width];	// next generation board........

char *gameBoardCurrent = gameBoard1;	// pointer to current gameboard
char *gameBoardUpdate = gameBoard2;

void render();
void initBoard();
void update();

int main() {

	initBoard();

	while(1){
		update();
		render();
	}
	return 0;
}


void update() {
	for (int row = 1; row < height-1; row++) {
		for (int col = 1; col < width-1; col++) {
			
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
			if (chance < 50)
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