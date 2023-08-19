#include "snake.h"



void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}

void initializeGame(GameParameters* game_parameter, const int screenWidthVariable, const int screenHeightVariable)
{
	
	game_parameter->screenWidth = screenWidthVariable;
	game_parameter->screenHeight = screenHeightVariable;
}

void setup(GameParameters* game_parameter, Snake* snake_variable, Fruit* fruit_variable, eDirection* dir_variable)
{
	game_parameter->gameOver = false;
	*dir_variable =	STOP;
	snake_variable->x = game_parameter->screenWidth / 2;
	snake_variable->y = game_parameter->screenHeight / 2;
	fruit_variable->fruitX = rand() % game_parameter->screenWidth + 1;
	fruit_variable->fruitY = rand() % game_parameter->screenHeight + 1;
	game_parameter->score = 0;

}

eDirection input(GameParameters* game_parameter, eDirection* dir_variable)
{

	//I fthe keyboard key is pressed
	if (_kbhit())
	{
		// _getch return the ASCII value of our character that is pressed in the keyboard
		switch (_getch())
		{
		case 'z':
		case 'Z':
		case 'w':
		case 'W':

			*dir_variable = UP;
			break;

		case 'q':
		case 'Q':
		case 'a':
		case 'A':
			*dir_variable = LEFT;
			break;
		case 'd':
		case 'D':
		
			*dir_variable = RIGHT;
			break;
		case 's':
		case 'S':
			*dir_variable = DOWN;
			break;
		case 'x':
		case 'X':
			game_parameter->gameOver = true;
			break;
		default:
			break;
		}
	}
	return *dir_variable;


}

void logic(GameParameters* game_parameter, Snake* snake_variable, eDirection dir_variable)
{
	int8_t previousValueX = snake_variable->tailX[0]; 
	int8_t previousValueY = snake_variable->tailY[0];
	int8_t previousValue2X, previousValue2Y;
	snake_variable->tailX[0] = snake_variable->x;
	snake_variable->tailY[0] = snake_variable->y;
	for (int8_t i = 1; i < snake_variable->numberTail; i++)
	{
		previousValue2X = snake_variable->tailX[i];
		previousValue2Y = snake_variable->tailY[i];
		snake_variable->tailX[i] = previousValueX;
		snake_variable->tailY[i] = previousValueY;
		previousValueX = previousValue2X;
		previousValueY = previousValue2Y;
	}
	
	switch (dir_variable)
	{
	case UP:
		
		snake_variable->y = snake_variable->y -1;
		break;

	case LEFT:
		snake_variable->x = snake_variable->x - 1;
	
		break;

	case RIGHT:
		snake_variable->x = snake_variable->x + 1;
	
		break;

	case DOWN:
		snake_variable->y = snake_variable->y + 1;
	
		break;
	default:
		break;

	}
	if ((snake_variable->x > game_parameter->screenWidth - 2 || snake_variable->x < 2) || (snake_variable->y > game_parameter->screenHeight - 2 || snake_variable->y < 2))
		game_parameter->gameOver = true;
		

	for (int8_t i = 0; i < snake_variable->numberTail; i++)
	{
		if (snake_variable->tailX[i] == snake_variable->x && snake_variable->tailY[i] == snake_variable->y)
			game_parameter->gameOver = true;
	}

}


void draw(GameParameters* game_parameter, Snake* snake_variable, Fruit* fruit_variable)
{

	char print = 'f';
	for (int8_t i = 0; i < game_parameter->screenHeight; i++)
	{
		for (int8_t j = 0; j < game_parameter->screenWidth; j++)
		{
			print = 'f';


			if (i == 1 || (i == game_parameter->screenWidth - 1))
			{
				gotoxy(j, i);
				printf("#");
				print = 't';
			}

			if (j == 0 || j == game_parameter->screenHeight - 1)
			{
				gotoxy(j, i);
				printf("#");
				print = 't';
			}


			if (i == snake_variable->y && j == snake_variable->x)
			{
				gotoxy(j, i);
				printf("O");
				print = 't';


			}

			if (i == fruit_variable->fruitY && j == fruit_variable->fruitX)
			{
				gotoxy(j, i);
				printf("*");
			}
			else
			{

				for (int k = 0; k < snake_variable->numberTail; k++)
				{

					if (snake_variable->tailX[k] == j && snake_variable->tailY[k] == i)
					{
						gotoxy(j, i);
						printf("o");
						print = 't';
					}
				}
			}

			if (print == 'f')
			{

				printf(" ");
			}
		}
	}



	if (((snake_variable->x) == fruit_variable->fruitX) && ((snake_variable->y) == fruit_variable->fruitY))
	{

		cout << endl;
		fruit_variable->fruitX = rand() % (game_parameter->screenWidth - 1) + 1;
		fruit_variable->fruitY = rand() % (game_parameter->screenHeight - 1) + 2;
		game_parameter->score = game_parameter->score + 10;
		snake_variable->numberTail = snake_variable->numberTail + 1;
	


	}

	cout << endl;
	gotoxy(0, 21);
	printf("Your Score is : ");
	cout << game_parameter->score << endl;
	gotoxy(0, 23);
	printf("Press X to exit the game. ");


}