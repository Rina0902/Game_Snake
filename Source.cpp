#include "snake.h"

GameParameters parameters ;
Snake snakeObject;
Fruit fruitObject;
State stateObject;

const GameParameters& ref_parameters = parameters;
const Snake& ref_snakeObject = snakeObject;
const Fruit& ref_fruitObject = fruitObject;
const State& ref_stateObject = stateObject;

enum eDirection dir;


int main()
{

	initializeGame(&parameters, 20, 20);
	setup(&parameters, &stateObject, &snakeObject, &fruitObject, &dir);
	
	while (stateObject.gameOver == 'f')
	{
		
		//interface
		
		draw_map(ref_parameters, ref_stateObject);
		draw_snake(ref_parameters, ref_snakeObject, ref_fruitObject);
		draw_fruit(ref_parameters, ref_fruitObject);
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