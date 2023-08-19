#include "Render.h"

using namespace std;

void gotoxy(int x, int y)
{
	printf("%c[%d;%df", 0x1B, y, x);
}


void Render::draw(Engine* E)
{

	bool print = false;
	for (int32_t i = 0; i < E->getScreenHeight(); i++)
	{
		for (int32_t j = 0; j < E->getScreenWidth(); j++)
		{
			print = false;
			
		
			if (i == 1 || (i == E->getScreenWidth() - 1) )
			{
				gotoxy(j, i);
				printf("#");
				print = true;
			}
			
			if (j == 0 || j == E->getScreenHeight() - 1)
			{
				gotoxy(j, i);
				printf("#");
				print = true;
			}
			
			
			if (i == E->getY() && j == E->getX())
			{
				gotoxy(j, i);
				printf("O");
				print = true;
			
 
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
						print = true;
					}
				}
			}
			
			if (!print)
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
		cout << "Fruit X : " << E->getFruitX() << endl;
		cout << "Fruit Y :  " << E->getFruitY() << endl;
		E->setScore(E->getScore() + 10);
		E->setNumberTail(E->getNumberTail() + 1);


	}

	cout << endl;
	//cout << "Your Score is " << E->getScore() << endl;


}