#include "snake.h"

#include <chrono>  

using namespace std::chrono;

#define SCREENWIDTH 20
#define SCREENHEIGHT 20

GameParameters parameters ;
Snake snakeObject;
Fruit fruitObject;
State stateObject;

enum eDirection direction = STOP;

int frame = 0;


int main()
{
	
	//init
	init_game_parameters(&parameters, SCREENWIDTH, SCREENHEIGHT);
	init(parameters, &stateObject, &snakeObject, &fruitObject);

	std::chrono::high_resolution_clock::time_point prev =
		std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::time_point current =
		std::chrono::high_resolution_clock::now();

	while (stateObject.gameOver == 'f')
	{
		current = std::chrono::high_resolution_clock::now();
		
	
		
		display_map(parameters, stateObject);
		display_snake(parameters, snakeObject, fruitObject);
		display_fruit(parameters, fruitObject);
		display_score(parameters, stateObject);
		
		

		//If the snake eats the fruit
		stateObject = generate_score(stateObject, snakeObject, fruitObject);
		fruitObject = generate_fruit(parameters, snakeObject, fruitObject);
		snakeObject = add_tail_number(snakeObject, fruitObject);



		direction = input(&stateObject, direction);
		set_instructions(parameters, &stateObject, &snakeObject, direction);

		if (std::chrono::duration_cast<std::chrono::microseconds>(current - prev).count() >= 16000) {
			prev = current;
			frame++;
			std::cout <<"Frame = " << frame << std::endl;
		}
		else {
			
		
			//Sleep(chrono::microseconds(1));
		}
	
		
	}
	
	cout << "Game Over!" << endl;
	
	return 0;
}