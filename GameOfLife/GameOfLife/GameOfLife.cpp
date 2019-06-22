// GameOfLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#define DEAD	'X'
#define ALIVE	'O'

const int width = 40;
const int height = 40;

#define INDEX(r, c)	(r*width+c)

int gameBoard1[height*width];	// current board....
int gameBoard2[height*width];	// next generation board........

int *gameBoardCurrent = gameBoard1;	// pointer to current gameboard
int *gameBoardUpdate = gameBoard2;


int main() {

	render();
	return 0;
}

void render() {
	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
			if (gameBoardCurrent[INDEX(row, col)])
				std::cout << ALIVE;
			else
				std::cout << DEAD;
		}
	}
}