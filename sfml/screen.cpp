#include "screen.h"

void screen::initVariables()
{
	//initializing variable...
	this->drawScreen = 0;
	this->nowGiveMoney = false;
	this->giveReceipt = false;
	this->userCollectedMoney = false;
	this->userCollectedReceipt = false;

	//making click sound...
	if (!clickBuf.loadFromFile("res/click_snd.wav"))
	{
		cout << "click_snd.wav can't be loaded...";
	}
	clickSnd.setBuffer(clickBuf);

	//making menu sound...
	if (!menuBuf.loadFromFile("res/menu_snd.wav"))
	{
		cout << "menu_snd.wav can't be loaded...";
	}
	menuSnd.setBuffer(menuBuf);

	//making cash sound...
	if (!cashBuf.loadFromFile("res/cash_snd.wav"))
	{
		cout << "cash_snd.wav can't be loaded...";
	}
	cashSnd.setBuffer(cashBuf);

	//making card sound...
	if (!cardBuf.loadFromFile("res/card_snd.wav"))
	{
		cout << "card_snd.wav can't be loaded...";
	}
	cardSnd.setBuffer(cardBuf);

	//making card...
	if (!this->cardImg.loadFromFile("res/card.png")) {
		cout << "Can't load card image.";
	}
	this->card.setSize(Vector2f(297, 350));
	this->card.setPosition(1387, 340);
	this->card.setTexture(&cardImg);

	//making receipt...
	if (!this->receiptImg.loadFromFile("res/receipt.jpg")) {
		cout << "Can't load receipt image.";
	}
	this->receipt.setSize(Vector2f(297, 350));
	this->receipt.setPosition(1380, 93);
	this->receipt.setTexture(&receiptImg);

	//making 500Note...
	if (!this->moneyImg500.loadFromFile("res/500note.png")) {
		cout << "Can't load 500note image.";
	}
	this->money500.setSize(Vector2f(420, 215));
	this->money500.setPosition(1328, 790);
	this->money500.setTexture(&moneyImg500);

	//making 1000Note...
	if (!this->moneyImg1000.loadFromFile("res/1000note.png")) {
		cout << "Can't load 1000note image.";
	}
	this->money1000.setSize(Vector2f(420, 215));
	this->money1000.setPosition(1328, 800);
	this->money1000.setTexture(&moneyImg1000);

	//Making screen0...
	if (!this->screen0Img.loadFromFile("res/screen0.png")) {
		cout << "Can't load screen0 image.";
	}
	this->screen0.setSize(Vector2f(865, 510));
	this->screen0.setPosition(252, 32);
	this->screen0.setTexture(&screen0Img);

	//Making screen1...
	if (!this->screen1Img.loadFromFile("res/screen1.jpg")) {
		cout << "Can't load screen1 image.";
	}
	this->screen1.setSize(Vector2f(865, 510));
	this->screen1.setPosition(252, 32);
	this->screen1.setTexture(&screen1Img);

	//Making screen2...
	if (!this->screen2Img.loadFromFile("res/screen2.png")) {
		cout << "Can't load screen2 image.";
	}
	this->screen2.setSize(Vector2f(865, 510));
	this->screen2.setPosition(252, 32);
	this->screen2.setTexture(&screen2Img);

	//Making screen3...
	if (!this->screen3Img.loadFromFile("res/screen3.png")) {
		cout << "Can't load screen3 image.";
	}
	this->screen3.setSize(Vector2f(865, 510));
	this->screen3.setPosition(252, 32);
	this->screen3.setTexture(&screen3Img);

	//Making screen4...
	if (!this->screen4Img.loadFromFile("res/screen4.png")) {
		cout << "Can't load screen4 image.";
	}
	this->screen4.setSize(Vector2f(865, 510));
	this->screen4.setPosition(252, 32);
	this->screen4.setTexture(&screen4Img);

	//Making screen5...
	if (!this->screen5Img.loadFromFile("res/screen5.png")) {
		cout << "Can't load screen5 image.";
	}
	this->screen5.setSize(Vector2f(865, 510));
	this->screen5.setPosition(252, 32);
	this->screen5.setTexture(&screen5Img);

	//Making screen6...
	if (!this->screen6Img.loadFromFile("res/screen6.png")) {
		cout << "Can't load screen6 image.";
	}
	this->screen6.setSize(Vector2f(865, 510));
	this->screen6.setPosition(252, 32);
	this->screen6.setTexture(&screen6Img);

	//Making screen7...
	if (!this->screen7Img.loadFromFile("res/screen7.png")) {
		cout << "Can't load screen7 image.";
	}
	this->screen7.setSize(Vector2f(865, 510));
	this->screen7.setPosition(252, 32);
	this->screen7.setTexture(&screen7Img);

	//Making screen8...
	if (!this->screen8Img.loadFromFile("res/screen8.png")) {
		cout << "Can't load screen8 image.";
	}
	this->screen8.setSize(Vector2f(865, 510));
	this->screen8.setPosition(252, 32);
	this->screen8.setTexture(&screen8Img);

}

