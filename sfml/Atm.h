#pragma once

#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "screen.h"

using namespace sf;
using namespace std;

class Atm: public screen
{
private:
	//General...
	RenderWindow* window;
	Event event;
	VideoMode videoMode;

	//Mouse position...
	int mouseX;					int mouseY;

	//background...(ATM Machine)
	Texture bg;					RectangleShape bground;

	//private functions....
	void initVariables();
	void initWindow();

public:
	//Constructors and destructors...
	Atm();
	virtual ~Atm();

	//this retruns true if window is running...
	const bool running() const;

	//public functions...
	void updateMousePosition();
	void pollEvents();

	//updating and rendering...
	void update();
	void render();
};

