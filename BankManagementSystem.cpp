/*
 * Bank Management System
 * Author: Belal Esmail
 *
 * An object-oriented C++ console application for managing clients,
 * transactions, users, permissions, transfers, and currency exchange.
 */

#include <iostream>
#include "clsLoginScreen.h"

using namespace std;


int main()
{
	/*clsMainScreen::ShowMainMenue();*/

	while(true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}

	system("pause>0");
}
