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
void setInstructions(GameParameters* game_parameter, State* stateObject, Snake* snakeObject, eDirection* dir_variable);
void draw_fruit(const GameParameters game_parameter, const Fruit fruitObject);
void draw_snake(const GameParameters game_parameter, const Snake snakeObject, const Fruit fruitObject);
void draw_map(const GameParameters game_parameter,const State stateObject);
void write_score(State* stateObject);
void generate(GameParameters* game_parameter, State* stateObject, Snake* snakeObject, Fruit* fruitObject);




