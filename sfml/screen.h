#pragma once

#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "btns.h"
#include "user.h"

using namespace sf;
using namespace std;

class screen:private btns,private user
{
protected:
	//variables...
	int drawScreen;  //it will help us keep track of the screens...
	bool giveReceipt;
	bool nowGiveMoney;
	bool userCollectedReceipt;
	bool userCollectedMoney;

private:

	//sounds...
	SoundBuffer cardBuf;		Sound cardSnd;
	SoundBuffer menuBuf;		Sound menuSnd;
	SoundBuffer cashBuf;		Sound cashSnd;
	SoundBuffer clickBuf;		Sound clickSnd;

	//error Messages...
	Text errorMsg1;				Text errorMsg2;
	Text errorMsg3;				Text errorMsg4;

	//card...
	Texture cardImg;			RectangleShape card;

	//Receipt...
	Texture receiptImg;			RectangleShape receipt;

	//money...
	Texture moneyImg1000;		RectangleShape money1000;
	Texture moneyImg500;		RectangleShape money500;

	//screen0...(Please select user)
	Texture screen0Img;			RectangleShape screen0;

	//screen1...(Please insert card)
	Texture screen1Img;			RectangleShape screen1;

	//screen2...(Enter your pin)
	Texture screen2Img;			RectangleShape screen2;

	//screen3...(Select what you want to do)
	Texture screen3Img;			RectangleShape screen3;

	//screen4...(Enter amount for transaction)
	Texture screen4Img;			RectangleShape screen4;

	//screen5...(Showing current user balance)
	Texture screen5Img;			RectangleShape screen5;

	//screen6...(succesfully Terminated)
	Texture screen6Img;			RectangleShape screen6;

	//screen7...(Processing plz Wait...)
	Texture screen7Img;			RectangleShape screen7;

	//screen8...(Enter Account number for fund transfer...)
	Texture screen8Img;			RectangleShape screen8;

	//private functions...
	void initVariables();

public:
	//constructor...
	screen();

	//if pressed cancel then reset everything in screen...
	void cancelPressed(int mouseX, int mouseY);

	//for changing screens...
	void changingScreen(int mouseX,int mouseY);

	//for drawing screens...
	void drawingScreen(RenderWindow* );
};

