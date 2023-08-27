#include "snake.h"



void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}

void init_game_parameters(GameParameters* parameters, const int screenWidthVariable, const int screenHeightVariable)
{
	parameters->screenWidth = screenWidthVariable;
	parameters->screenHeight = screenHeightVariable;
}

void init(const GameParameters& game_parameter, State* stateObject,  Snake* snake_variable, Fruit* fruit_variable)
{
	
	stateObject->gameOver = 'f';
	stateObject->score = 0;
	snake_variable->x = game_parameter.screenWidth / 2;
	snake_variable->y = game_parameter.screenHeight / 2;
	fruit_variable->fruitX = rand() % game_parameter.screenWidth + 1;
	fruit_variable->fruitY = rand() % game_parameter.screenHeight + 1;
}



eDirection input(State* stateObject, eDirection dir_variable)
{
	//If the keyboard key is pressed, the function Keyboard Hit is true
	if (_kbhit())
	{
		// the function get character return the ASCII value of our character that is pressed in the keyboard
		switch (_getch())
		{
		case 'z':
		case 'Z':
		case 'w':
		case 'W':

			dir_variable = UP;
			break;

		case 'q':
		case 'Q':
		case 'a':
		case 'A':
			dir_variable = LEFT;
			break;
		case 'd':
		case 'D':
		
			dir_variable = RIGHT;
			break;
		case 's':
		case 'S':
			dir_variable = DOWN;
			break;
		case 'x':
		case 'X':
			stateObject->gameOver = 't';
			break;
		default:
			break;
		}
	}
	return dir_variable;
}

void set_instructions(const GameParameters& game_parameter, State* stateObject, Snake* snake_variable,const eDirection& dir_variable)
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
	if ((snake_variable->x > game_parameter.screenWidth - 2 || snake_variable->x < 2) || (snake_variable->y > game_parameter.screenHeight - 2 || snake_variable->y < 2))
		stateObject->gameOver = 't';
		

	for (int8_t i = 0; i < snake_variable->numberTail; i++)
	{
		if (snake_variable->tailX[i] == snake_variable->x && snake_variable->tailY[i] == snake_variable->y)
			stateObject->gameOver = true;
	}

}


void display_fruit(const GameParameters& game_parameter, const Fruit& fruitObject)
{
	char print = 'f';
	for (int8_t i = 0; i < game_parameter.screenHeight; i++)
	{
		for (int8_t j = 0; j < game_parameter.screenWidth; j++)
		{
			print = 'f';
			if (i == fruitObject.fruitY && j == fruitObject.fruitX)
			{

				gotoxy(j, i);
				printf("*");

			}

		}
	}
}
void display_snake(const GameParameters& game_parameter, const Snake& snakeObject, const Fruit& fruitObject)
{
	char print = 'f';
	for (int8_t i = 2; i < game_parameter.screenHeight-1; i++)
	{
		for (int8_t j = 2; j < game_parameter.screenWidth-1; j++)
		{
			print = 'f';
			if (i == snakeObject.y && j == snakeObject.x)
			{
				gotoxy(j, i);
				printf("O");
				print = 't';


			}
			else if((print == 'f') && (!(i == fruitObject.fruitY && j == fruitObject.fruitX)))
			{
				gotoxy(j, i);
				printf(" ");
			}
		
			for (int k = 0; k < snakeObject.numberTail; k++)
			{

				if (snakeObject.tailX[k] == j && snakeObject.tailY[k] == i)
				{
					gotoxy(j, i);
					printf("o");
					print = 't';
				}
			}	
		}
	}
}

void display_map(const GameParameters& game_parameter,const State& stateObject)
{
	char print = 'f';
	for (int8_t i = 0; i < game_parameter.screenHeight; i++)
	{
		for (int8_t j = 0; j < game_parameter.screenWidth; j++)
		{
			print = 'f';


			if (i == 1 || (i == game_parameter.screenWidth - 1))
			{
				gotoxy(j, i);
				printf("#");
				print = 't';
			}

			if (j == 0 || j == game_parameter.screenHeight - 1)
			{
				gotoxy(j, i);
				printf("#");
				print = 't';
			}
		}
	}
}

void display_score(const State& stateObject)
{
	cout << endl;
	gotoxy(0, 21);
	printf("Your Score is : ");
	cout << stateObject.score << endl;
	gotoxy(0, 23);
	printf("Press X to exit the game.\n \n");
}

State generate_score(State stateObject, Snake snakeObject, Fruit fruitObject)
{
	if (((snakeObject.x) == fruitObject.fruitX) && ((snakeObject.y) == fruitObject.fruitY))
	{
		stateObject.score = stateObject.score + 10;

	}
	return stateObject;
}

Fruit generate_fruit(GameParameters game_parameter,Snake snakeObject, Fruit fruitObject)
{
	if (((snakeObject.x) == fruitObject.fruitX) && ((snakeObject.y) == fruitObject.fruitY))
	{
		
		fruitObject.fruitX = rand() % (game_parameter.screenWidth - 1) + 1;
		fruitObject.fruitY = rand() % (game_parameter.screenHeight - 1) + 2;
	}
	return fruitObject;
}

Snake add_tail_number( Snake snakeObject, Fruit fruitObject)
{
	if (((snakeObject.x) == fruitObject.fruitX) && ((snakeObject.y) == fruitObject.fruitY))
	{
		snakeObject.numberTail = snakeObject.numberTail + 1;
	}
	return snakeObject;
}