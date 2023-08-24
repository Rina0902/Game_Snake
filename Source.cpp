#include "snake.h"

GameParameters parameters ;
Snake snakeObject;
Fruit fruitObject;
State stateObject;
enum eDirection dir;


int main()
{

	initializeGame(&parameters, 20, 20);
	setup(&parameters, &stateObject, &snakeObject, &fruitObject, &dir);
	
	while (stateObject.gameOver == 'f')
	{
		
		//interface
		
		draw_map(parameters, stateObject);
		draw_snake(parameters, snakeObject, fruitObject);
		draw_fruit(parameters, fruitObject);
		write_score(&stateObject);
		//Generate the score and the fruit axe
		generate(&parameters, &stateObject, &snakeObject, &fruitObject);
		Sleep(80);
		input(&parameters, &stateObject, &dir);
		setInstructions(&parameters,  &stateObject, &snakeObject, &dir);
	

	}
	cout << endl;
	cout << endl;
	cout << "Game Over!" << endl;

	return 0;
}