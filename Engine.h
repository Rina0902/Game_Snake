#pragma once

#include <conio.h>
#include <iostream>

enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };

using namespace std;

class Engine
{
private:
	
	int x, y, fruitX, fruitY, score;
	int tailX[100], tailY[100];
	int numberTail = 0;

	int screenWidth;
	int screenHeight;

	bool gameOver;

public:

	

	void initializeEngine(const int screenWidthVariable, const int screenHeightVariable);
	void setup(eDirection dir_variable);
	eDirection input(eDirection dir_variable);
	void logic(eDirection dir_variable);

	
	// Setter 
	void setGameOver(bool gameOverVariable);
	void setScreenWidth(int screenWidthVariable);
	void setScreenHeight(int screenHeightVariable);
	void setX(int variableX);
	void setY(int variableY);
	void setFruitX(int variableFuitX);
	void setFruitY(int variableFuitY);
	void setScore(int scoreVariable);
	void setNumberTail(int numberTail);
	void setTailX(int* tailX_variable);
	void setTailY(int* tailY_variable);

	// Getter
	bool getGameOver();
	int getScreenWidth();
	int getScreenHeight();
	int getX();
	int getY();
	int getFruitX();
	int getFruitY();
	int getScore();
	int getNumberTail();
	int* getTailX();
	int* getTailY();


};






