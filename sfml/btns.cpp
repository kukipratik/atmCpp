#include "btns.h"

void btns::initVariables()
{
    this->showStarCount = 0;
    this->shouldGiveMoney = false;
    this->totalAmount = 0;
    this->finalPinEntered = 0;

    //loading font...
    if (!this->font.loadFromFile("res/courier_new.ttf")) {
        cout << "Font can't be loaded...";
    }

    //making key pin Sound...
    if (!keyBuf.loadFromFile("res/key_snd.wav"))
    {
        cout << "key_snd.wav can't be loaded...";
    }
    keySnd.setBuffer(keyBuf);

    //making menu Sound...
    if (!menuBuf.loadFromFile("res/menu_snd.wav"))
    {
        cout << "menu_snd.wav can't be loaded...";
    }
    menuSnd.setBuffer(menuBuf);

}

btns::btns()
{
    this->initVariables();
}

void btns::showStar()
{
    //logic...
    if (this->showStarCount < 4 && !this->clearPressed) {
        this->showStarCount++;
        cout << "increased"<<this->showStarCount << endl;
    }
    else if (this->showStarCount > 0 && this->clearPressed) {
        this->showStarCount--;
        cout << "decreased" << endl;
    }

    //settings for stars...
    this->pin.setFont(this->font);
    this->pin.setPosition(610, 329);
    this->pin.setCharacterSize(30);
    this->pin.setFillColor(sf::Color::Green);

    //displaying stars...
    if (this->showStarCount == 1) {
        this->pin.setString(" * ");
    }
    else if (this->showStarCount == 2) {
        this->pin.setString(" * * ");
    }
    else if (this->showStarCount == 3) {
        this->pin.setString(" * * * ");
    }
    else if (this->showStarCount == 4) {
        this->pin.setString(" * * * * ");
    }
}

void btns::giveEnteredPin(int num)
{
    if (num == -1) {
        this->finalPinEntered = this->finalPinEntered / 10;
    }
    else {
        string str = to_string(this->finalPinEntered);
        int length = str.length();
        if (length<4) {
            this->finalPinEntered = this->finalPinEntered * 10 + num;
        }
    }
    //cout << "Entered Pin = " << this->finalPinEntered << endl;
}

void btns::showEnteredAmount(int num)
{
    if (num == -1) {
        this->totalAmount = this->totalAmount / 10;
    }
    else if (std::to_string(this->totalAmount).length() <= 5) {
        this->totalAmount = this->totalAmount * 10 + num;
    }
    cout << "total Amount = " << this->totalAmount << endl;
    //setting up text to display...
    this->enteredAmount.setFont(this->font);
    this->enteredAmount.setString(to_string(this->totalAmount));
    this->enteredAmount.setPosition(600, 325);
    this->enteredAmount.setLetterSpacing(2);
    this->enteredAmount.setCharacterSize(40);
    this->enteredAmount.setFillColor(sf::Color::Green);
}

void btns::showEnteredANum(int num)
{
    if (num == -1) {
        this->ANum = this->ANum / 10;
    }
    else if(std::to_string(this->ANum).length() < 9) {
        this->ANum = this->ANum * 10 + num;
    }
    cout << "ANum = " << this->ANum << endl;
    //setting up text to display...
    this->enteredANum.setFont(this->font);
    this->enteredANum.setString(to_string(this->ANum));
    this->enteredANum.setPosition(550, 330);
    this->enteredANum.setLetterSpacing(2);
    this->enteredANum.setCharacterSize(38);
    this->enteredANum.setFillColor(sf::Color::Green);
}

void btns::unlockSideButton(int mouseX, int mouseY, int &drawScreen)
{
    //for R1 button...
    if (mouseX >= 1145 && mouseX <= 1220 && mouseY >= 220 && mouseY <= 285) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            drawScreen = 4; //asking for enter amount to money withdrawl...
            this->shouldGiveMoney = true; //This time we have to give money but wait for user to enter amount....
            menuSnd.play();
        }
    }

    //for R2 button...
    if (mouseX >= 1145 && mouseX <= 1220 && mouseY >= 305 && mouseY <= 365) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            drawScreen = 8; //asking for account number to fund transfer...
            menuSnd.play();
        }
    }

    //for l1 button...
    if (mouseX >= 150 && mouseX <= 222 && mouseY >= 220 && mouseY <= 285) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            drawScreen = 5; //showing current balance for the current user...
            menuSnd.play();
        }
    }

    //for l2 button...
    if (mouseX >= 150 && mouseX <= 222 && mouseY >= 305 && mouseY <= 365) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            //drawScreen = 4; //screen to change pin password...
            //menuSnd.play();
        }
    }
}

