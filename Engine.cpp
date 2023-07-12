#include "Engine.h"


// Setter 
void Engine::setGameOver(bool gameOverVariable) {
	gameOver = gameOverVariable;
}
void Engine::setScreenWidth(int screenWidthVariable) {
	screenWidth = screenWidthVariable;
}
void Engine::setScreenHeight(int screenHeightVariable) {
	screenHeight = screenHeightVariable;
}
void Engine::setX(int variableX) {
	x = variableX;
}
void Engine::setY(int variableY) {
	y = variableY;
}
void Engine::setFruitX(int variableFuitX) {
	fruitX = variableFuitX;
}
void Engine::setFruitY(int variableFuitY) {
	fruitY = variableFuitY;
}
void Engine::setScore(int scoreVariable) {
	score = scoreVariable;
}
void Engine::setNumberTail(int numberTailVariable) {
	numberTail = numberTailVariable;
}
void Engine::setTailX(int* tailX_Variable) 
{
	for (int i = 0; i < 100; i++)
		tailX[i] = tailX_Variable[i];
	
}
void Engine::setTailY(int* tailY_Variable)
{
	for (int i = 0; i < 100; i++)
		tailY[i] = tailY_Variable[i];

}

// Getter
bool Engine::getGameOver() {
	return gameOver;
}
int Engine::getScreenWidth() {
	return screenWidth;
}
int Engine::getScreenHeight() {
	return screenHeight;
}
int Engine::getX() {
	return x;
}
int Engine::getY() {
	return y;
}
int Engine::getFruitX() {
	return fruitX;
}
int Engine::getFruitY() {
	return fruitY;
}
int Engine::getScore() {
	return score;
}
int Engine::getNumberTail() {
	return numberTail;
}
int* Engine::getTailX() 
{
	return tailX;
}
int* Engine::getTailY() {
	
	return tailY;
}

void Engine::initializeEngine(const int screenWidthVariable, const int screenHeightVariable)
{
	setScreenWidth(screenWidthVariable);
	setScreenHeight(screenHeightVariable);
}

void Engine::setup(eDirection dir_variable)
{
	setGameOver(false);
	dir_variable = STOP;
	setX(getScreenWidth() / 2);
	setY(getScreenHeight() / 2);
	setFruitX(rand() % getScreenWidth());
	setFruitY(rand() % getScreenHeight());
	setScore(0);

}


eDirection Engine::input(eDirection dir_variable)
{
	//I fthe keyboard key is pressed
	if (_kbhit())
	{
		// _getch return the ASCII value of our character that is pressed in the keyboard
		switch (_getch())
		{
		case 'z':
		case 'Z':
		
			dir_variable = UP;
			break;
		case 'q':
		case 'Q':
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
			setGameOver(true);
			break;
		default:
			break;
		}
	}

	return dir_variable;



}

void Engine::logic(eDirection dir_variable)
{
	int previousValueX = getTailX()[0];
	int previousValueY = getTailY()[0];
	int previousValue2X, previousValue2Y;
	getTailX()[0] = getX();
	getTailY()[0] = getY();
	for (int i = 1; i < getNumberTail(); i++)
	{
		previousValue2X = getTailX()[i];
		previousValue2Y = getTailY()[i];
		getTailX()[i] = previousValueX;
		getTailY()[i] = previousValueY;
		previousValueX = previousValue2X;
		previousValueY = previousValue2Y;
	}
	switch (dir_variable)
	{
	case UP:
		
		setY(getY()-1);
		break;

	case LEFT:
		setX(getX() - 1);
	
		break;

	case RIGHT:
		setX(getX() + 1);
	
		break;

	case DOWN:
		setY(getY() + 1);
	
		break;
	default:
		break;

	}
	if ((getX() > getScreenWidth() - 2 || getX() < 0) || (getY() > getScreenHeight() - 1 || getY() < 0))

		setGameOver(true);

	for (int i = 0; i < getNumberTail(); i++)
	{
		if (getTailX()[i] == getX() && getTailY()[i] == getY())
			setGameOver ( true );
	}

}