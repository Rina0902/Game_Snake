
#include "Render.h"
#include "Engine.h"

Render renderGame;
Engine gameEngine;
enum eDirection dir;

int main()
{
	
	gameEngine.initializeEngine(20, 20);
	gameEngine.setup(dir);
	while (!gameEngine.getGameOver())
	{
		gameEngine = renderGame.draw(gameEngine);
		Sleep(50);
		dir = gameEngine.input(dir);
		gameEngine.logic(dir);
		
	}
	cout << endl;
	cout << endl;
	cout << "Game Over!" << endl;
	
	return 0;
}