#include<iostream>
#include "Atm.h"
using namespace std;

int main()
{
    //making object of atm...
    Atm atm;

    //Game Loop...
    while (atm.running()) {

        //Update as per events...
        atm.update();

        //Render objects on screen...
        atm.render();
    }

    return 0;
}