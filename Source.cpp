#include "snake.h"

#include <chrono>  

using namespace std::chrono;

#define SCREENWIDTH 20
#define SCREENHEIGHT 20

GameParameters parameters ;
Snake snakeObject;
Snake aiSnakeObject;
Fruit fruitObject;
State stateObject;

enum eDirection direction = STOP;

double clockToMilliseconds(clock_t ticks) {
	
	return (ticks / (double)CLOCKS_PER_SEC) * 1000.0;
}

clock_t deltaTime = 0;
unsigned int frames = 0;
double  frameRate = 60;
double  averageFrameTimeMilliseconds = 16.67;


int main()
{
	
	//init
	init_game_parameters(&parameters, SCREENWIDTH, SCREENHEIGHT);
	init_snake(parameters, &snakeObject);
	init_state(&stateObject);
	init_fruit(parameters,&fruitObject);
	cout << "snakeObject = " << snakeObject.numberTail << endl;
	

	while (stateObject.gameOver == 'f')
	{
		clock_t beginFrame = clock();
		
		display_map(parameters, stateObject);
		display_snake(parameters, snakeObject, fruitObject);
		display_fruit(parameters, fruitObject);
		display_score(parameters, stateObject);
		
		clock_t endFrame = clock();

		//If the snake eats the fruit
		stateObject = generate_score(stateObject, snakeObject, fruitObject);
		add_tail_number(&snakeObject, fruitObject);
		fruitObject = generate_fruit(parameters, snakeObject, fruitObject);
	
		direction = input(&stateObject, direction);
		set_instructions(parameters, &stateObject, &snakeObject, direction);
		Sleep(frameRate*2);
		
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
	
	cout << "Game Over!" << endl;
	
	return 0;
}