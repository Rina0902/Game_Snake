#include "Render.h"



Engine Render::draw(Engine E)
{
	//HWND consoleWindow = GetConsoleWindow();
	//HDC consoleDC = GetDC(consoleWindow);
	
	system("cls");
	for (int i = 0; i <= E.getScreenWidth(); i++)
	{
		cout << "#";

	}
	cout << endl;
	for (int i = 0; i < E.getScreenHeight(); i++)
	{
		for (int j = 0; j < E.getScreenWidth(); j++)
		{
			if ((j == 0) || (j == E.getScreenWidth() - 1))
				cout << "#";

			if (i == E.getY() && j == E.getX())
			{
				

				//for (int l = 0; l<7; l++)
				//	for (int s=0;s<7;s++)
				//		SetPixel(consoleDC, i+l,j+s, RGB(0, 255, 0));


				cout << "O";
				
			}

			else if (i == E.getFruitY() && j == E.getFruitX())
				cout << "*";
			else
			{
				bool print = false;
				for (int k = 0; k < E.getNumberTail(); k++)
				{

					if (E.getTailX()[k] == j && E.getTailY()[k] == i)
					{
						cout << "o";
						print = true;
					}

				}
				if (!print)
					cout << " ";

			}

		}
		cout << endl;

	}
	for (int i = 0; i <= E.getScreenWidth(); i++)
	{
		cout << "#";

	}

	if ((E.getX() == E.getFruitX()) && (E.getY() == E.getFruitY()))
	{
		cout << "yey sucees";

		E.setFruitX (rand() % E.getScreenWidth()) ;
		E.setFruitY(rand() % E.getScreenHeight()) ;
		E.setScore( E.getScore() + 10) ;
		E.setNumberTail(E.getNumberTail() + 1);
	

	}

	cout << endl;
	cout << "Your Score is " << E.getScore() << endl;
	//ReleaseDC(consoleWindow, consoleDC);

	return E;

}
