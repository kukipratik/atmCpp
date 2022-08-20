#include "user.h"

void user::initVariables()
{
	//loading font...
	if (!this->font.loadFromFile("res/courier_new.ttf")) {
		cout << "Font can't be loaded...";
	}
}

user::user()
{
	this->initVariables();
}

void user::makeBuffer(string userName)
{
	//opening database file to read only...
	ifstream db("res/dbase.txt");	
	if (!db.is_open() ) {
		cout << "Couldn't open dbase.txt file" << endl;
		exit(1);
	}

	//opening buffer file to write...
	ofstream buf("res/buffer.txt");
	if (!buf.is_open()) {
		cout << "Couldn't open buffer.txt file" << endl;
		exit(1);
	}

	string line;

	while (!db.eof())
	{
		getline(db, line);	//reading from db...
		cout << " userName = " << userName<<endl;
		if (line.find(userName) != std::string::npos)
		{//if line contains user name then....
			buf << line;	//writing in db...
			break;
		}
	}
	cout << "line = " << line << endl;

	//closing files...
	db.close();
	buf.close();

	//now user current Amount is stored in amount variable...
	this->showBalance();
}

bool user::authenticate(string pin)
{
	//opening buffer file to read only...
	ifstream buf("res/buffer.txt");
	if (!buf.is_open()) {
		cout << "Couldn't open buffer.txt file" << endl;
		exit(1);
	}

	string line;
	getline(buf, line);

	if (line.find(pin) != std::string::npos) 
	{//if line contains pin then...
		buf.close();
		return true;
	}
	buf.close();
	return false;
}

void user::showBalance()
{
	//opening buffer file to read only...
	ifstream buf("res/buffer.txt");
	if (!buf.is_open()) {
		cout << "Couldn't open buffer.txt file" << endl;
		exit(1);
	}

	buf >> this->amount; //this will give 1st wrd of buffer which is balance...
	
	this->balance.setFont(this->font);
	this->balance.setString(this->amount);
	this->balance.setPosition(610, 329);
	this->balance.setCharacterSize(40);
	this->balance.setFillColor(sf::Color::Green);
	buf.close();
}

void user::updateDbase(string enteredAmount)
{
	//storing dbase words in vector...
	this->storeInVec();

	// now updating database...
	ofstream db3("res/dbase.txt");
	int j = 1;

	//using above vector to write database file again...
	for (int i = 0; i < vec.size(); i++)
	{
		if (i == userAmountMark)
		{
			//only updating amount...
			db3 << this->giveNewBalacne(std::stoi(enteredAmount)) << " ";
		}
		else
		{
			//writing other things as before...
			db3 << vec[i] << " ";
		}

		//this is for changing line...
		if (j == 3)
		{
			db3 << '\n';
			j = 1;
			continue;
		}
		j++;
	}
	db3.close();
}

string user::giveNewBalacne(int enteredAmout)
{
	int newBalance = 0;
	int currentBalance = std::stoi(this->amount);
	cout << "cB = " << currentBalance << endl;

	if (currentBalance >= enteredAmout) {
		newBalance = currentBalance - enteredAmout;
	}

	return std::to_string(newBalance);
}

void user::storeInVec()
{
	string wrd;
	int i = 0;
	// opening database file in reading mode...
	ifstream db2("res/dbase.txt");

	// reading from databaase file and storing in vector...
	while (db2 >> wrd)
	{
		this->vec.push_back(wrd); // stored them in vector...
	}
	db2.close();
}

