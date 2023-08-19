#include "Render.h"

using namespace std;

void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}


void Render::draw(Engine* E)
{

	char print = 'f';
	for (int8_t i = 0; i < E->getScreenHeight(); i++)
	{
		for (int8_t j = 0; j < E->getScreenWidth(); j++)
		{
			print = 'f';
			
		
			if (i == 1 || (i == E->getScreenWidth() - 1) )
			{
				gotoxy(j, i);
				printf("#");
				print = 't';
			}
			
			if (j == 0 || j == E->getScreenHeight() - 1)
			{
				gotoxy(j, i);
				printf("#");
				print = 't';
			}
			
			
			if (i == E->getY() && j == E->getX())
			{
				gotoxy(j, i);
				printf("O");
				print = 't';
			
 
			}

			if (i == E->getFruitY() && j == E->getFruitX())
			{
				gotoxy(j, i);		
				printf("*");
			}
			else
			{

				for (int k = 0; k < E->getNumberTail(); k++)
				{

					if (E->getTailX()[k] == j && E->getTailY()[k] == i)
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
	
	

	if ((E->getX() == E->getFruitX()) && (E->getY() == E->getFruitY()))
	{
		
		cout << endl;
		
		E->setFruitX((rand() % (E->getScreenWidth() - 1)) + 1 );
		E->setFruitY((rand() % (E->getScreenHeight() - 1)) + 2 );
		E->setScore(E->getScore() + 10);
		E->setNumberTail(E->getNumberTail() + 1);


	}

	cout << endl;
	gotoxy(0, 21);
	printf("Your Score is : ");
	cout << E->getScore() << endl;
	gotoxy(0, 23);
	printf("Press X to exit the game. ");


}