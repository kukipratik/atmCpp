#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include<fstream>

using namespace sf;
using namespace std;

class user
{
protected:
	//text and font for pin password...
	Font font;		Text balance;
	string amount;

	//for marking user amount in vector....
	/*
		lama ------> 0
		Shresta ---> 3
		Tharu -----> 6
		i.e. in position  0,3,6  their amount is located while storing in vector...
		Will be understood later...
	*/
	int userAmountMark;

private:
	vector<string> vec;
	void initVariables();

public:
	user();

	//selecting user in screen0...
	void makeBuffer(string userName);

	//authentication...
	bool authenticate(string pin);

	//show balance...
	void showBalance();

	//for storing each words of db in vector so that we can later use them to update dbase...
	void storeInVec();

	//for calculating new balance...
	string giveNewBalacne(int enteredAmount);

	//after money withdrawl...
	void updateDbase(string enteredAmount);

};

