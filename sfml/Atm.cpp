#include "Atm.h"

void Atm::initVariables()
{
    //initializing the private variables...
    this->window = nullptr;

    //seting background image...
    if (!this->bg.loadFromFile("res/bg.jpg")) {
        cout << "Can't load bg image.";
    }
    
    //making the background...
    this->bground.setSize(Vector2f(1919, 1079));
    this->bground.setTexture(&bg);
}

void Atm::initWindow()
{
    //assigning values...
    this->videoMode.width = 1919;
    this->videoMode.height = 1079;

    //creating window...
    this->window = new RenderWindow(this->videoMode, "ATM", Style::Fullscreen);
    this->window->setFramerateLimit(60);
}

Atm::Atm()
{
    //getting ready with variables and windows...
    this->initVariables();
    this->initWindow();
}

Atm::~Atm()
{
    delete this->window;
}

const bool Atm::running() const
{
    //checking if window is open...
    return this->window->isOpen();
}

void Atm::updateMousePosition()
{
    //this will give us mouse position relative with to window...
    this->mouseX = Mouse::getPosition(*this->window).x;
    this->mouseY = Mouse::getPosition(*this->window).y;
    //cout << "(" << this->mouseX << "," << this->mouseY << ")" << endl;
}

void Atm::pollEvents()
{
    //Event polling...
    while (this->window->pollEvent(this->event)) {
        //for closing window...
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            this->window->close();

        //for closing window with exit button on window...
        if (this->mouseX >= 150 && this->mouseX <= 285 && this->mouseY >= 981 && this->mouseY <= 1036) {
            if (Mouse::isButtonPressed(sf::Mouse::Left)) {
                this->window->close();
            }
        }

        //for changing between screens...
        this->changingScreen(this->mouseX,this->mouseY);
    }
}

void Atm::update()
{
    this->pollEvents();
    this->updateMousePosition();
}

void Atm::render()
{
    //for clearing previous windows' objects and making new things in it...
    this->window->clear(Color::Blue);

    //drawing background...
    this->window->draw(this->bground);

    //drawing screens...
    this->drawingScreen(this->window);

    //displaying drawn objects...
    this->window->display();
}
