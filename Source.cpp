#include "snake.h"

#define SCREENWIDTH 20
#define SCREENHEIGHT 20

GameParameters parameters ;
Snake snakeObject;
Fruit fruitObject;
State stateObject;

enum eDirection direction = STOP;


int main()
{
	//init
	init_game_parameters(&parameters, SCREENWIDTH, SCREENHEIGHT);
	init(parameters, &stateObject, &snakeObject, &fruitObject);


	while (stateObject.gameOver == 'f')
	{
		
		display_map(parameters, stateObject);
		display_snake(parameters, snakeObject, fruitObject);
		display_fruit(parameters, fruitObject);
		display_score(stateObject);

		//If the snake eats the fruit
		stateObject =  generate_score(stateObject,snakeObject,fruitObject);
		fruitObject =  generate_fruit(parameters, snakeObject, fruitObject);
		snakeObject = add_tail_number(snakeObject, fruitObject);

		Sleep(80);

		direction = input(&stateObject, direction);
		set_instructions(parameters,  &stateObject, &snakeObject, direction);
	
	}
	
	cout << "Game Over!" << endl;
	
	return 0;
}