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
	int8_t screenWidth;
	int8_t screenHeight;
};

struct State
{
	int16_t score = 0;
	char gameOver = 'f';
};

//Declaration of functions
void gotoxy(int x, int y);
void initializeGame( GameParameters* parameters, const int screenWidthVariable, const int screenHeightVariable);
void setup(GameParameters* parameters, State* stateObject, Snake* snake_variable, Fruit* fruit_variable, eDirection* dir_variable);
void input(GameParameters* game_parameter, State* stateObject, eDirection* dir_variable);
void setInstructions(GameParameters* game_parameter, State* stateObject, Snake* snake_variable, eDirection* dir_variable);
void draw_fruit(GameParameters* game_parameter, Fruit* fruit_variable);
void draw_snake(GameParameters* game_parameter, Snake* snake_variable, Fruit* fruit_variable);
void draw_map(GameParameters* game_parameter, State* stateObject);
void write_score(State* stateObject);
void generate(GameParameters* game_parameter, State* stateObject, Snake* snake_variable, Fruit* fruit_variable);




