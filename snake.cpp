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

void init_snake(const GameParameters& game_parameter, Snake* snake_variable)
{
	snake_variable->x = rand() % game_parameter.screenWidth + 1;
	snake_variable->y = rand() % game_parameter.screenHeight + 2;
	snake_variable->numberTail = 0;
}

void init_state(State* stateObject)
{
	
	stateObject->gameOver = 'f';
	stateObject->score = 0;
}

void init_fruit(const GameParameters & game_parameter, Fruit * fruit_variable)
{

	fruit_variable->fruitX = rand() % game_parameter.screenWidth + 1;
	fruit_variable->fruitY = rand() % game_parameter.screenHeight + 2;
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
		
		snake_variable->y --;
		break;

	case LEFT:
		snake_variable->x --;
	
		break;

	case RIGHT:
		snake_variable->x ++;
	
		break;

	case DOWN:
		snake_variable->y ++;
	
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
void display_snake(const GameParameters& game_parameter, const Snake& snakeObject, const Fruit& fruitObject, const Snake& aiSnakeObject)
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
			else if (i == aiSnakeObject.y && j == aiSnakeObject.x)
			{
				if ((0 < aiSnakeObject.y < 20) && (0 < aiSnakeObject.x < 20))
				{
					gotoxy(j, i);
					printf("X");
					print = 't';
				}



			}
			else if((print == 'f') && (!(i == fruitObject.fruitY && j == fruitObject.fruitX)))
			{
				gotoxy(j, i);
				printf(" ");
			}
			
			for (int k = 0; k < snakeObject.numberTail; k++)
			{
				gotoxy(0, 27);
				printf("enter");
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

void display_score(const GameParameters& game_parameter, const State& stateObject)
{
	cout << endl;
	gotoxy(0, game_parameter.screenHeight + 1);
	printf("Your Score is : ");
	cout << stateObject.score << endl;
	gotoxy(0, game_parameter.screenHeight + 3);
	printf("Press X to exit the game.\n \n");
}

State generate_score(State stateObject,const Snake& snakeObject,const Fruit& fruitObject)
{
	if (((snakeObject.x) == fruitObject.fruitX) && ((snakeObject.y) == fruitObject.fruitY))
	{
		stateObject.score = stateObject.score + 10;
	}
	return stateObject;
}

Fruit generate_fruit(const GameParameters& game_parameter,const Snake& snakeObject, Fruit fruitObject)
{
	
	if (((snakeObject.x) == fruitObject.fruitX) && ((snakeObject.y) == fruitObject.fruitY))
	{
		
		fruitObject.fruitX = rand() % (game_parameter.screenWidth - 1) + 1;
		fruitObject.fruitY = rand() % (game_parameter.screenHeight - 1) + 1;
		
	}
	return fruitObject;
}

void add_tail_number(Snake* snakeObject, const Fruit& fruitObject)
{

	if (((snakeObject->x) == fruitObject.fruitX) && ((snakeObject->y) == fruitObject.fruitY))
	{
		snakeObject->numberTail ++;
	}

}

void move_aiSnake(Snake* snakeObject, eDirection* dir_variable)
{

	*dir_variable = static_cast<eDirection>(rand() % DOWN);
	int8_t previousValueX = snakeObject->tailX[0];
	int8_t previousValueY = snakeObject->tailY[0];
	int8_t previousValue2X, previousValue2Y;
	snakeObject->tailX[0] = snakeObject->x;
	snakeObject->tailY[0] = snakeObject->y;
	for (int8_t i = 1; i < snakeObject->numberTail; i++)
	{
		previousValue2X = snakeObject->tailX[i];
		previousValue2Y = snakeObject->tailY[i];
		snakeObject->tailX[i] = previousValueX;
		snakeObject->tailY[i] = previousValueY;
		previousValueX = previousValue2X;
		previousValueY = previousValue2Y;
	}
	bool var = (0 > snakeObject->y || snakeObject->y >= 20);
	cout << "var = " << var << endl;
	switch (*dir_variable)
	{
	case UP:
		snakeObject->y--;
		if (0 > snakeObject->y || snakeObject->y >= 20)
		{

			snakeObject->y++;
		}
		snakeObject->y++;
		break;

	case LEFT:
		snakeObject->x--;
		if (0 > snakeObject->x && snakeObject->x >= 20)
		{
			snakeObject->x++;
		}
		if ((snakeObject->x == 21) || (snakeObject->x == 20))
		{
			snakeObject->x = snakeObject->x - 2;
		}
		break;



	case RIGHT:
		snakeObject->x++;
		if (0 > snakeObject->x && snakeObject->x >= 20)
		{
			snakeObject->x--;
		}
		if ((snakeObject->x == 21) || (snakeObject->x == 20))
		{
			snakeObject->x = snakeObject->x - 2;
		}
		break;


	case DOWN:
		snakeObject->y++;
		if (1 > snakeObject->y && snakeObject->y >= 20)
		{
			snakeObject->y--;

		}
		break;



	default:
		break;

	}





}