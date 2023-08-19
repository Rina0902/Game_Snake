#include "snake.h"

GameParameters game_param;
Snake snake_var;
Fruit fruit_var;
enum eDirection dir;


int main()
{

	initializeGame(&game_param, 20, 20);
	setup(&game_param , &snake_var , &fruit_var , &dir);
	
	while (!game_param.gameOver)
	{
		
		draw(&game_param, &snake_var, &fruit_var);
		Sleep(80);
		dir = input(&game_param , &dir);
		logic(&game_param, &snake_var, dir);

	}
	cout << endl;
	cout << endl;
	cout << "Game Over!" << endl;

	return 0;
}