screen::screen()
{
	this->initVariables();
}

void screen::cancelPressed(int mouseX, int mouseY)
{
	//for cancel key...
	if (mouseX >= 800 && mouseX <= 915 && mouseY >= 715 && mouseY <= 775) {
		if (Mouse::isButtonPressed(sf::Mouse::Left)) {
			menuSnd.play();
			//reset everything and go back to screen1...
			this->showStarCount = 0;
			this->drawScreen = 0;
			this->totalAmount = 0;
			this->shouldGiveMoney = false;
			this->nowGiveMoney = false;
			this->giveReceipt = false;
			this->userCollectedMoney = false;
			this->userCollectedReceipt = false;
			cout << "cancel entered." << endl;
		}
	}
}

void screen::changingScreen(int mouseX, int mouseY)
{
	//selecting user...(in screen0)
	if (this->drawScreen == 0) {
		//for Pratik Lama...
		if (mouseX >= 380 && mouseX <= 725 && mouseY >= 200 && mouseY <= 230) {
			if (Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->makeBuffer("PratikLama");
				this->user::userAmountMark = 0;
				this->clickSnd.play();
				this->drawScreen = 1;
			}
		}
		//for Pratik Shrestha...
		if (mouseX >= 370 && mouseX <= 840 && mouseY >= 275 && mouseY <= 300) {
			if (Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->makeBuffer("PratikShrestha");
				this->user::userAmountMark = 3;
				this->clickSnd.play();
				this->drawScreen = 1;
			}
		}
		//for Pratik Tharu...
		if (mouseX >= 370 && mouseX <= 755 && mouseY >= 350 && mouseY <= 375) {
			if (Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->makeBuffer("PratikTharu");
				this->user::userAmountMark = 6;
				this->clickSnd.play();
				this->drawScreen = 1;
			}
		}
	}

	//clicking card with mouse...(in screen1)
	if (mouseX >= 1390 && mouseX <= 1680 && mouseY >= 345 && mouseY <= 685) {
		if (Mouse::isButtonPressed(sf::Mouse::Left) && this->drawScreen == 1) {
			this->cardSnd.play();
			//wait until sound finishes...
			while (cardSnd.getStatus() == Sound::Playing)
			{
				sf::sleep(sf::seconds(0.1f));
			}
			this->drawScreen = 2; //changing screen to 2...
			cout << "card clicked" << endl;
		}
	}

	//for entering pin password...(in screen 2)
	if (this->drawScreen == 2) {
		this->pinEntered(mouseX, mouseY, drawScreen);
		//pressing ok and moving to screen3 only if pin password is correct...
		if (mouseX >= 797 && mouseX <= 915 && mouseY >= 880 && mouseY <= 940) {
			if (Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (this->authenticate(to_string(this->finalPinEntered))) {
					this->menuSnd.play();
					this->drawScreen = 3;
				}
				else {
					this->errorMsg1.setFont(this->user::font);
					this->errorMsg1.setString("Incorrect Pin");
					this->errorMsg1.setPosition(600, 470);
					//this->errorMsg.setLetterSpacing(2);
					this->errorMsg1.setCharacterSize(25);
					this->errorMsg1.setFillColor(sf::Color::Red);
				}
			}
		}
	}

	//unlocking side buttons to select options...(in screen 3)
	if (this->drawScreen == 3) {
		this->unlockSideButton(mouseX, mouseY, drawScreen);
	}

	//for entering amount for transaction...(in screen 4)
	if (this->drawScreen == 4) {
		this->pinEntered(mouseX, mouseY, drawScreen);
		//pressing ok and moving to screen6 only if total amount is less than 25000 and greater than 0...
		if (this->totalAmount <= 25000 && this->totalAmount > 0) {
			if (mouseX >= 797 && mouseX <= 915 && mouseY >= 880 && mouseY <= 940) {
				if (Mouse::isButtonPressed(sf::Mouse::Left)) {
					if (this->totalAmount <= std::stoi(this->amount)) {
						this->user::updateDbase(to_string(this->totalAmount));
						this->drawScreen = 7;//showing processing plz wait...
						this->menuSnd.play();
						this->cashSnd.play();
					}
					else {
						this->errorMsg2.setFont(this->user::font);
						this->errorMsg2.setString("Not Enough Money.");
						this->errorMsg2.setPosition(570, 470);
						//this->errorMsg.setLetterSpacing(2);
						this->errorMsg2.setCharacterSize(25);
						this->errorMsg2.setFillColor(sf::Color::Red);
					}
				}
			}
		}
		else { //if not then show appropriate message...
			if (mouseX >= 797 && mouseX <= 915 && mouseY >= 880 && mouseY <= 940) {
				if (Mouse::isButtonPressed(sf::Mouse::Left)) {
					this->errorMsg3.setFont(this->user::font);
					this->errorMsg3.setString("Can't do more than Rs.25000 transaction.");
					this->errorMsg3.setPosition(400, 470);
					//this->errorMsg.setLetterSpacing(2);
					this->errorMsg3.setCharacterSize(25);
					this->errorMsg3.setFillColor(sf::Color::Red);
				}
			}
		}
	}

	//pressing ok after seeing current user money...(in screen5)
	if (this->drawScreen == 5) {
		if (mouseX >= 797 && mouseX <= 915 && mouseY >= 880 && mouseY <= 940) {
			if (Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->menuSnd.play();
				//reset everything and go back to screen1 after pressing ok...
				this->showStarCount = 0;
				this->drawScreen = 0;
				this->totalAmount = 0;
			}
		}
	}

	//this is for showing receipt and money...(in screen6)
	if (this->drawScreen == 6) {
		this->giveReceipt = true; //give receipt in this screen only...
		if (this->shouldGiveMoney) {
			this->nowGiveMoney = true; //give money in this screen only...
		}
		//clicking the receipt with mouse...
		if (mouseX >= 1378 && mouseX <= 1675 && mouseY >= 92 && mouseY <= 440) {
			if (Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->userCollectedReceipt = true;
			}
		}
		//clicking the money with mouse...
		if (mouseX >= 1329 && mouseX <= 1745 && mouseY >= 800 && mouseY <= 1010) {
			if (Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->userCollectedMoney = true;
			}
		}
		//this is when user want to withdrawl money...
		if (this->shouldGiveMoney) {
			//if the user has collected both receipt and money then reset every thing go back to screen 1...
			if (this->userCollectedMoney && this->userCollectedReceipt) {
				this->showStarCount = 0;
				this->drawScreen = 0;
				this->totalAmount = 0;
				this->shouldGiveMoney = false;
				this->nowGiveMoney = false;
				this->giveReceipt = false;
				this->userCollectedMoney = false;
				this->userCollectedReceipt = false;
			}
		}
		else {//if user just want to do fund transfer...
			if (this->userCollectedReceipt) {
				//if the user has collected receipt then reset every thing go back to screen 1...
				this->showStarCount = 0;
				this->drawScreen = 0;
				this->totalAmount = 0;
				this->shouldGiveMoney = false;
				this->nowGiveMoney = false;
				this->giveReceipt = false;
				this->userCollectedMoney = false;
				this->userCollectedReceipt = false;
			}
		}
	}

	//waiting until cash processing Sound is finished...(in screen7)
	if (this->drawScreen == 7) {
		//wait until sound finishes...
		bool status = this->cashSnd.getStatus() == Sound::Stopped;
		if (status) {
			this->drawScreen = 6;
		}
	}

	//Asking account number....(in screen8)
	if (this->drawScreen == 8) {
		this->pinEntered(mouseX, mouseY, drawScreen);

		//pressing ok button...
		if (mouseX >= 797 && mouseX <= 915 && mouseY >= 880 && mouseY <= 940) {
			if (Mouse::isButtonPressed(sf::Mouse::Left)) {
				//account number length == 9 then ok.... go to screen4... 
				if (std::to_string(this->ANum).length() == 9) {
					this->menuSnd.play();
					this->drawScreen = 4;	//moving to screen 4 to enter amount...
				}
				else {	//else show error msg...
					this->errorMsg4.setFont(this->user::font);
					this->errorMsg4.setString("Please Enter Correct Account Number.");
					this->errorMsg4.setPosition(400, 470);
					//this->errorMsg.setLetterSpacing(2);
					this->errorMsg4.setCharacterSize(25);
					this->errorMsg4.setFillColor(sf::Color::Red);
				}
			}
		}
	}

	//for cancel button...(in all screens)
	this->cancelPressed(mouseX, mouseY);

}