void btns::pinEntered(int mouseX, int mouseY, int drawScreen)
{
    //for key 1...
    if (mouseX >= 492 && mouseX <= 567 && mouseY >= 718 && mouseY <= 776) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            keySnd.play();
            if (drawScreen == 2) {
                this->showStar();
                this->giveEnteredPin(1);
            }
            else if (drawScreen == 4) {
                this->showEnteredAmount(1);
            }
            else if (drawScreen == 8) {
                this->showEnteredANum(1);
            }
            cout << "1 entered." << endl;
        }
    }

    //for key 2...
    else if (mouseX >= 585 && mouseX <= 667 && mouseY >= 716 && mouseY <= 776) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            keySnd.play();
            if (drawScreen == 2) {
                this->showStar();
                this->giveEnteredPin(2);
            }
            else if (drawScreen == 4) {
                this->showEnteredAmount(2);
            }
            else if (drawScreen == 8) {
                this->showEnteredANum(2);
            }
            cout << "2 entered." << endl;
        }
    }

    //for key 3...
    else if (mouseX >= 685 && mouseX <= 757 && mouseY >= 718 && mouseY <= 776) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            keySnd.play();
            if (drawScreen == 2) {
                this->showStar();
                this->giveEnteredPin(3);
            }
            else if (drawScreen == 4) {
                this->showEnteredAmount(3);
            }
            else if (drawScreen == 8) {
                this->showEnteredANum(3);
            }
            cout << "3 entered." << endl;
        }
    }

    //for key 4...
    else if (mouseX >= 492 && mouseX <= 567 && mouseY >= 796 && mouseY <= 856) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            keySnd.play();
            if (drawScreen == 2) {
                this->showStar();
                this->giveEnteredPin(4);
            }
            else if (drawScreen == 4) {
                this->showEnteredAmount(4);
            }
            else if (drawScreen == 8) {
                this->showEnteredANum(4);
            }
            cout << "4 entered." << endl;
        }
    }

    //for key 5...
    else if (mouseX >= 586 && mouseX <= 667 && mouseY >= 798 && mouseY <= 858) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            keySnd.play();
            if (drawScreen == 2) {
                this->showStar();
                this->giveEnteredPin(5);
            }
            else if (drawScreen == 4) {
                this->showEnteredAmount(5);
            }
            else if (drawScreen == 8) {
                this->showEnteredANum(5);
            }
            cout << "5 entered." << endl;
        }
    }

    //for key 6...
    else if (mouseX >= 684 && mouseX <= 760 && mouseY >= 798 && mouseY <= 858) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            keySnd.play();
            if (drawScreen == 2) {
                this->showStar();
                this->giveEnteredPin(6);
            }
            else if (drawScreen == 4) {
                this->showEnteredAmount(6);
            }
            else if (drawScreen == 8) {
                this->showEnteredANum(6);
            }
            cout << "6 entered." << endl;
        }
    }

    //for key 7...
    else if (mouseX >= 492 && mouseX <= 567 && mouseY >= 878 && mouseY <= 940) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            keySnd.play();
            if (drawScreen == 2) {
                this->showStar();
                this->giveEnteredPin(7);
            }
            else if (drawScreen == 4) {
                this->showEnteredAmount(7);
            }
            else if (drawScreen == 8) {
                this->showEnteredANum(7);
            }
            cout << "7 entered." << endl;
        }
    }

    //for key 8...
    else if (mouseX >= 588 && mouseX <= 665 && mouseY >= 878 && mouseY <= 940) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            keySnd.play();
            if (drawScreen == 2) {
                this->showStar();
                this->giveEnteredPin(8);
            }
            else if (drawScreen == 4) {
                this->showEnteredAmount(8);
            }
            else if (drawScreen == 8) {
                this->showEnteredANum(8);
            }
            cout << "8 entered." << endl;
        }
    }

    //for key 9...
    else if (mouseX >= 683 && mouseX <= 760 && mouseY >= 878 && mouseY <= 940) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            keySnd.play();
            if (drawScreen == 2) {
                this->showStar();
                this->giveEnteredPin(9);
            }
            else if (drawScreen == 4) {
                this->showEnteredAmount(9);
            }
            else if (drawScreen == 8) {
                this->showEnteredANum(9);
            }
            cout << "9 entered." << endl;
        }
    }

    //for key 0...
    else if (mouseX >= 585 && mouseX <= 660 && mouseY >= 960 && mouseY <= 1020) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            keySnd.play();
            if (drawScreen == 2) {
                this->showStar();
                this->giveEnteredPin(0);
            }
            else if (drawScreen == 4) {
                this->showEnteredAmount(0);
            }
            else if (drawScreen == 8) {
                this->showEnteredANum(0);
            }
            cout << "0 entered." << endl;
        }
    }

    //for clear key...
    else if (mouseX >= 795 && mouseX <= 915 && mouseY >= 800 && mouseY <= 857) {
        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            menuSnd.play();
            this->clearPressed = true;
            if (drawScreen == 2) {
                this->showStar();
                this->giveEnteredPin(-1);
            }
            else if (drawScreen == 4) {
                this->showEnteredAmount(-1);
            }
            else if (drawScreen == 8) {
                this->showEnteredANum(-1);
            }
        this->clearPressed = false;
        cout << "clear entered." << endl;
    }
    }
}
