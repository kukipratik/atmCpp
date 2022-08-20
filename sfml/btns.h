#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>

using namespace sf;
using namespace std;

class btns
{
protected:
	//we need them in screen class(while drawingScreen)...
	int showStarCount;
	int totalAmount;
	int ANum; //account number...(ANum)
	bool shouldGiveMoney;
	int finalPinEntered;
	//text and font for pin password...
	Font font;					Text pin;
	Text enteredAmount;			Text enteredANum;

private:
	bool clearPressed;

	//sounds...
	SoundBuffer keyBuf;			Sound keySnd;
	SoundBuffer menuBuf;		Sound menuSnd;

	//private functions...
	void initVariables();

public:
	//constructor...
	btns();

	//for showing star while entering password...(for screen 2)
	void showStar();

	//for knowing what user has entered as pin...
	void giveEnteredPin(int num);

	//for showing entered amount....(for screen 4)
	void showEnteredAmount(int num);

	//for showing entered account number....(for screen 8 while fund transfer)
	void showEnteredANum(int num);

	//for pressing side buttons....
	void unlockSideButton(int mouseX, int mouseY, int &drawScreen);

	//for letting user enter pin....
	void pinEntered(int mouseX, int mouseY, int drawScreen);
};

