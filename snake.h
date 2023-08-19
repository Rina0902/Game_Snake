#pragma once

#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

enum eDirection { STOP = 0, LEFT , RIGHT , UP , DOWN };

struct Snake
{
	int8_t x = 0, y = 0;
	int8_t numberTail = 0;
	int8_t tailX[100], tailY[100];
};

struct Fruit
{
	int8_t fruitX = 0, fruitY = 0;
};

struct GameParameters
{

	int16_t score = 0;
	int8_t screenWidth;
	int8_t screenHeight;
	bool gameOver;
};


//Declaration of functions
void gotoxy(int x, int y);
void initializeGame(GameParameters* game, const int screenWidthVariable, const int screenHeightVariable);
void setup(GameParameters* game_parameter, Snake* snake_variable, Fruit* fruit_variable, eDirection* dir_variable);
eDirection input(GameParameters* game_parameter, eDirection* dir_variable);
void logic(GameParameters* game_parameter, Snake* snake_variable, eDirection dir_variable);
void draw(GameParameters* game_parameter, Snake* snake_variable, Fruit* fruit_variable);









