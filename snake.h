#pragma once

#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

enum eDirection { STOP = 0, LEFT , RIGHT , UP , DOWN };

struct Snake
{
	float x = 0.0, y = 0.0;
	int8_t numberTail = 0;
	int8_t tailX[100] , tailY[100];
};

struct Fruit
{
	float fruitX = 0.0, fruitY = 0.0;
};

struct GameParameters
{
	int8_t screenWidth ;
	int8_t screenHeight ;
};

struct State
{
	int16_t score = 0;
	char gameOver = 'f';
};

//Declaration of functions
void gotoxy(int x, int y);
void init_game_parameters( GameParameters* parameters, const int screenWidthVariable, const int screenHeightVariable);


//setup
void init_state(State* stateObject);
void init_snake(const GameParameters& game_parameter, Snake* snake_variable);
void init_fruit(const GameParameters& game_parameter, Fruit* fruit_variable);


eDirection input(State* stateObject, eDirection dir_variable);
void set_instructions(const GameParameters& game_parameter, State* stateObject, Snake* snake_variable, const eDirection& dir_variable);

void display_fruit(const GameParameters& game_parameter, const Fruit& fruitObject);
void display_snake(const GameParameters& game_parameter, const Snake& snakeObject, const Fruit& fruitObject, const Snake& aiSnakeObject);
void display_map(const GameParameters& game_parameter, const State& stateObject);
void display_score(const GameParameters& game_parameter, const State& stateObject);

//If the snake eats the fruit
State generate_score(State stateObject,const Snake& snakeObject,const Fruit& fruitObject);
Fruit generate_fruit(const GameParameters& game_parameter,const Snake& snakeObject, Fruit fruitObject);
void add_tail_number(Snake* snakeObject, const Fruit& fruitObject);


void move_aiSnake(Snake* snakeObject, eDirection* dir_variable);