void screen::drawingScreen(RenderWindow* win)
{
	if (this->drawScreen == 0)
	{
		win->draw(this->screen0);
	}
	else if (this->drawScreen == 1)
	{
		win->draw(this->screen1);
		win->draw(this->card);
	}
	else if (this->drawScreen == 2) {
		win->draw(this->screen2);
		if (this->showStarCount > 0) {
			win->draw(this->pin);
		}
		win->draw(this->errorMsg1);
	}
	else if (this->drawScreen == 3) {
		win->draw(this->screen3);
	}
	else if (this->drawScreen == 4) {
		win->draw(this->screen4);
		if (this->totalAmount > 0) {
			win->draw(this->enteredAmount);
		}
		if (this->totalAmount > std::stoi(this->amount)) {
			win->draw(this->errorMsg2);
		}
		if (this->totalAmount > 25000) {
			win->draw(this->errorMsg3);
		}
	}
	else if (this->drawScreen == 5) {
		win->draw(this->screen5);
		win->draw(this->balance);
	}
	else if (this->drawScreen == 6) {
		win->draw(this->screen6);
		//if user hasn't collected either money or receipt then draw them in screen 6...
		if (!this->userCollectedReceipt && giveReceipt) {
			win->draw(this->receipt);
		}
		if (!this->userCollectedMoney && this->shouldGiveMoney && this->nowGiveMoney) {
			if (totalAmount < 1000) {
				win->draw(this->money500);
			}
			else {
				win->draw(this->money1000);
			}
		}
	}
	else if (this->drawScreen == 7) {
		win->draw(this->screen7);
	}
	else if (this->drawScreen == 8) {
		win->draw(this->screen8);
		if (this->ANum > 0) {
			win->draw(this->enteredANum);
		}
		if (std::to_string(this->ANum).length() != 9) {
			win->draw(this->errorMsg4);
		}
	}
}
