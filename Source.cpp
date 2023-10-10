#include "Snake.h"
#include "AStar.h"
#include <chrono>  

using namespace std::chrono;

#define SCREENWIDTH 20
#define SCREENHEIGHT 20

GameParameters parameters;
Snake snakeObject;
Snake aiSnakeObject;
Fruit fruitObject;
State stateObject;
vector<vector<int>> map_variable(SCREENWIDTH, std::vector<int>(SCREENHEIGHT));

enum eDirection direction = STOP;
enum eDirection aiDirection = STOP;

double clockToMilliseconds(clock_t ticks) {

	return (ticks / (double)CLOCKS_PER_SEC) * 1000.0;
}

clock_t deltaTime = 0;
unsigned int frames = 0;
double  frameRate = 60;
double  averageFrameTimeMilliseconds = 16.67;

int cost = 1;

int main()
{
	//init
	init_game_parameters(&parameters, SCREENWIDTH, SCREENHEIGHT);
	init_snake(parameters, &snakeObject);
	init_snake(parameters, &aiSnakeObject);
	init_state(&stateObject);
	init_fruit(parameters, &fruitObject);
	init_fruit(parameters, &fruitObject);
	std::pair<int, int> start = { aiSnakeObject.x,  aiSnakeObject.y };
	while (stateObject.gameOver == 'f')
	{
		std::pair<int, int> end = { fruitObject.fruitX, fruitObject.fruitY };
		std::vector<std::pair<int, int>> path = search(map_variable, cost, start, end);
		for (std::pair<int, int> point : path)
		{
			start = { point.first, point.second };
			std::cout << "(" << point.first << ", " << point.second << ") ";
			clock_t beginFrame = clock();

			map_variable = display_map(parameters, stateObject, map_variable);
			map_variable = display_snake(parameters, snakeObject, fruitObject, aiSnakeObject, map_variable);
			display_fruit(parameters, fruitObject);
			display_score(parameters, stateObject);

			clock_t endFrame = clock();

			//If the snake eats the fruit
			stateObject = generate_score(stateObject, snakeObject, fruitObject);
			add_tail_number(&snakeObject, fruitObject);

			add_tail_number(&aiSnakeObject, fruitObject);
			fruitObject = generate_fruit(parameters, snakeObject, fruitObject, aiSnakeObject);


			aiSnakeObject.x = point.first;
			aiSnakeObject.y = point.second;

			direction = input(&stateObject, direction);
			set_instructions(parameters, &stateObject, &snakeObject, direction);
			Sleep(frameRate * 2);

			deltaTime += endFrame - beginFrame;

			frames++;

			//if you really want FPS
			if (clockToMilliseconds(deltaTime) > 1000.0) { //every second
				frameRate = (double)frames * 0.5 + frameRate * 0.5; //more stable
				frames = 0;
				deltaTime -= CLOCKS_PER_SEC;
				cout << "deltaTime was:" << deltaTime << endl;
				averageFrameTimeMilliseconds = 1000.0 / (frameRate == 0 ? 0.001 : frameRate);

				cout << "Frame time was:" << averageFrameTimeMilliseconds << endl;

			}
		}
	}
	cout << "Game Over!" << endl;

	return 0;
}